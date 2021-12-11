#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int, int>, int> pp;
bool comp(pp a, pp b)
{
    return a.first.second < b.first.second;
}
int main() //include or exclude principle
{
    pp jobs[] = {{{3, 10}, 20}, {{1, 2}, 50}, {{6, 19}, 100}, {{2, 100}, 200}};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    sort(jobs, jobs + n, comp);

    for (pp i : jobs)
        cout << i.first.first << " " << i.first.second << " " << i.second << endl;

    vector<int> prof(n, 0);
    prof[0] = jobs[0].second;

    for (int i = 1; i < n; i++)
    {
        int inc = jobs[i].second, exec = prof[i - 1];

        int l = 0, h = i - 1, m, p = -1;
        while (l <= h)
        {
            m = l + (h - l) / 2;
            if (jobs[m].first.second < jobs[i].first.first)
            {
                p = m;
                l = m + 1;
            }
            else
                h = m - 1;
        }

        if (p != -1)
            inc += prof[p];

        prof[i] = max(exec, inc);
    }
    cout << prof[n - 1] << endl;
    for (int i : prof)
        cout << i << " ";
}