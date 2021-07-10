#include<bits/stdc++.h>
using namespace std;

static int mod = 1e9+7;

int main(void){
    int n;
    cin>>n;
    int c[n];
    long long int ans = 1;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    sort(c,c+n);
    for(int i=0;i<n;i++)
    {
        if(c[i] < i){
            ans = 0;
            break;
        }
        ans = (ans*(c[i]-i)%mod);
    }
    cout<<ans%mod<<endl;
}