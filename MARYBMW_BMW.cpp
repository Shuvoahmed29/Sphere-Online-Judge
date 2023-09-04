#include<bits/stdc++.h>
using namespace std;
#define long long int
const int N = 1e5+10;
int parent[N],sz[N];
bool ok[N];
vector<int>g[N];
void make(int i)
{
    parent[i] = i;
    sz[i] = 1;
}
int find(int v)
{
    if(parent[v] == v) return parent[v];
    return parent[v] = find(parent[v]);
}
void Union(int v1, int v2)
{
    v1 = find(v1);
    v2 = find(v2);
    if(v1 != v2)
    {
        if(sz[v1] < sz[v2])    swap(v1,v2);
        parent[v2] = v1;
        sz[v1] += sz[v2];
    }
}
vector<int> bfs(int src,int n)
{
    queue<int> Q;
    vector<int>vec;
    Q.push(src);
    ok[src] = true;
    while(!Q.empty())
    {
        int p = Q.front();
        Q.pop();
        ok[p] = true;
        vec.push_back(p);
        if(p == n) return vec;
        for(auto child:g[p])
        {
            if(ok[child] == false)
            {
                Q.push(child);
                ok[child] = true;
            }
        }
    }
    return vec;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    int n,m,ans=1e18+9,i,v1,v2,wt,k;
    vector<int>vec1;
    while(tt--)
    {
        cin >> n >> m;
        vector<pair<int,pair<int,int>>> graph,grap1;
        for(i=0; i<m; i++)
        {
            cin >> v1 >> v2 >> wt;
            graph.push_back({wt,{v1,v2}});
        }
        sort(graph.begin(),graph.end());
        reverse(graph.begin(),graph.end());
        for(i=1; i<=n; i++) make(i);
        for(auto it:graph)
        {
            wt = it.first;
            v1 = it.second.first;
            v2 = it.second.second;
            if(find(v1) == find(v2)) continue;
            Union(v1,v2);
            vec1.push_back(v1);
            vec1.push_back(v2);
            g[v1].push_back(v2);
            g[v2].push_back(v1);
            grap1.push_back({wt,{v1,v2}});
        }
        vector<int> vec;
        vec = bfs(1,n);
        sort(vec1.begin(),vec1.end());
        vector<pair<int,int>> pr;
        k=vec.size()-1;
        if(vec1[vec1.size()-1] != n || vec1[0] != 1) cout << -1 << '\n';
        else
        {
            for(i=0; i<k; i++)
            {
                pr.push_back({vec[i],vec[i+1]});
            }
            for(auto it:grap1)
            {
                int wt = it.first;
                int v1 = it.second.first;
                int v2 = it.second.second;
                for(auto it:pr)
                {
                    if(it.first==v1 && it.second==v2)
                    {
                        ans = min(ans,wt);
                        break;
                    }
                    else if(it.first==v2 && it.second==v1)
                    {
                        ans = min(ans,wt);
                        break;
                    }
                }
            }
            cout << ans << '\n';
        }
    }
}
