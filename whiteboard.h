/*
 * Copyright (C) 2018 Microchip Technology Inc.  All rights reserved.
 * Joshua Henderson <joshua.henderson@microchip.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef WHITEBOARD_H
#define WHITEBOARD_H

#include <QColor>
#include <QImage>
#include <QPoint>
#include <QWidget>

class WhiteBoard : public QWidget
{
    Q_OBJECT

public:
    explicit WhiteBoard(QWidget* parent = 0);
    void setPenColor(const QColor& newColor);

public slots:
    void clearImage();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private:
    void drawLineTo(const QPoint& endPoint);
    void resizeImage(QImage* image, const QSize& newSize);

    bool m_drawing;
    bool m_modified;
    int m_penWidth;
    QColor m_penColor;
    QImage m_image;
    QPoint m_lastPoint;
};

#endif // WHITEBOARD_H
