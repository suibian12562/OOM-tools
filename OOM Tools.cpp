#include <iostream>
#include<Windows.h>
const char  program_ver[] = "beta_0.0.3";
int main()
{
    std::cout << "程序版本" << program_ver<<std::endl;
start:
    std::cout << "本程序为内存测试程序"<<std::endl;
    std::cout << "输入你要写入的内存大小 单位(mb)" << std::endl;
    int n;
    std::cin >> n;
    int old_n = n;
    n = (n * static_cast<double>(1048576)) / 4 / 5 / 0.81;
    for (; n != 0; n--)
    {
        int * mkill = new int;
        ////std::cout << n<<std::endl;
    }
    std::cout << "本次约写入" << old_n << "MB内存(不准确!!)\n\n\a" << std::endl;
    Sleep(1000);
    goto start;

}
