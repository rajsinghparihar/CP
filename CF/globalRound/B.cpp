#include <bits/stdc++.h>
using namespace std;

bool isSup(vector<int> ath1, vector<int> ath2)
{
    int cnt = 0;
    for (int i = 0; i < ath1.size(); i++)
    {
        if (ath1[i] < ath2[i])
            cnt++;
    }
    if (cnt >= 3)
        return true;
    else
        return false;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        bool vis[n];
        cin >> n;
        vector<vector<int>> atheletes(n);
        for (int i = 0; i < n; i++)
        {
            vis[i] = false;
            int r1, r2, r3, r4, r5;
            cin >> r1 >> r2 >> r3 >> r4 >> r5;
            atheletes[i].push_back(r1);
            atheletes[i].push_back(r2);
            atheletes[i].push_back(r3);
            atheletes[i].push_back(r4);
            atheletes[i].push_back(r5);
        }
        stack<int> st;
        vector<int> par(n);
        st.push(0);
        for (int i = 0; i < n; i++)
        {
            int x = st.top();
            if (isSup(atheletes[i], atheletes[x]))
            {
                st.push(i);
                par[i] = x;
            }
        }
        int start = 0;
        bool notPos = false;
        if (n > 1)
        {
            while (1)
            {
                if (!vis[start])
                {
                    vis[start] = true;
                    start = par[start];
                }
                else if (vis[start])
                {
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                notPos = true;
                break;
            }
        }

        int ans;
        if (!st.empty())
            ans = st.top();
        if (notPos)
            ans = -2;
        cout << ans + 1 << endl;
    }
    return 0;
}