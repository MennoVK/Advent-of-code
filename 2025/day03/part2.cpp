#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

int main()
{
    ifstream infile("input.txt");
    if (!infile) return 1;

    string line;

    long long count = 0;

    while (getline(infile, line)) {
        string strLine;

        for (int i = 0; i < line.length() - (line.length() - 12 ); i++){
            int largestNum = 0;
            int largestNumIdx = 0;

            for (int j = i; j < line.length() - 12 + 1 + i; j++){
                if (line[j] - '0' > largestNum || line[j] == '0'){
                    largestNum = line[j] - '0';
                    largestNumIdx = j;
                }
            }
            strLine += to_string(largestNum);
            line[largestNumIdx] = '0';
            largestNum = 0;

        }
        count += stoll(strLine);
    }

    cout << count << endl;

    return 0;
}
