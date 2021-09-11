#include <bits/stdc++.h>
using namespace std;
long long int dp[21][21][2]; // dp
long long int dig[21];       // number

long long int rec(int pos, int cnt, int flag)
{
    if (dp[pos][cnt][flag] != -1)
        return dp[pos][cnt][flag];

    if (pos == 20)
    {
        if (cnt <= 3)
            return 1;
        else
            return 0;
    }
    long long int ans = 0;
    if (flag == 0)
    {
        for (int d = 0; d < dig[pos]; d++)
        {
            ans += rec(pos + 1, cnt + (d != 0), 1);
        }
        ans += rec(pos + 1, cnt + (dig[pos] != 0), 0);
    }
    else
    {
        for (int d = 0; d < 10; d++)
        {
            ans += rec(pos + 1, cnt + (d != 0), 1);
        }
    }
    return dp[pos][cnt][flag] = ans;
}

long long int solve(long long int x)
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        dig[i] = 0;
    }
    int last = 19;
    while (x > 0)
    {
        dig[last] = x % (10LL);
        x /= (10LL);
        last--;
    }
    return rec(0, 0, 0);
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << endl;
    }
    return 0;
}