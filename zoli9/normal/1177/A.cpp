#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll n;
ll hat10[19];
ll dtotal[16];

ll darab(ll k)
{
    ll kk=k;
    ll dnum=0;
    while(kk>0)
    {
        dnum++;
        kk/=10;
    }
    return dtotal[dnum-1]+(dnum*(k-hat10[dnum-1]+1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    hat10[0]=1;
    for(int i=1; i<19; i++) hat10[i]=hat10[i-1]*10ll;
    dtotal[0]=0;
    for(int i=1; i<16; i++)
    {
        dtotal[i]=dtotal[i-1]+(hat10[i-1]*9*i);
    }
    cin>>n;
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
    cout<<ds[siz-kell]<<endl;
    return 0;
}