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
        {"",
         {5, 6, 9, 6, 1, 8, 2, 0, 5, 6}}};

int main() {
    Server server = Server("Inleveropgave 3a: Merge Sort in C++");
    int startIndex = 0;
    int endIndex = 0;
    for (int i = startIndex; i <= endIndex; i++) {
        server.initialize(testCases[i].task, testCases[i].digits);
    }
    std::cout << server << std::endl;

    return 0;
}
