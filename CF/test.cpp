#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int dp[n + 1][n + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     dp[i][i] = 1;
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = 2 * A[i] - A[j];
            for (int k = 0; k < n; k++)
            {
                if (A[k] == x)
                    dp[i][j] = dp[k][i] + 1;
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //ans = max(ans, dp[i][j]);
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    //return ans;
    return 0;
}
