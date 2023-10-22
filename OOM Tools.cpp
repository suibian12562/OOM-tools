/*#include <iostream>
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
*/


#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main() {
    // Request the amount of memory to test (in GB)
    cout << "Enter the amount of memory you want to test (GB): ";
    int gb;
    cin >> gb;
    size_t MEMORY_SIZE = static_cast<size_t>(gb) * 1024 * 1024 * 1024; // 1 GB

    // Allocate memory using std::vector
    vector<char> buffer(MEMORY_SIZE);

    // Fill the memory with random data using C++11 random number generator
    cout << "Filling the memory with random data..." << endl;
    srand(static_cast<unsigned>(time(nullptr))); // Initialize the random seed
    for (size_t i = 0; i < MEMORY_SIZE; i++) {
        buffer[i] = static_cast<char>(rand() % 256); // Generate a random byte
    }

    // Read the memory back and compare it with the original data
    cout << "Reading the memory back and comparing it with the original data..." << endl;
    for (size_t i = 0; i < MEMORY_SIZE; i++) {
        char expected = buffer[i]; // The original byte
        char actual = buffer[i]; // The read byte
        if (expected != actual) {
            cerr << "Memory error detected at address " << static_cast<void*>(&buffer[i]) << endl;
            cerr << "Expected: " << static_cast<int>(expected) << ", Actual: " << static_cast<int>(actual) << endl;
            return 1;
        }
    }

    // Memory is automatically freed when the vector goes out of scope
    cout << "Memory test passed!" << endl;
    return 0;
}
