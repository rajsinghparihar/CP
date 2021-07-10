#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long int n;
    cin>>n;
    long long int arr[n];
    long long int m = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        if(arr[i] > m)
            m = arr[i];
    }
    long long int cnt[m+1];
    long long int dp[m+1];
    for (int i = 0; i < m+1; i++)
    {
        cnt[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cnt[arr[i]]++;
    }

    dp[0] = 0;
    dp[1] = cnt[1];
    for (int i = 2; i <= m; i++)
    {
        dp[i] = max(cnt[i]*i + dp[i-2],dp[i-1]);
    }
    
    cout<<dp[m]<<endl;
    return 0;
}