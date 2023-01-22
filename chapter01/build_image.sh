#!/bin/bash
set -euo pipefail

if [ $# -ne 1 ]; then
    echo "Usage: $0 <efi file>"
fi

EFI_FILE="$1"

qemu-img create -f raw disk.img 200M
mkfs.fat -s 2 -f 2 -R 32 -F 32 disk.img
sudo mount -o loop disk.img /mnt
sudo mkdir -p /mnt/EFI/BOOT
sudo cp "$1" /mnt/EFI/BOOT/BOOTX64.EFI
sudo umount /mnt