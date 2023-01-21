//
// Created by biosvos on 1/21/23.
//

typedef unsigned short CHAR;
typedef unsigned long long EFI_STATUS;
typedef void *EFI_HANDLE;


struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef EFI_STATUS (*EFI_TEXT_FUNC)(struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *this, CHAR

*string);

struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    void *dummy;
    EFI_TEXT_FUNC OutputStringFunction;
};

struct EFI_SYSTEM_TABLE {
    char dummy[52];
    EFI_HANDLE ConsoleOutputHandle;
    struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *protocol;
};

EFI_STATUS EfiMain(EFI_HANDLE handle, struct EFI_SYSTEM_TABLE *table) {
    table->protocol->OutputStringFunction(table->protocol, L"hello, world!\n");
    while (1) {};
    return 0;
}