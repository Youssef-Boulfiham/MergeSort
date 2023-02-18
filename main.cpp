#include <iostream>
#include "src/include/Server.h"
#include <vector>
#include <iterator>
#include <functional>

using std::string, std::cout, std::endl, std::vector;

struct TestCase {
    string task;
    vector<int> digits;
};

vector<TestCase>
        testCases = {
        {"testrun",
         {1, 0, 3, 2}},
        {"testrun1",
         {5, 6, 9, 6, 1, 8, 2, 0, 5, 6}}};


int main() {

    Server server = Server("Inleveropgave 3a: Merge Sort in C++");
//
    //    std::vector<int> xs = {1, 2, 3, 4, 5, 6, 7};
//    std::vector<int> ys = server.listReplaceIndexed(xs, 1, 4, {8, 9, 10});
//    for (const auto& y : ys) {
//        std::cout << y << " ";
//    }
//
    int startIndex = 1;
    int endIndex = 1;
    for (int i = startIndex; i <= endIndex; i++) {
        server.initialize(testCases[i].task, testCases[i].digits);
    }
//    std::cout << server <<
//              std::endl;

    return 0;
}
