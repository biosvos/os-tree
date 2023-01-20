# hello world

## create image
```bash
qemu-img create -f raw disk.img 200M
mkfs.fat -s 2 -f 2 -R 32 -F 32 disk.img
sudo mount -o loop disk.img /mnt
sudo cp -r EFI/ /mnt/
sudo umount /mnt
```

## run qemu with image
```bash
qemu-system-x86_64 -bios /usr/share/ovmf/x64/OVMF.fd -drive format=raw,file=disk.img
```
> 현재 왜 인지는 모르겠으나, 이상한 bdsdxe failed to load boot 에러가 발생한다. hello world 자체는 잘 뜸