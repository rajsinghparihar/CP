#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int a[n + 1];
    int indeg[n + 1];
    int outdeg[n + 1];
    vector<int> isolated;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        indeg[i] = 0;
        outdeg[i] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        if (a[i] != 0)
        {
            indeg[a[i]]++;
            outdeg[i]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0 && outdeg[i] == 0)
        {
            isolated.push_back(i);
        }
    }
    if (isolated.size() == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (isolated[0] != i && indeg[i] == 0)
            {
                a[isolated[0]] = i;
                outdeg[isolated[0]]++;
                indeg[i]++;
                break;
            }
        }
    }
    else if (isolated.size() > 1)
    {
        for (int i = 0; i < isolated.size(); i++)
        {
            int cur = isolated[i];
            int nxt = isolated[(i + 1) % isolated.size()];
            a[cur] = nxt;
            indeg[nxt]++;
            outdeg[cur]++;
        }
    }

    isolated.clear();
    vector<int> ins, outs;

    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            ins.push_back(i);
        if (outdeg[i] == 0)
            outs.push_back(i);
    }

    for (int i = 0; i < ins.size(); i++)
    {
        a[outs[i]] = ins[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}