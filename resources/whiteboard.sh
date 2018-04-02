#!/bin/sh

eval "$DEMO_LEAVE"

cd "$(dirname "$0")/"
./whiteboard $1 2>/dev/null

eval "$DEMO_ENTER"
