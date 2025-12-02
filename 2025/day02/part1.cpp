#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

long long calculateInvalidIDSumForRange(long long num1, long long num2);

int main()
{
    ifstream infile("input.txt");
    if (!infile) return 1;

    char ch;
    int idx = 0;

    long long num1;
    long long num2;

    int currentIdx = 0;

    long long globalInvalidIdSum = 0;

    string input;

    getline(infile, input);

    for (int i = 0; i < input.length(); i++){
        if(input[i] == '-'){
            num1 = stoll(input.substr(currentIdx, i));
            currentIdx = i + 1;
        }
        else if(input[i] == ',' || !input[i + 1]){
            num2 = stoll(input.substr(currentIdx, i));
            currentIdx = i + 1;
            
            globalInvalidIdSum += calculateInvalidIDSumForRange(num1, num2);
        }
    }
    
    cout << globalInvalidIdSum << endl;

    return 0;
}

long long calculateInvalidIDSumForRange(long long num1, long long num2){
    string firstHalf;
    string secondHalf;

    long long invalidIdSum = 0;

    for (num1; num1 < num2 + 1; num1++){
        string numStr = to_string(num1);
        firstHalf = numStr.substr(0, numStr.length() / 2);
        secondHalf = numStr.substr(numStr.length() / 2, numStr.length());

        if(firstHalf == secondHalf){
            invalidIdSum += num1;
        }
    }

    return invalidIdSum;
}