#include<bits/stdc++.h>
using namespace std;

int main(void){

    string s,t;
    cin>>s>>t;

    stack<char> st;
    int n = s.length();
    int m = t.length();

    int lcs[n+5][m+5];

    for(int i=0;i<=n;i++){
        lcs[i][0] = 0;
    }
    for(int j=0;j<=m;j++){
        lcs[0][j] = 0;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                lcs[i][j] = 1 + lcs[i-1][j-1];
            }
            else{
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    // cout<<s[n]<<" "<<t[m]<<endl;
    int i = n, j = m;
    while(i>0 && j>0){
        int temp = max(lcs[i][j-1],lcs[i-1][j]);
        if(temp == lcs[i][j]){
            if(temp == lcs[i-1][j]){
                i--;
            }
            else if(temp == lcs[i][j-1]){
                j--;
            }
        }
        else{
            st.push(s[i-1]);
            i--;
            j--;
        }
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
    return 0;
}