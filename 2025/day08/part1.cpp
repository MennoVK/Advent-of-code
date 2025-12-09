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
void mergeSets(std::vector<std::set<Point3D>>& v, size_t i, size_t j);
void eraseSet(std::vector<std::set<Point3D>>& v, size_t index);

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
            list.push_back({pts[i], pts[j], calculateDistance(pts[j], pts[i])});
        }
    }

    sort(list.begin(), list.end(), compareByDistance);

    vector<set<Point3D>> test;
    
    for (int i = 0; i < list.size(); i++){
        bool addedA = false;
        bool addedB = false;
        int index;

        for (int j = 0; j < test.size(); j++){
            for (const auto& p : test[j]) {
                if (p == list[i].p1) {
                    if(addedA){
                        mergeSets(test, j, index);
                        eraseSet(test, index);
                    }
                    else{
                        test[j].insert(list[i].p2);
                        addedB = true;
                        index = j;
                    }
                    break;
                }
                if (p == list[i].p2) {
                    if(addedB){
                        mergeSets(test, j, index);
                        eraseSet(test, index);
                    }else{
                        test[j].insert(list[i].p1);
                        addedA = true;
                        index = j;
                    }
                    break;
                }
            }
        }

        if(!addedA && !addedB){
            test.push_back({list[i].p1, list[i].p2});
        }

        if (i == 999){
            break;
        }
    }
    
    int globalCount = 1;

    vector<int> largestNumbers; 

    for (int i = 0; i < test.size(); i++){
        largestNumbers.push_back(test[i].size());
    }

    sort(largestNumbers.begin(), largestNumbers.end(), std::greater<int>());

    cout << globalCount * largestNumbers[0] * largestNumbers[1] * largestNumbers[2] << endl;

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

void mergeSets(std::vector<std::set<Point3D>>& v, size_t i, size_t j) {
    v[i].insert(v[j].begin(), v[j].end());
}

void eraseSet(std::vector<std::set<Point3D>>& v, size_t index) {
    v.erase(v.begin() + index);
}