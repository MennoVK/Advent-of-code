#include <iostream>
#include <fstream> 
#include <sstream> 
#include <string>
#include <vector>

using namespace std;

bool inRange (long long start, long long end, long long number);

int main()
{
    ifstream infile("input.txt");
    if (!infile) return 1;

    string line;
    long long num1, num2;
    char dash;
    long long id;
    int globalCount = 0;

    vector<vector<long long>> ranges;

    bool rangesComplete = false;

    while (getline(infile, line)){
        stringstream ss(line);

        if (!rangesComplete){
            if (line == ""){
                rangesComplete = true;
                continue;
            }
    
            ss >> num1 >> dash >> num2;
            ranges.push_back({num1, num2});
        }
        else{
            ss >> id;

            for (int i = 0; i < ranges.size(); i++){
                if(inRange(ranges[i][0], ranges[i][1], id)){
                    globalCount++;
                    break;
                }
            }
        }
    }

    cout << globalCount << endl;

    return 0;
}

bool inRange (long long start, long long end, long long number) {
    return number >= start && number <= end;
}