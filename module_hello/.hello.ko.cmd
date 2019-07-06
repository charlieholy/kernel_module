cmd_/opt/module/hello.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o /opt/module/hello.ko /opt/module/hello.o /opt/module/hello.mod.o
