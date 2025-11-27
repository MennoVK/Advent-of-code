#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

int main()
{
    std::ifstream infile("input.txt");

    int a, b;

    while (infile >> a >> b)
    {
        std::cout << a << " " << b << std::endl;
    }

    infile.close(); 
    return 0;
}
