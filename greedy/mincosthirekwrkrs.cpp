#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;    //quality,minWage
typedef pair<double, int> ppd; //ratio,quality

bool sortComp(ppi a, ppi b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
struct pqComp
{
    bool operator()(ppd a, ppd b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<ppi> worker(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        worker[i] = {x, y};
    }
    int k;
    cin >> k;
    vector<ppd> ratio(n);
    for (int i = 0; i < n; i++)
        ratio[i] = {(double)worker[i].second / worker[i].first, worker[i].first};

    sort(ratio.begin(), ratio.end(), sortComp);

    priority_queue<ppd, vector<ppd>, pqComp> maxheap;
    double minCost = 0, heapCost = 0;
    for (int i = 0; i < k; i++)
    {
        maxheap.push(ratio[i]);
        heapCost += ratio[i].second;
        cout << maxheap.top().first << " " << heapCost << endl;
    }
    minCost = ratio[k - 1].first * heapCost;

    for (int i = k; i < n; i++)
    {
        heapCost -= maxheap.top().second;
        maxheap.pop();
        maxheap.push(ratio[i]);
        heapCost += ratio[i].second;
        minCost = min(minCost, heapCost * ratio[i].first);
        cout << maxheap.top().first << " " << heapCost << endl;
    }
    cout << minCost;
}