#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <vector>

using namespace std;

void printGrid(vector<vector<int>> grid);
void printOperators(vector<char> operators);

int main()
{
    ifstream infile("input.txt");
    if (!infile) return 1;

    string line;
    vector<vector<int>> grid;
    vector<char> operators;
    
    while (getline(infile, line)){
        vector<int> numbers;
        stringstream lineStream(line);

        int value;
        char _operator;

        if(line[0] != '*' && line[0] != '+'){
            while(lineStream >> value)
            {
                numbers.push_back(value);
            }
            grid.push_back(numbers);
        }
        else{
            while(lineStream >> _operator)
            {
                operators.push_back(_operator);
            }
        }
        
    }

    printGrid(grid);
    printOperators(operators);
    // cout << grid.size() << endl;
    // cout << grid[0].size() << endl;

    long long globalCount = 0;

    for (int j = 0; j < grid[0].size(); j++){
        long long value = 0;

        for (int i = 0; i < grid.size(); i++){
            if(operators[j] == '*'){
                if(i == 0){
                    value++;
                }
                value *= grid[i][j];
            }
            else{
                value += grid[i][j];
            }

            // cout << grid[i][j];
            // cout << operators[j];
        }
        globalCount += value;
        cout << value << endl;
    }

    cout << globalCount << endl;

    return 0;
}

void printGrid(vector<vector<int>> grid){
    for (const auto& i : grid) {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }

    return;
}

void printOperators(vector<char> operators){
    for (const auto& i : operators) {
        cout << i << " ";
    }
    cout << endl;

    return;
}
