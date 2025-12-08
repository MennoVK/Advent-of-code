#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

struct Point3D { 
    int x, y, z; 

    bool operator==(const Point3D& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator<(const Point3D& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }
};
struct distanceBetween { Point3D p1,p2; double distance;};
bool compareByDistance(const distanceBetween &a, const distanceBetween &b);

double calculateDistance(Point3D, Point3D);

void logTest(const std::vector<std::set<Point3D>>& test) {
    std::cout << "test size: " << test.size() << "\n";

    for (size_t i = 0; i < test.size(); i++) {
        std::cout << "  [" << i << "] length: " << test[i].size() << " -> [";

        size_t count = 0;
        for (const auto& p : test[i]) {
            cout << "(" << p.x << "," << p.y << "," << p.z << ")";
            if (++count < test[i].size()) std::cout << ", ";
        }

        std::cout << "]\n";
    }
}


int main()
{
    ifstream infile("input.txt");
    if (!infile) return 1;

    string line;

    vector <Point3D> pts;

    while (getline(infile, line)){
        stringstream ss(line);

        Point3D p;
        char c1, c2;
        ss >> p.x >> c1 >> p.y >> c2 >> p.z;
        pts.push_back(p);
    }

    vector<distanceBetween> list;

    for (int i = 0; i < pts.size(); i++){
        for (int j = i + 1; j < pts.size(); j++){
            cout << "distance between ";
            cout << pts[i].x << " " << pts[i].y << " " << pts[i].z;
            cout << " and ";
            cout << pts[j].x << " " << pts[j].y << " " << pts[j].z;
            cout << " is ";
            cout << calculateDistance(pts[j], pts[i]) << endl;
            list.push_back({pts[i], pts[j], calculateDistance(pts[j], pts[i])});
        }
    }

    sort(list.begin(), list.end(), compareByDistance);

    vector<set<Point3D>> test;
    
    // create base list which contains lists of Point3D
    // check if base list contains list which contains Point3D that is about to be inserted.
    // if Point3D exists, append other value to list
    // otherwise create new list with 2 points with smallest distance
    // cout << list.size() << endl;

    for (int i = 0; i < list.size(); i++){


        //loop over all distanceBetween entries (189)
        bool addedA = false;
        bool addedB = false;
        

        for (int j = 0; j < test.size(); j++){
            // loop through main list
            for (const auto& p : test[j]) {
                if (p == list[i].p1) {
                    test[j].insert(list[i].p2);
                    // cout << "hit" << endl;

                    // cout << list[i].p2.x << "," << list[i].p2.y << "," << list[i].p2.z << endl;
                    addedB = true;
                    break;
                }
                if (p == list[i].p2) {
                    test[j].insert(list[i].p1);
                    // cout << "hit" << endl;
                    // cout << list[i].p1.x << "," << list[i].p1.y << "," << list[i].p1.z << endl;
                    addedA = true;
                    break;
                }
            }
        }

        if(!addedA && !addedB){
            test.push_back({list[i].p1, list[i].p2});
            // push vector of 2 points to main vector
        }

        logTest(test);

        if (i == 10){
            break;
        }
    }


    return 0;
}

double calculateDistance (Point3D pointA, Point3D pointB){
    return sqrt(
        pow((pointB.x - pointA.x), 2) + 
        pow((pointB.y - pointA.y), 2) + 
        pow((pointB.z - pointA.z), 2)
    );
}

bool compareByDistance(const distanceBetween &a, const distanceBetween &b)
{
    return a.distance < b.distance;
}