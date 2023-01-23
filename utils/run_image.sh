#!/bin/bash
set -euo pipefail

if [ $# -ne 1 ]; then
    echo "Usage: $0 <image file>"
fi
image="$1"

qemu-system-x86_64 \
-bios /usr/share/ovmf/x64/OVMF.fd \
-monitor stdio \
-drive format=raw,file="$image"