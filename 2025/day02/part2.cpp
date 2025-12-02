#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

long long calculateInvalidIDSumForRange(long long num1, long long num2);
bool hasRepeatedPattern(const string s);

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
    long long invalidIdSum = 0;

    for (num1; num1 < num2 + 1; num1++){
        string numStr = to_string(num1);

        if(hasRepeatedPattern(numStr)){
            invalidIdSum += num1;
        }
    }

    return invalidIdSum;
}

bool hasRepeatedPattern(string s){
    string doubleInput = s + s;

    for (int i = 1; i < doubleInput.length() - s.length(); i++){
        if(doubleInput.substr(i, s.length()) == s){
            return true;
        };
    }

    return false;
}