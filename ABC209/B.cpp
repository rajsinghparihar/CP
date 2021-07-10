#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,x;
    cin>>n>>x;
    int a[n];
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum += a[i];
        if(i%2==1)
        {
            sum--;
        }
    }
    if(sum <= x)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}