#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool compareVectors(vector<char> vec1, vector<char> vec2);
int combineNested(const vector<vector<int>>& items, vector<int>& current, int start, int r, vector<char>* result, vector<char> input);
char toggle(char ch);

int main()
{
    ifstream infile("input.txt");
    if (!infile) return 1;

    string line;

    int globalCount = 0;
    
    while (getline(infile, line)){
        vector<char> input;
        vector<vector<int>> buttons;
        
        int part = 0;

        for (int i = 1; i < line.size(); i++){
            if(part == 0){
                if(line[i] == ']'){
                    part = 1;
                }
                else{
                    input.push_back(line[i]);
                }
            }
            else if (part == 1){
                if(line[i + 1] == '{'){
                    part = 2;
                }
                else{
                    vector<int> button;
                    int idx = 0;
    
                    while(true){
                        if(line[i + idx] != '(' && line[i + idx] != ',' && line[i + idx] != ' '){
                            button.push_back(line[i + idx] - '0');
                        }
                        idx++;
                        if(line[i + idx] == ')'){
                            buttons.push_back(button);
                            i += idx;
                            button = {};
                            break;
                        }
                    }
                }
            }
        }

        vector<int> current;
        
        for (int r = 1; r <= buttons.size(); ++r) {
            vector<char> result;
            for (int i = 0; i < input.size(); i++){
                result.push_back('.');
            }

            int operations = combineNested(buttons, current, 0, r, &result, input);
            if (operations > 0) {
                globalCount += operations;
                break;
            }
        }
    }

    cout << globalCount << endl;

    return 0;
}

bool compareVectors(vector<char> vec1, vector<char> vec2) {
    return vec1 == vec2;
}

void updateResult(vector<int> button, vector<char>* result, vector<char> input){
    for (int i = 0; i < button.size(); i++){
        (*result)[button[i]] = toggle((*result)[button[i]]);
    }
}

int combineNested(const vector<vector<int>>& items, vector<int>& current, int start, int r, vector<char>* result, vector<char> input) {
    int operations = 0;

    if (current.size() == r) {
        for (int idx : current) {
            operations++;
        }
        
        vector<char> temp = *result;
        for (int idx : current) {
            updateResult(items[idx], &temp, input);
            if(compareVectors(input, temp)){
                return operations;
            };
        }
    }

    for (int i = start; i < items.size(); ++i) {
        current.push_back(i);
        int ops = combineNested(items, current, i + 1, r, result, input);
        if (ops > 0) return operations + ops;
        current.pop_back();
    }
    return 0;
}

char toggle(char ch){
    if(ch == '.'){
        return '#';
    }
    else {
        return '.';
    } 
}