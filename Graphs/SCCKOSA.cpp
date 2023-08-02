//Shresth's Template
//checkpost CF
#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define fr0 for(int i=0; i<n; i++)
#define fr1 for(int i=1; i<=n; i++)
 
using namespace std;
int n;
int m;
int arr[100010];
int vis[100010];
vector<int> adj[100010];
vector<int> adjT[100010];
stack<int>s;
int mini = INT_MAX;


void dfs(int node){
    vis[node] = 1;

    for(auto child : adj[node]){
        if(!vis[child]){
            dfs(child);                 //toposort
        }
    }

    s.push(node);
}

void dfsT(int node, unordered_map<int,int>& mp){
    vis[node] = 1;
    mp[arr[node]]++;

    mini = min(mini, arr[node]);

    for(auto child : adjT[node]){       //dfs traversal
        if(!vis[child]){
            dfsT(child,mp);
        }
    }

}
 
int32_t main()
{
    cin>>n;
    for(int i = 1; i<=n; i++){          //price of every town input
        cin >> arr[i];
    }

    cin>>m;
    for(int i = 0;i<m; i++){
        int a,b; cin>>a>>b;             //graph input
        adj[a].pb(b);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);                     //toposort
        }
    }

    for(int node = 1; node<=n; node++){
        vis[node] = 0;
        for(auto child : adj[node]){
            adjT[child].push_back(node);    //graph transpose
        }
    }

    int minPrice = 0;
    int ways = 1;

    while(!s.empty()){
        int node = s.top();
        s.pop();
        mini = INT_MAX;
        unordered_map<int,int> mp;
        if(!vis[node]){
            dfsT(node,mp);
            minPrice += mini;
            ways *= mp[mini]%mod;
            ways %= mod;
        }
    }

    cout << minPrice <<" "<< ways <<endl;
}