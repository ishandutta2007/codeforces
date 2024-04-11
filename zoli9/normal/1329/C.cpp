#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int g, h;
ll a[1500009];
int szint[1500009];
vi solution;
ll ans;
int si[1500009];
int endsi[1500009];
bool tele[1500009];
int g2;
int h2;

void kivesz(int x)
{
    if(x>=(1<<(h-1)))
    {
        a[x]=0;
        return;
    }
    if(x<g2)
    {
        si[x]--;
        if(si[x]==endsi[x]) tele[x]=true;
    }
    if(a[2*x]==0 && a[2*x+1]==0)
    {
        a[x]=0;
        return;
    }
    if(a[2*x]>a[2*x+1])
    {
        a[x]=a[2*x];
        kivesz(2*x);
    }
    else
    {
        a[x]=a[2*x+1];
        kivesz(2*x+1);
    }
    if(a[2*x]>a[2*x+1])
    {
        if(tele[2*x]) tele[x]=true;
    }
    else
    {
        if(tele[2*x+1]) tele[x]=true;
    }
}

void solve(int node)
{
    if(node>=g2)
    {
        if(a[node]>0)
        {
            solution.push_back(node);
            ans-=a[node];
        }
        if(node<(1<<(h-1)))
        {
            solve(2*node);
            solve(2*node+1);
        }
        return;
    }
    while(!tele[node])
    {
        solution.push_back(node);
        ans-=a[node];
        kivesz(node);
    }
    solve(2*node);
    solve(2*node+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    szint[1]=1;
    for(int i=2; i<=1100000; i++)
    {
        szint[i]=1+szint[i/2];
    }
    while(test--)
    {
        cin>>h>>g;
        g2=(1<<g);
        h2=(1<<h);
        ans=0;
        solution.clear();
        for(int i=1; i<h2; i++)
        {
            cin>>a[i];
            ans+=a[i];
            si[i]=(1<<(h-szint[i]+1))-1;
            tele[i]=false;
            if(i<(1<<g)) endsi[i]=(1<<(g-szint[i]+1))-1;
        }
        solve(1);
        cout<<ans<<'\n';
        for(int aa: solution) cout<<aa<<" ";
        cout<<'\n';
    }


    return 0;
}