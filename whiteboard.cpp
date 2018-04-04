/*
 * Copyright (C) 2018 Microchip Technology Inc.  All rights reserved.
 * Joshua Henderson <joshua.henderson@microchip.com>
 */
#include <QMouseEvent>
#include <QPainter>
#include <QPen>

#include "whiteboard.h"

WhiteBoard::WhiteBoard(QWidget* parent)
    : QWidget(parent),
      m_drawing(false),
      m_modified(false),
      m_penWidth(3),
      m_penColor(Qt::blue)
{
    setAttribute(Qt::WA_StaticContents);
}

void WhiteBoard::setPenColor(const QColor& newColor)
{
    m_penColor = newColor;
}

void WhiteBoard::clearImage()
{
    m_image.fill(Qt::white);
    m_modified = true;
    update();
}

void WhiteBoard::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_lastPoint = event->pos();
        m_drawing = true;
    }
}

void WhiteBoard::mouseMoveEvent(QMouseEvent* event)
{
    if ((event->buttons() & Qt::LeftButton) && m_drawing)
        drawLineTo(event->pos());
}

void WhiteBoard::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && m_drawing)
    {
        drawLineTo(event->pos());
        m_drawing = false;
    }
}

void WhiteBoard::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, m_image, dirtyRect);
}

void WhiteBoard::resizeEvent(QResizeEvent* event)
{
    if (width() > m_image.width() || height() > m_image.height())
    {
        int newWidth = qMax(width() + 128, m_image.width());
        int newHeight = qMax(height() + 128, m_image.height());
        resizeImage(&m_image, QSize(newWidth, newHeight));
        update();
    }

    QWidget::resizeEvent(event);
}

void WhiteBoard::resizeImage(QImage* image, const QSize& newSize)
{
    if (image->size() == newSize)
        return;

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255, 255, 255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

void WhiteBoard::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&m_image);
    painter.setPen(QPen(m_penColor, m_penWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter.drawLine(m_lastPoint, endPoint);
    m_modified = true;

    int rad = (m_penWidth / 2) + 2;
    update(QRect(m_lastPoint, endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
    m_lastPoint = endPoint;
}
