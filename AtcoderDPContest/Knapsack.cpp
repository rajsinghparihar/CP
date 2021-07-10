#include<bits/stdc++.h>
using namespace std;


int main(void){
    int N,W;
    cin>>N>>W;
    long long int dp[N+1][W+1];
    long long int res;
    vector<int> wt(N),val(N);
    memset(dp,0,sizeof(dp));

    for(int i=0;i<N;i++)
    {
        cin>>wt[i]>>val[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = W; j > 0; j--)
        {
            if(wt[i-1] <= j){
                dp[i][j] = max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    res = dp[N][W];
    cout<<res<<endl;
}