#include <iostream>
#include <cassert>
#include <vector>
#include <deque>

using std::cout;
using std::endl;
using std::vector;
using std::deque;

class Router {
    struct Packet {
        int source;
        int destination;
        int timestamp;

        Packet() {
            source = -1;
            destination = -1;
            timestamp = -1;
        }
        Packet(int s, int d, int t) : source(s), destination(d), timestamp(t) {
        }
    };
    deque<Packet> m_packets;
    int m_memoryLimit;
    bool containsPacket(const Packet& b) const {
        for (const auto& a : m_packets) {
            if (a.source == b.source && a.destination == b.destination && a.timestamp == b.timestamp) {
                return true;
            }
        }
        return false;
    }

    struct Range {
        int start;
        int end;
    };

    static int lowerBoundComp(const Packet& a, const int& value) {
        return a.timestamp < value;
    }

    static int upperBoundComp(const int& value, const Packet& a) {
        return a.timestamp < value;
    }

    int indexOfGreaterOrEqual(deque<Packet> list, int number) {
        size_t first = 0;
        size_t last = list.size() - 1;
        if (list[first].timestamp > number || list[last].timestamp < number) {
            return -1;
        }

        while (first < last) {
            size_t middle = (first + last) / 2;
            if (list[middle].timestamp < number) {
                first = middle + 1;
            }
            else {
                last = middle;
            }
        }

        return first;
    }

public:
    Router(int memoryLimit) : m_packets(0), m_memoryLimit(memoryLimit) {
    }

    bool addPacket(int source, int destination, int timestamp) {
        if (containsPacket({ source, destination, timestamp })) {
            return false;
        }

        m_packets.emplace_back(source, destination, timestamp);
        int packetsCount = m_packets.size();
        if (packetsCount > m_memoryLimit) {
            m_packets.pop_front();
        }

        return true;
    }

    vector<int> forwardPacket() {
        if (m_packets.size() < 1) return vector<int>(0);
        Packet next = m_packets.front();
        m_packets.pop_front();
        return { next.source, next.destination, next.timestamp };
    }

    int getCount(int destination, int startTime, int endTime) {
        int count = 0;
        int startIndex = indexOfGreaterOrEqual(m_packets, startTime);
        if (startIndex == -1) {
            startIndex = 0;
        }
        int endIndex = indexOfGreaterOrEqual(m_packets, endTime);
        if (endIndex == -1) return 0;
        for (int i = startIndex; i <= endIndex; i++) {
            if (m_packets[i].destination == destination) {
                count++;
            }
        }

        return count;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

static void test1() {
    Router* obj = new Router(3);
    bool p1 = obj->addPacket(1, 4, 90);
    bool p2 = obj->addPacket(2, 5, 90);
    bool p3 = obj->addPacket(1, 4, 90);
    bool p4 = obj->addPacket(3, 5, 95);
    bool p5 = obj->addPacket(4, 5, 105);
    vector<int> f1 = obj->forwardPacket();
    bool p6 = obj->addPacket(5, 2, 110);
    printf("end\n");
}

static void test2() {
    Router* obj = new Router(2);
    bool p1 = obj->addPacket(7, 4, 90);
    int a1 = obj->getCount(4, 1, 100);
    int a2 = obj->getCount(4, 99, 100);
    int a3 = obj->getCount(4, 99, 105);
    vector<int> f1 = obj->forwardPacket();
    vector<int> f2 = obj->forwardPacket();
    printf("end\n");
}

static void test3() {
    Router* obj = new Router(4);
    bool p1 = obj->addPacket(4, 5, 1);
    int a1 = obj->getCount(5, 1, 1);
    printf("end\n");
}

static void test4() {
    Router* obj = new Router(3);
    bool p1 = obj->addPacket(1, 4, 6);
    int a1 = obj->getCount(4, 1, 4);
    printf("end\n");
}

static void test5() {
    Router* obj = new Router(5);
    bool p1 = obj->addPacket(1, 4, 1);
    bool p2 = obj->addPacket(4, 2, 1);
    int a1 = obj->getCount(2, 1, 1);
    printf("p1 = %d p2 = %d a1 = %d\n", p1, p2, a1);
}

static void runTests() {
    //test1();
    //test2();
    //test3();
    //test4();
    test5();
}

int main() {
    runTests();
    return 0;
}