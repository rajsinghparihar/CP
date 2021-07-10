#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    long long int l;
    cin>>n>>l;
    double dist[n];
    
    for (int i = 0; i < n; i++)
    {
        cin>>dist[i];
    }

    double ans = 0;
    sort(dist, dist+n);
    double maxDistLamps = 0;
    for (int i = 1; i < n; i++)
    {
        if(dist[i]-dist[i-1] > maxDistLamps)
            maxDistLamps = (dist[i]-dist[i-1]);
    }
    double distLeft = dist[0] - 0;
    double distRight = l - dist[n-1];

    ans = max(maxDistLamps/2,max(distLeft,distRight));

    cout<<setprecision(10)<<double(ans)<<endl;
    return 0;
}