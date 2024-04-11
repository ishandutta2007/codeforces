#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll h10[19];

ll dtotal[16];

ll teljes(ll x)
{
    ll hat10=0;
    ll y=x;
    while(y>0)
    {
        y/=10;
        hat10++;
    }
    ll res=0;
    ll dbszam=x;
    for(int i=1; i<=hat10; i++)
    {
        res+=((dbszam*(dbszam+1))/2);
        dbszam-=(9*h10[i-1]);
    }
    return res;
}

ll darab(ll k)
{
    ll kk=k;
    ll dnum=0;
    while(kk>0)
    {
        dnum++;
        kk/=10;
    }
    return dtotal[dnum-1]+(dnum*(k-h10[dnum-1]+1));
}

ll part2(ll n)
{
    ll elso=1;
    ll utolso=1e12;
    while(elso<=utolso)
    {
        ll kozep=(elso+utolso)/2;
        if(darab(kozep)>=n) utolso=kozep-1;
        else elso=kozep+1;
    }
    ll kell=n-darab(utolso);
    vi ds;
    while(elso>0)
    {
        ds.push_back(elso%10);
        elso/=10;
    }
    int siz=ds.size();
    return ds[siz-kell];
}
int test;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    h10[0]=1;
    for(int i=1; i<=18; i++)
    {
        h10[i]=10*h10[i-1];
    }
    dtotal[0]=0;
    for(int i=1; i<16; i++)
    {
        dtotal[i]=dtotal[i-1]+(h10[i-1]*9*i);
    }
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        ll w;
        cin>>w;
        ll elso=1;
        ll utolso=1e9;
        while(elso<=utolso)
        {
            ll kozep=(elso+utolso)/2;
            if(teljes(kozep)<w) elso=kozep+1;
            else utolso=kozep-1;
        }
        w-=teljes(utolso);
        cout<<part2(w)<<endl;
    }

    return 0;
}