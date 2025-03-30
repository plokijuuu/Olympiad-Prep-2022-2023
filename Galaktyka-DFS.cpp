#include <iostream>
#include <vector>

using namespace std;

vector<int>W[1000000];
int vis[1000000];

void DFS(int w)
    {

       vis[w]=1;
       for(int i=0;i<W[w].size();i++)
       {
            int v = W[w][i];
           if(vis[v]==0)
           {
               DFS(v);
           }
       }

    }
int main()
{
    int N,m,a,b;
    cin>>N>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        W[a].push_back(b);
        W[b].push_back(a);
    }
    int ans=0;
    for(int i=1;i<=N;i++)
    {

        if(!vis[i])
        {
            DFS(i),ans++;
        }
    }
    cout<<ans;

    return 0;
}
