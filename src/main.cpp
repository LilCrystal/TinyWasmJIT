#include <iostream>
#include <fstream>
#include <vector>
#include "TestTool.h"

int reader()
{
    // 替换为你要读取的文件的绝对路径
    const std::string filePath = "D:\\Workspace\\Project\\Tiny-Wasm-Compiler-Learn\\Chapter01\\test\\add.wat";

    // 打开文件以二进制模式读取
    std::ifstream file(filePath, std::ios::binary);
    if (!file)
    {
        std::cerr << "无法打开文件: " << filePath << std::endl;
        return 1;
    }

    // 读取文件内容到vector中
    const std::vector<int> byteCode((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // 关闭文件
    file.close();

    // 逐个打印字节码
    for (const int byte : byteCode)
    {
        std::cout << std::hex << static_cast<int>(byte) << " ";
    }
    std::cout << std::endl;

    return 0;
}

int main()
{
    try
    {
        {/* code */}
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}