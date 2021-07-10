#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    int arr[n];
    int cnt1=0,cnt2=0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        if((arr[i]-arr[i-1]) < 0)
            cnt1++;
    }
    for (int i = 1; i < n; i++)
    {
        if((arr[i]-arr[i-1]) < 0)
        {
            while ((arr[i]-arr[i-1]) < 0)
            {
                cnt2++;
                i++;
            }
            break;
        }
    }
    if(cnt1 != cnt2)
    {
        cout<<"no"<<endl;
    }
    else
    {
        cout<<"yes"<<endl;
    }
    
    return 0;
}