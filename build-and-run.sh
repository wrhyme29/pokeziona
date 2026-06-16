#!/usr/bin/env bash

export ROM_NAME="${ROM_NAME:=pokeziona.gba}"
export ROM_DEPLOYMENT_FOLDER="${ROM_DEPLOYMENT_FOLDER:=/mnt/d/Games/GameBoy/poke-dev}"
export GBA_EMULATOR="${GBA_EMULATOR:=/mnt/d/Games/GameBoy/VisualBoyAdvance.exe}"
export WINDOWS_ROM_DEPLOYMENT_PATH=$(wslpath -m "${ROM_DEPLOYMENT_FOLDER}")

make

if [ $? -eq 0 ]; then 
  cp -v "${ROM_NAME}" "${ROM_DEPLOYMENT_FOLDER}/${ROM_NAME}"
  echo -e "${GBA_EMULATOR} '${WINDOWS_ROM_DEPLOYMENT_PATH}/${ROM_NAME}'"
  ${GBA_EMULATOR} "${WINDOWS_ROM_DEPLOYMENT_PATH}/${ROM_NAME}"
fi
