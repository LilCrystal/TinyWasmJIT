#include "executor.h"

namespace executor
{
    // 定义 ARM64 机器码，实现两个 32 位整数的加法
    // 汇编代码：add w0, w1, w2; ret
    // 对应的机器码（小端序）
    const std::array<unsigned char, 8> machineCode = {
        0x00, 0x00, 0x01, 0x11, // add w0, w1, w2
        0xC0, 0x03, 0x5F, 0xD6  // ret
    };

    // 定义函数指针类型
    using AddFunction = int (*)(int, int);

    int add_func()
    {
        // // 计算机器码的大小
        // const size_t codeSize = machineCode.size();

        // // 使用 mmap 分配可执行内存
        // // NOLINTNEXTLINE(misc-const-correctness)
        // void *codeMemory = mmap(nullptr, codeSize, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        // if (codeMemory == MAP_FAILED)
        // {
        //     std::cerr << "mmap failed: " << errno << std::endl;
        //     return 1;
        // }

        // // 将机器码复制到分配的内存中
        // memcpy(codeMemory, machineCode.data(), codeSize);

        // // 将内存地址转换为函数指针
        // // NOLINTNEXTLINE(cppcoreguidelines-pro-type-reinterpret-cast)
        // const AddFunction add = reinterpret_cast<AddFunction>(codeMemory);

        // // 调用函数进行加法运算
        // const int a = 10;
        // const int b = 20;
        // const int result = add(a, b);

        // // 输出结果
        // std::cout << "Result of " << a << " + " << b << " = " << result << std::endl;

        // // 释放内存
        // if (munmap(codeMemory, codeSize) == -1)
        // {
        //     std::cerr << "munmap failed: " << errno << std::endl;
        //     return 1;
        // }

        return 0;
    }
}