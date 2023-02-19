#include <iostream>
#include "src/include/Server.h"
#include <vector>
#include <iterator>
#include <functional>
#include <random>

using namespace std;
struct TestCase {
    string task;
    vector<int> digits;
};

vector<int> getListOfNumbersRandom(int n, int start, int end) {
    random_device RandomNumberGenerator;
    mt19937 mersenne_engine{RandomNumberGenerator()};
    uniform_int_distribution<int> dist{start, end};
    vector<int> list(n);
    for (int i = 0; i < n; ++i) {
        list[i] = dist(mersenne_engine);
    }
    return list;
}


vector<TestCase>
        testCases = {
        {"sorteren van vijf positieve getallen",
                {5,4,3,2,1}},
        {"sorteren van positieve eenheden",
                {9, 3, 5, 7, 1, 8, 2, 6, 4, 0}},
        {"sorteren van positieve eenheden en tientallen",
                {99, 59, 5, 71, 60, 63, 32, 79, 63, 0}},
        {"sorteren van positieve eenheden, tientallen en honderdtallen",
                {999,  8,    176,  54,  87,  471,  24,   122,  538,  0}},
        {"sorteren van negatieve eenheden",
                {-9,   0,    -9,   -2,  -5,  -9,   0,    -1,   -5,   -9}},
        {"sorteren van negatieve eenheden en tientallen",
                {-61,  -39,  -9,   -46, -68, -13,  -68,  -13,  -61,  -96}},
        {"sorteren van positieve en negatieve eenheden, tientallen en honderdtallen",
                {-720, -485, -1,   -52, -89, -134, -206, -165, -887, -755}},
        {"sorteren van positieve en negatieve eenheden",
                {6,    -5,   2,    -4,  -1,  -1,   9,    -9,   6,    -2}},
        {"sorteren van positieve en negatieve eenheden en tientallen",
                {66,   99,   54,   -97, -2,  81,   32,   61,   78,   96}},
        {"sorteren positieve en negatieve eenheden, tientallen en honderdtallen",
                {720,  -5,   -291, 2,   -89, -134, -206, 165,  887,  -755}}};


int main() {

    Server server = Server("Inleveropgave 3a: Merge Sort in C++");
//
    //    std::vector<int> xs = {1, 2, 3, 4, 5, 6, 7};
//    std::vector<int> ys = server.listReplaceIndexed(xs, 1, 4, {8, 9, 10});
//    for (const auto& y : ys) {
//        std::cout << y << " ";
//    }
//
    int startIndex = 0;
    int endIndex = 8;
    for (int i = startIndex; i <= endIndex; i++) {
        server.initialize(testCases[i].task, testCases[i].digits);
//        cout <<
//                          server <<
//             endl << endl;
    }

    return 0;
}
