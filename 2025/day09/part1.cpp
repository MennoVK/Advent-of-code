#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Point2D { 
    long long x, y;
};

long long area(Point2D p1, Point2D p2);

int main()
{
    ifstream infile("input.txt");
    if (!infile) return 1;

    string line;

    vector <Point2D> pts;

    while (getline(infile, line)){
        stringstream ss(line);

        Point2D p;
        char c1, c2;
        ss >> p.x >> c1 >> p.y;
        pts.push_back(p);
    }

    long long largestArea = 0;

    for (long long i = 0; i < pts.size(); i++){
        for (long long j = 0; j < pts.size(); j++){
            if(area(pts[i], pts[j]) > largestArea){
                largestArea = area(pts[i], pts[j]);
            }
        }
    }

    cout << largestArea << endl;

    return 0;
}

long long area(Point2D p1, Point2D p2){
    return abs(p2.x - p1.x + 1) * abs(p2.y - p1.y + 1);
}