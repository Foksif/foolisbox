cmake_minimum_required(VERSION 3.10)
project(MinimalCoreutils C ASM_NASM)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -Wall -Wextra -ffreestanding -nostdlib -fno-stack-protector -fno-pie -no-pie")
set(CMAKE_ASM_NASM_FLAGS "${CMAKE_ASM_NASM_FLAGS} -f elf64")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostdlib -no-pie -static")

file(GLOB_RECURSE SOURCES 
    "src/*.c"
    "src/*.asm"
)
add_executable(foolisbox ${SOURCES})

set_target_properties(foolisbox PROPERTIES LINK_FLAGS "-nostdlib -e _start")
