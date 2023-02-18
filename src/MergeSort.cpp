#include <thread>
#include "include/Server.h"

#include "include/MergeSort.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <vector>


using std::string, std::cout, std::endl, std::vector, std::endl, std::iterator;


MergeSort::MergeSort(string taskName) {
}

std::vector<int> MergeSort::run(vector<int> xs) {
    Server server("inheritance");
    int unit = 1;
    while (unit <= xs.size()) {
        int h =0;
        for (h; h < xs.size() -2; h += unit *2) {
            int l = h;
            int r1 = xs.size();
            int r2 = h + 2 * unit;
            vector<int> lst = {r1, r2};
            int r = *min_element(lst.begin(), lst.end());
            int mid = h + unit;
            int p = l;
            int q = mid;
            while ((p < mid) && (q < r)) {
                if (xs[p] <= xs[q]) {
                    p += 1;
                } else {
                    std::vector<int> tmp = {xs[q]};
                    // indexeren
//                    cout << "-" << server.printList(xs) <<
//                         "-" << server.printList(server.getListSliced(xs, p, q))
//                         << "-" << server.printList(
//                            server.listReplaceIndexed(xs, p + 1, q + 1, server.getListSliced(xs, p, q))) << endl;
                    xs = server.listReplaceIndexed(xs, p + 1, q + 1, server.getListSliced(xs, p, q));
                    xs = server.listReplaceIndexed(xs, p, p+1, tmp);
                    p += 1;
                    mid += 1;
                    q += 1;
                }
            }
        }
        unit *= 2;
        cout << server.printList(xs) << endl;
        int a = 0;
    }
    return xs;
}
