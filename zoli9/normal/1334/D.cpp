#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
ll n, l, r;
void pr(ll group, ll idx)
{
    if(group==n)
    {
        cout<<1<<" ";
        return;
    }
    if(idx%2==1)
    {
        cout<<group<<" ";
        return;
    }
    idx/=2;
    cout<<group+idx<<" ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n>>l>>r;
        vll s(n+1);
        for(ll i=1; i<n; i++)
        {
            s[i]=2*(n-i);
        }
        s[n]=1;
        ll sum=0;
        ll g1=-1;
        ll i1=-1;
        ll g2=-1;
        ll i2=-1;
        for(ll i=1; i<=n; i++)
        {
            if(i1==-1 && l<=sum+s[i])
            {
                g1=i;
                i1=l-sum;
            }
            if(i2==-1 && r<=sum+s[i])
            {
                g2=i;
                i2=r-sum;
            }
            sum+=s[i];
        }
        if(g1==g2)
        {
            for(ll i=i1; i<=i2; i++)
            {
                pr(g1, i);
            }
            cout<<'\n';
            continue;
        }
        for(ll i=i1; i<=s[g1]; i++) pr(g1, i);
        for(ll g=g1+1; g<g2; g++)
        {
            for(ll i=1; i<=s[g]; i++) pr(g, i);
        }
        for(ll i=1; i<=i2; i++) pr(g2, i);
        cout<<'\n';
    }

    return 0;
}