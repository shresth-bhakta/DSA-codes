//Shresth's Template
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


 void make(int v, int parent[], int size[]){
        parent[v] = v;
        size[v] = 1;
    }

    int find(int v, int parent[]){
        if(parent[v]==v) return parent[v];
        return parent[v] = find(parent[v], parent);
    }

    void Union(int a, int b, int parent[], int size[]){
         a = find(a,parent);
         b = find(b, parent);
        if(a!=b){
            if(size[a]<size[b]) swap(a,b);
            parent[b] = a;
            size[a]+=size[b];
        }
    }

 
int32_t main()
{
    
}