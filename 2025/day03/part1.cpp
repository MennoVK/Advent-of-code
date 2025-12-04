#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

long long calculateInvalidIDSumForRange(long long num1, long long num2);

int main()
{
    ifstream infile("input.txt");
    if (!infile) return 1;

    string line;

    int num1 = 0;
    int num2 = 0;
    int count = 0;

    while (getline(infile, line)) {
        for (int i = 0; i < line.length(); i++){
            int num = line[i] - '0';

            if(num > num1 && i != line.length() -1){
                num1 = num;
                num2 = 0;
            }
            else{
                if (num > num2){
                    num2 = num;
                }
            }
        }
        count += stoi(to_string(num1) + to_string(num2));
        num1 = 0;
        num2 = 0;
    }

    cout << count << endl;

    return 0;
}
