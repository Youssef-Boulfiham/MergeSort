#include <thread>
#include "include/Server.h"
#include "include/MergeSort.h"

Server::Server(const std::string &assignmentName) {
    this->assignmentName = assignmentName;
    // defineer actuele tijd
    this->timeCurrent = Server::setTimeCurrent();
    // defineer hoelaat de Server is opgestart
    this->timeStart = this->timeCurrent;
    // plaatshouder voor berekende tijdverschillen
    this->timeDifference;
}

std::chrono::system_clock::time_point Server::setTimeCurrent() {
    return std::chrono::system_clock::now();
}

std::chrono::system_clock::time_point Server::getTimeStart() {
    return this->timeStart;
}

std::chrono::system_clock::time_point Server::getTimeCurrent() {
    return this->timeCurrent;
}

std::string Server::setTimeToString(std::chrono::system_clock::time_point timeToConvert) {
    std::time_t timeTime_t = std::chrono::system_clock::to_time_t(timeToConvert);
    std::tm timeTm = *std::localtime(&timeTime_t);
    std::_Put_time<char> time_Put_time = std::put_time(&timeTm, "%H:%M:%S");
    std::ostringstream oss;
    oss << time_Put_time;
    return oss.str();
}

#include <iomanip> // for std::setw() and std::setfill()

std::string Server::timeDifferenceToString(
        std::chrono::duration<long long int, std::ratio<1, 1000000000>> timeDifference) {
    auto nanoseconds = timeDifference.count();
    long long milliseconds = nanoseconds / 1000000;
    nanoseconds %= 1000000;
    long long seconds = milliseconds / 1000;
    milliseconds %= 1000;
    long long minutes = seconds / 60;
    seconds %= 60;
    long long hours = minutes / 60;
    minutes %= 60;
    long long days = hours / 24;
    hours %= 24;
    std::stringstream oss;
    if (days > 0) {
        oss << days << " dagen, ";
    }
    if (hours > 0 || days > 0) {
        oss << hours << " uren, ";
    }
    if (minutes > 0 || hours > 0 || days > 0) {
        oss << minutes << " minuten, ";
    }
    oss << seconds << " seconden, ";
    oss << std::setfill('0') << std::setw(3) << milliseconds << ",";
    oss << std::setfill('0') << std::setw(3) << nanoseconds / 1000000 << ",";
    oss << std::setfill('0') << std::setw(3) << (nanoseconds / 1000) % 1000;
    oss << " milisecondes";
    return oss.str();
}


std::string Server::getName() const { return this->assignmentName; }

std::string Server::printListOfLists(const std::vector<std::vector<int>> &listOfLists) {
    std::ostringstream os;
    if (listOfLists.size() == 1 && listOfLists[0].empty()) {
        os << "{{}}";
    } else {
        os << "{";
        for (const auto &list: listOfLists) {
            if (list.empty()) {
                os << "{}";
            } else {
                os << "{";
                for (int i = 0; i < list.size(); i++) {
                    os << list[i];
                    if (i != list.size() - 1) {
                        os << ",";
                    }
                }
                os << "}";
            }
        }
        os << "}";
    }
    return os.str();
}

std::ostream &operator<<(std::ostream &os, Server &Server) {
//    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string verschil = Server.timeDifferenceToString(Server.setTimeCurrent() - Server.getTimeStart());
    os << "Server " << Server.getName() << std::endl
       << "START TIME " << Server.setTimeToString(Server.getTimeStart()) << std::endl
       << verschil;

    return os;
}

std::string Server::printList(const std::vector<int> &list) {
    std::ostringstream os;
    os << "{";
    for (int i = 0; i < list.size(); i++) {
        os << list[i];
        if (i != list.size() - 1) {
            os << ",";
        }
    }
    os << "}";
    return os.str();
}

std::vector<int> Server::flattenListOfLists(const std::vector<std::vector<int>> &listOfLists) {
    std::vector<int> list;
    for (const auto &listInList: listOfLists) {
        for (const auto &integer: listInList) {
            list.push_back(integer);
        }
    }
    return list;
}

std::string Server::intToString(int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

int Server::stringToInt(char value) {
    return value - '0';
}

std::vector<int> Server::listReplaceIndexed(std::vector<int> xs,
                                            int p,
                                            int q,
                                            std::vector<int> ys) {
    xs.erase(xs.begin() + p, xs.begin() + q);
    xs.insert(xs.begin() + p, ys.begin(), ys.end());
    return xs;
}

std::vector<int> Server::getListSliced(std::vector<int> xs, int p, int q) {
    vector<int> xsSliced = std::vector<int>(xs.begin() + p, xs.begin() + q);
    return xsSliced;

}

void Server::initialize(const std::string &taskName,
                        const std::vector<int> &listUnsorted) {
    cout << taskName << endl;
    MergeSort mergeSort(taskName);
    mergeSort.run(listUnsorted);
}
