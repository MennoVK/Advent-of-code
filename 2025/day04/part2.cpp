#include <iostream>
#include <fstream> 
#include <string>
#include <vector>

using namespace std;

void printGrid(vector<vector<char>> grid);
int countSurroundingRolls(int x, int y, vector<vector<char>> grid);

int main()
{
    ifstream infile("input.txt");
    if (!infile) return 1;

    string line;
    vector<string> lines;
    vector<vector<char>> grid;

    while (getline(infile, line))
        lines.push_back(line);

    int globalCount = 0;

    int n = lines.size();
    int m = lines[0].size();

    grid.resize(n + 2, vector<char>(m + 2, '.'));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            grid[i + 1][j + 1] = lines[i][j];

    bool moreRolls = true;

    while(moreRolls){
        int traverseCount = 0;

        for (int i = 0; i < grid.size() ; i++){
            for (int j = 0; j < grid.size() ; j++){
                if(grid[i][j] == '@'){
                    if(countSurroundingRolls(i, j, grid)){
                        grid[i][j] = '.';
                        traverseCount++;
                    };
                    // printGrid(grid);
                }
            }
        }
        if(traverseCount == 0){
            moreRolls = false;
        }
        globalCount += traverseCount;
        traverseCount = 0;
    }

    cout << globalCount << endl;

    return 0;
}

void printGrid(vector<vector<char>> grid){
    for (const auto& i : grid) {
        for (char j : i)
            cout << j << " ";
        cout << endl;
    }

    return;
}

int countSurroundingRolls(int x, int y, vector<vector<char>> grid){
    int count = 0;

    if (grid[x][y] == '@'){
        count--;
    }

    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3 ; j++){
            if(grid[x-1+i][y-1+j] == '@'){
                count++;
            }
        }
    }

    if(count < 4){
        return 1;
    }
    else{
        return 0;
    }
}