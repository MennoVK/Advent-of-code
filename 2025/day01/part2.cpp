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

        int fullRotations = (amount / 100);
        int restRotation = (amount % 100);

        bool dialWasZero = dial == 0;

        if(direction == 'L'){
            password += fullRotations;
            dial -= restRotation;
        }
        else{
            password += fullRotations;
            dial += restRotation;
        }

        if (dialWasZero && dial < 0){
            dial += 100;
        }
        else{
            if (dial == 0){
                password++;
            }
            if(dial < 0){
                dial += 100;
                password++;
            }
            if(dial >= 100){
                dial -= 100;
                password++;
            }
        }

    }
    cout << password << endl;

    return 0;
}