all: hello.efi

hello.efi: hello.c
	clang -target x86_64-pc-win32-coff -o hello.o -c hello.c
	lld-link /subsystem:efi_application /entry:EfiMain /out:hello.efi hello.o