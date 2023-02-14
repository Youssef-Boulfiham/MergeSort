#pragma  once
#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <vector>


class Server {

    std::chrono::system_clock::time_point timeStart;
    std::chrono::system_clock::time_point timeCurrent;
    std::chrono::duration<long long, std::ratio<1, 1000000000>> timeDifference{};

    static std::chrono::system_clock::time_point setTimeCurrent();

    static std::string setTimeToString(std::chrono::system_clock::time_point timeToConvert);

    static std::string timeDifferenceToString(std::chrono::duration<long long, std::ratio<1, 1000000000>> timeDifference);

    [[nodiscard]] std::string getName() const;

    std::chrono::system_clock::time_point getTimeStart();

    std::chrono::system_clock::time_point getTimeCurrent();

    static std::vector<int> flattenListOfLists(const std::vector<std::vector<int>> &listOfLists);

    friend std::ostream &operator<<(std::ostream &os, Server &Server);

public:

    explicit Server(const std::string& assignmentName);

    static std::string printListOfLists(const std::vector<std::vector<int>> &listOfLists);

    static std::string intToString(int value);

    static int stringToInt(char value);

    std::string assignmentName;

    static std::string printList(const std::vector<int> &list);

    void initialize(const std::string& taskName, const std::vector<int>& listUnsorted);
};
#endif // SERVER_H
