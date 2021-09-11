#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int s, n;
    cin >> s >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    bool flag[n]; // true if ith dragon is defeated.
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (s > v[i].first)
        {
            s += v[i].second;
            flag[i] = true;
        }
        else
        {
            flag[i] = false;
        }
    }
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        ans = ans && flag[i];
    }
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
