#!/bin/sh


if [ -z "$1" ]; then
    echo "Error: Tell me a home directory!"
fi

TARGET=$1

cat >config.h <<EOF
#pragma once
#define FK_HOME_DIR "${TARGET}"
EOF