#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v;
        int cnt[5] = {0};
        int tot = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end(), greater<string>());
        for (int i = 0; i < n; i++)
        {
            string s = v[i];
            for (int k = 0; k < s.length(); k++)
            {
                cnt[s[k] - 'a']++;
            }
            tot += s.length();
            for (int j = 0; j < 5; j++)
            {
                if (2 * cnt[j] > tot)
                {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}