# dependencies
```bash
sudo pacman -S lld
```

# create image
```bash
qemu-img create -f raw disk.img 200M
mkfs.fat -s 2 -f 2 -R 32 -F 32 disk.img
sudo mount -o loop disk.img /mnt
sudo mkdir -p /mnt/EFI/BOOT
sudo cp hello.efi /mnt/EFI/BOOT/BOOTX64.EFI
sudo umount /mnt
```

# run qemu with image
```bash
qemu-system-x86_64 -bios /usr/share/ovmf/x64/OVMF.fd -drive format=raw,file=disk.img
```