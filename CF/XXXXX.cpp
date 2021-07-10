#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t,n,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        int arr[n];
        long long int sum = 0;
        int cnt = 0;
        int l = INT_MAX;
        int r = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            sum += arr[i];
            if(arr[i]%x == 0)
                cnt++;
        }
        if(cnt == n)
        {
            cout<<-1<<endl;
        }
        else if(sum % x != 0)
        {
            cout<<n<<endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if(arr[i]%x != 0)
                {
                    l = i;
                    break;
                }
            }
            for (int i = n-1; i >= 0; i--)
            {
                if(arr[i]%x != 0)
                {
                    r = i;
                    break;
                }
            }
            cout<<n-min(n-1-r+1,l-0+1)<<endl;
        }
    }
    return 0;
}