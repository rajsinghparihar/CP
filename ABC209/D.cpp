// C++ program to calculate number
// of nodes between two nodes
#include <bits/stdc++.h>
using namespace std;

bool visited[100005];
bool color[100005];
void dfs(vector<int> adj[], int s, bool state) {
    visited[s] = true;
    color[s] = state;
    for(int i = 0;i < adj[s].size();++i)    {
        if(visited[adj[s][i]] == false)
        {
            color[adj[s][i]] = state;
            dfs(adj, adj[s][i], !state);
        }
    }
}
// Driver program to test above functions
int main()
{
    int n,q;
    cin>>n>>q;
	vector<int> adj[n+1];
    for(int i=1;i<=n;i++)
    {
        visited[i] = false;
        color[i] = false; // false -> red, true -> blue;
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool red = false;
    dfs(adj,1,red);
    for (int i = 0; i < q; i++)
    {
        int c,d;
        cin>>c>>d;
        if(color[c] == color[d])
            cout<<"Town"<<endl;
        else
            cout<<"Road"<<endl;
    }
    
	return 0;
}
