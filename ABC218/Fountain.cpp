#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> a(n), dp(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int left;
    int right;

    for (int i = 0; i < n; i++)
    {
        left = max(i - a[i], 0);
        right = min(i + a[i] + 1, n);
        dp[left] = max(dp[left], right);
    }
    int ans = 1;
    right = dp[0];
    int nxt = -1;
    for (int i = 0; i < n; i++)
    {
        nxt = max(nxt, dp[i]);
        if (i == right)
        {
            ans++;
            right = nxt;
        }
    }
    cout << ans << endl;
    return 0;
}