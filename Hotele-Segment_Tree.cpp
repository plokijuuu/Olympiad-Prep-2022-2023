#include <bits/stdc++.h>

using namespace std;
long long baza=pow(2,20);
long long tab[2*(2<<20)];
long long T[2<<20];
long long query(int p,int k)
{
    long long ans=0;
    p=p+baza-1;
    k=k+baza+1;
    while(p+1!=k)
    {
        if(p%2==0)
        {
            ans+=tab[p+1];
        }
        if(k%2==1)
        {
            ans+=tab[k-1];
        }
        p/=2;
        k/=2;
    }
    return ans;
}
void update(int ind,int val)
{
    ind=ind+baza;
    int roz=val-tab[ind];

    while(ind!=0)
    {
        tab[ind]=tab[ind]+roz;
        ind/=2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>T[i];
        tab[i+baza]=T[i];
    }

    for(int i=baza-1;i>=1;i--)
    {
        tab[i]=tab[i*2]+tab[i*2+1];
    }
    for(int i=1;i<=q;i++)
    {
        int a,b,x,y,liczba;
        cin>>liczba;
        if(liczba==1)
        {
            cin>>a>>b;
            update(a,b);
        }
        else if (liczba==2)
        {
            cin>>x>>y;
            if(x>y) cout<<"0"<<endl;
            else cout<<query(x,y)<<endl;
        }

    }
    return 0;
}
