#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pp;
bool customComp(pp a, pp b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}
int main() //O(n^2)
{
    pp jobs[] = {{2, 100}, {1, 19}, {2, 27}, {1, 25}, {3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    int maxd = -1;
    for (int i = 0; i < n; i++)
        maxd = max(maxd, jobs[i].first);
    sort(jobs, jobs + n, customComp);
    vector<int> seq(maxd, -1);
    int prof = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].first - 1; j >= 0; j--)
        {
            if (seq[j] == -1)
            {
                prof += jobs[i].second;
                seq[j] = jobs[i].first;
                break;
            }
        }
    }
    cout << prof << endl;
    for (int i = 0; i < maxd; i++)
        if (seq[i] != -1)
            cout << seq[i] << " ";
}