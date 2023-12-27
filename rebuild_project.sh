#!/bin/bash

BIN_DIR=bin

echo "Rebuild project..."

if [ -d "${BIN_DIR}" ]; then
    echo "Removing ${BIN_DIR}..."
    rm -rf ${BIN_DIR}
else
    echo "${BIN_DIR} does not exist."
fi

echo "Running build_project.sh"
source build_project.sh
