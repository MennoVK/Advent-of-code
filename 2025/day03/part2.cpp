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

    long long count = 0;

    while (getline(infile, line)) {
        string strNum = "";

        
        for (int i = 12; i > 1; i--){
            cout << strNum << endl;
            int largestNum = 0;
            int largestNumIdx;

            for (int j = 0; j < line.length(); j++){
                if(j < line.length() - i){
                    if (line[j] - '0' > largestNum){
                        largestNum = line[j] - '0';
                        largestNumIdx = j;
                    }
                }
            }
            strNum += to_string(largestNum);

            line = line.erase(0, largestNumIdx + 1);

            if( largestNumIdx == 0){
            }
            else{
                i -= largestNumIdx - 1;
            }
        }


        strNum += line.substr(line.length() - (12 - strNum.length()));
        
        cout << strNum << endl;

        count += stoll(strNum);
    }
    cout << count << endl;

    return 0;
}
