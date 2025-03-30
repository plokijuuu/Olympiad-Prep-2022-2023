#include <bits/stdc++.h>

using namespace std;
vector<int>g[1000000];
int vis[1000000];
int col[1000000];
queue<int>q;
void BFS(int v)
{

    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int w:g[v])
        {
        if(vis[w]==0)
        {
            vis[w]=1;
            if(col[v]==2)
            {
                col[w]=1;
            }
            else col [w]=2;
             q.push(w);}
            if(col[w]==col[v])
            {
                cout<<"NIE";
                exit(0);
            }


        }
    }
}
int main()
{
    int N,s,a,b;
    cin>>N>>s;
    for(int i=1;i<=s;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=s;i++)
    {
        if(!vis[i])
        {
            col[i]=2;
            BFS(i);
            q.push(i);
        }
    }
    cout<<"TAK";

    return 0;
}
