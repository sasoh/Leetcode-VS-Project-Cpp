#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <set>
using namespace std;

using Link = pair<int, int>;

static list<Link> linksToNeighbors(const vector<Link>& nodes, const set<Link>& removedNodes, int node) {
    list<Link> neighbors{};

    for (int i{ 0 }; i < nodes.size(); ++i) {
        auto n = nodes[i];
        if (removedNodes.contains(n)) continue;
        if (n.first == node || n.second == node) {
            neighbors.push_back(n);
        }
    }

    return neighbors;
}

static Link bfsCut(const vector<Link>& nodes, const set<int>& exitNodes, const set<Link>& removedLinks, int start) {
    auto neighbors{ linksToNeighbors(nodes, removedLinks, start) };
    set<Link> visited{};

    while (neighbors.size() > 0) {
        auto next = neighbors.front();
        neighbors.pop_front();
        visited.insert(next);

        if (exitNodes.contains(next.first) || exitNodes.contains(next.second)) {
            return next;
        }

        auto nextNeighbors = linksToNeighbors(nodes, removedLinks, next.second);
        for (const auto& n : nextNeighbors) {
            if (!visited.contains(n)) {
                neighbors.push_back(n);
            }
        }
    }

    return {};
}

int main()
{
    int n = 3;
    int l = 2;
    int e = 1;
    vector<Link> links{
        {0, 1},
        {1, 2},
    };
    set<int> exitNodes{ 1 };

    set<Link> removedLinks{};
    while (1) {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();
        auto toCut = bfsCut(links, exitNodes, removedLinks, si);
        cout << toCut.first << " " << toCut.second << endl;
        removedLinks.insert(toCut);
    }
}