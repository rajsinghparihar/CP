#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        int cnt[26] = {0};
        bool vis[26] = {0};
        vector<char> diff;
        int ans = 0;
        int ones = 0;
        for (int i = 0; i < n; i++)
        {
            cnt[s[i] - 'a']++;
            vis[s[i] - 'a'] = false;
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[s[i] - 'a'] && cnt[s[i] - 'a'] >= 2)
            {
                vis[s[i] - 'a'] = true;
                ans++;
                // one red, one green
            }
            else if (!vis[s[i] - 'a'] && cnt[s[i] - 'a'] == 1)
            {
                diff.push_back(s[i]);
            }
        }
        int m = diff.size();
        sort(diff.begin(), diff.end());
        for (int i = 0; i < m; i++)
        {
            if (diff[i] != diff[(i + 1) % m])
                ones++;
        }
        ans += ones / 2;
        cout << ans << endl;
    }
    return 0;
}