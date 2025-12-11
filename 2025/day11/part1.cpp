#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

bool findOut (unordered_map<string, vector<string>> map, string startStr, int &count);

int main()
{
    ifstream infile("input.txt");
    if (!infile) return 1;

    string line;

    unordered_map<string, vector<string>> map;

    while (getline(infile, line)){
        stringstream ss(line);

        string word;
        string key;
        vector<string> values;
        int idx = 0;

        while (ss >> word) {
            if(idx == 0){
                key = word.substr(0 , word.length() - 1);
            }
            else{
                values.push_back(word);
            }
            idx++;      
        }

        map.insert({key, values});
    }

    int globalCount = 0;

    findOut(map, "you", globalCount);

    cout << globalCount << endl;

    return 0;
}

bool findOut (unordered_map<string, vector<string>> map, string startStr, int &count) {
    auto it = map.find(startStr);
    
    for (int i = 0; i < it->second.size(); i++){
        if (it == map.end() || it->second[i] == "you") {
            return false;
        }
        else{
            if(it->second[i] == "out"){
                count++;
                return true;
            }
            findOut(map, it->second[i], count);
        }
    }
    return false;
}