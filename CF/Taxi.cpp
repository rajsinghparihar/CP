#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int cnt[5];
    int ans = 0;
    for(int i=0;i<5;i++)
        cnt[i] = 0;

    for (int i = 0; i < n; i++)
    {
        cnt[arr[i]]++;
    }
    cnt[1] = max(cnt[1]-cnt[3], 0);
    ans = cnt[4] + cnt[3] + (cnt[1] + 2*cnt[2] + 3)/4;
    cout<<ans<<endl;    
    return 0;
}