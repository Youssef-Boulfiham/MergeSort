#include <thread>
#include "include/Server.h"

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

std::string Server::timeDifferenceToString(
        std::chrono::duration<long long int, std::ratio<1, 1000000000>> timeDifference) {
    auto nanoseconds = timeDifference.count();
    long long seconds = nanoseconds / 1000000000;
    nanoseconds %= 1000000000;
    long long minutes = seconds / 60;
    seconds %= 60;
    long long hours = minutes / 60;
    minutes %= 60;
    std::stringstream oss;
    oss << hours << " uren, " << minutes << " minuten en " << seconds << " secondes";
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
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string verschil = Server.timeDifferenceToString(Server.setTimeCurrent() - Server.getTimeStart());
    os << "Server " << Server.getName() << std::endl
       << "START TIME " << Server.setTimeToString(Server.getTimeStart()) << std::endl
       << "test " << verschil;

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

void Server::initialize(const std::string &taskName,
                        const std::vector<int> &listUnsorted) {
}

int Server::stringToInt(char value) {
    return value - '0';
}
