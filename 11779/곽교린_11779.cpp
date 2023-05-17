#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> graph[1001]; //[source](cost, destination) cost between each city
priority_queue<pair<int, vector<int>>> pq; //(cost, path)priority queue
int cost[1001] = { 0, }; //cost of arriving in each city
int cityN, busN, startC, destC; //city num, bus num, start city, destination city




int main()
{
    cin >> cityN >> busN;

    vector<int> sol; // solution

    int tempStart, tempDest, tempCost;
    for (int i = 0; i < cityN + 1; i++) {
        cost[i] = -1;
    }
    for (int i = 0; i < busN; i++) {
        cin >> tempStart >> tempDest >> tempCost;
        graph[tempStart].push_back({ -tempCost, tempDest });
    }
    cin >> startC >> destC;

    pq.push({ 0,vector<int>(1, startC) }); //insert start

    while (!pq.empty()) {
        pair<int, vector<int>> entry = pq.top(); //select costless entry
        pq.pop();
        if (cost[entry.second.back()] == -1 || -entry.first < cost[entry.second.back()]) { //throw out useless entry
            cost[entry.second.back()] = -entry.first; //update cost of arriving in each city
            if (entry.second.back() == destC) { //if this entry is destination
                sol = entry.second;
                continue;
            }
            for (auto k : graph[entry.second.back()]) {
                vector<int> tempV; //deep copy
                for (auto u : entry.second) {
                    tempV.push_back(u);
                }
                tempV.push_back(k.second);
                pq.push({ entry.first + k.first, tempV }); //add new entry
            }
        }
    }

    cout << cost[destC] << endl;
    cout << sol.size() << endl;
    for (auto i : sol) {
        cout << i << " ";
    }

    return 0;
}
