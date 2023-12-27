#!/bin/bash

BIN_DIR=bin

echo "Running build script..."

if [ -z "${VCPKG_DIR}" ]; then
    echo "VCPKG_DIR is not set, please download vcpkg and set VCPKG_DIR to the directory where vcpkg is located."
    exit 1
else
    echo "VCPKG_DIR is found at ${VCPKG_DIR}"
fi

if ! [ -x "$(command -v cmake)" ]; then
    echo "cmake is not installed or is not in PATH; Please install cmake and add it to PATH."
    exit 1
fi

echo "Choose a build type: (d)ebug or (r)elease"
read mode

case $mode in
    d|D)
        BUILD_MODE=Debug
        ;;
    r|R)
        BUILD_MODE=Release
        ;;
    *)
        echo "Invalid build mode selected, ceasing build"
        exit 1
esac

echo "Building in ${BUILD_MODE} mode..."

BUILD_COMMAND="cmake -S . -B ${BIN_DIR} --log-level=VERBOSE -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=${BUILD_MODE}"

echo "Running build command: ${BUILD_COMMAND}"
${BUILD_COMMAND}

if [ $? -ne 0 ]; then
    echo "Build failed, exiting..."
    exit 1
fi

echo "Setting up symbolic link for compile_commands.json..."
ln -s ${BIN_DIR}/compile_commands.json compile_commands.json

echo "!! Cmake Build succeeded !!"
echo "Switching to ${BIN_DIR} and running make..."

cd ${BIN_DIR}
make

if [ $? -ne 0 ]; then
    echo "Make failed to run, exiting..."
    exit 1
fi

echo "!! Make succeeded !!"
exit 0
