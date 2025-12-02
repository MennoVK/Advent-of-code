#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

int main()
{
    ifstream infile("input.txt");
    if (!infile) return 1;

    int dial = 50;

    string line;
    char direction; 
    int amount;

    int password = 0;

    while (getline(infile, line)) {
        direction = line[0];
        amount = stoi(line.substr(1));
        
        if(direction == 'L'){
            dial -= (amount % 100);
        }
        else{
            dial += (amount % 100);
        }
        
        if (dial < 0){
            dial = 100 + dial;
        }
        if (dial >= 100){
            dial -= 100;
        }
        
        if (dial == 0){
            password++;
        }
    }
    cout << password << endl;

    return 0;
}
