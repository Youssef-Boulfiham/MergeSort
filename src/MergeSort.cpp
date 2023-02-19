#include "include/Server.h"
#include "include/MergeSort.h"

#include <algorithm>
#include <iostream>
#include <vector>


using std::string, std::cout, std::endl, std::vector, std::endl, std::iterator;


MergeSort::MergeSort(const string &taskName) {
}


std::vector<int> MergeSort::run(vector<int> xs) {
    // overerf algemene hulpfuncties
    Server server("inheritance");
    // defineer starttijd van deze operatie
    auto timeStart = Server::setTimeCurrent();
    // aantal dat met elkaar wordt vergeleken
    int unit = 1;
    // zolang de volledige lijst nog niet van klein naar groot is gesorteerd
    while (unit <= xs.size()) {
        // het aantal elementen dat met elkaar wordt vergeleken.
        int h = 0;
        // zolang het aantal elementen niet hoger is dan het totaal aantal elementen.
        // zet het dubbele van dit unit in stappen vooruit
        for (h; h < xs.size(); h += unit * 2) {
            // onthoudt h in apparte variabele
            int l = h;
            // onthoudt het bereik dat gecontroleerd kan worden
            int r1 = xs.size();
            int r2 = h + 2 * unit;
            // bereken het bereik dat gecontroleerd kan worden
            vector<int> lst = {r1, r2};
            // selecteer het laagste element van r1 en r2.
            int r = *min_element(lst.begin(), lst.end());
            // onthoudt element rechts dat zal worden vergeleken
            int mid = h + unit;
            // onthoudt indexwaarde
            int p = l;
            // onthoudt h weer
            int q = mid;
            // vergelijk elementen
            while ((p < mid) && (q < r)) {
                // wanneer element links kleiner dan element rechts
                if (xs[p] <= xs[q]) {
                    // hoog indexpositie van p met één op
                    p++;
                    // anders
                } else {
                    // onthoudt element tijdelijk
                    int tmp = xs[q];
                    // zet kleinere waarde voor geselecteerde reeks aaneengesloten van grotere waardes.
                    // verwijder kleinere waarde
                    xs = server.listReplaceIndexed(xs, p + 1, q + 1, server.getListSliced(xs, p, q));
                    // zet kleinere waarde voor de opgeschoven reeks/
                    xs = server.listReplaceIndexed(xs, p, p + 1, {tmp});
                    // hoog indexen op.
                    p++;
                    mid++;
                    q++;
                }
            }
        }
        // verbreedt unit maal twee
        unit *= 2;
    }
    // bereken duur van operatie
    //cout << server.timeDifferenceToString(server.setTimeCurrent()- timeStart) << endl;
    return xs;
}


