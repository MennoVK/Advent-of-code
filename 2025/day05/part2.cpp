#include <iostream>
#include <fstream> 
#include <sstream> 
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ifstream infile("input.txt");
    if (!infile) return 1;

    string line;
    long long num1, num2;
    char dash;

    vector<vector<long long>> ranges;

    set<long long> set;

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
            for (int i = 0; i < ranges.size(); i++){
                set.insert(ranges[i][0]);
                set.insert(ranges[i][1]);
            }
            break;
        }
    }

    for (int i = 0; i < set.size(); i++){
        cout << i << endl;
    }

    cout << *--set.end() - *set.begin();


    return 0;
}