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

vll t, p;
ll sumsmall[500009];
ll sumbig[500009];
int sumS[500009];
int sumB[500009];
vpll idxs[500009];
ll seqSize;
vll seq;
ll m[5000009];
ll n;
int getSeqIndex[500009];
int lastIndex[500009];
ll cumsum[500009];

bool possible[500009];
ll dp[500009];

void modosit(int cs, int k, int v, int h, ll val)
{
    if(h<k || v<h) return;
    if(k==v && k==h)
    {
        m[cs]+=val;
        return;
    }
    m[cs]+=val;
    modosit(2*cs, k, (k+v)/2, h, val);
    modosit(2*cs+1, (k+v)/2+1, v, h, val);
}
ll kerdes(int cs, int k, int v, int x, int y)
{
    if(x>y) return 0;
    if(y<k || v<x) return 0;
    if(x<=k && v<=y) return m[cs];
    ll p1=kerdes(2*cs, k, (k+v)/2, x, y);
    ll p2=kerdes(2*cs+1, (k+v)/2+1, v, x, y);
    return p1+p2;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    t.resize(n);
    p.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>t[i];
    }
    t.push_back(n+1);
    cumsum[0]=0;
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
        idxs[t[i]].push_back({p[i], i});
        cumsum[i+1]=cumsum[i]+p[i];
    }
    cin>>seqSize;
    seq.resize(seqSize);
    for(int i=0; i<seqSize; i++)
    {
        cin>>seq[i];
        getSeqIndex[seq[i]]=i+1;
    }
    seq.push_back(n+1);
    seqSize++;
    getSeqIndex[n+1]=seqSize;
    lastIndex[n+1]=n;
    for(int i=n-1; i>=0; i--)
    {
        if(getSeqIndex[t[i]]==0) continue;
        if(getSeqIndex[t[i]]==seqSize)
        {
            lastIndex[t[i]]=i;
            continue;
        }
        sumS[i]=lastIndex[t[i]];
        sumB[i]=lastIndex[seq[getSeqIndex[t[i]]]];
        lastIndex[t[i]]=i;
    }
    for(int i=0; i<=n; i++)
    {
        for(pll prs: idxs[i])
        {
            if(prs.F>0)
            {
                modosit(1, 0, n-1, prs.S, prs.F);
            }
        }
        for(pll prs: idxs[i])
        {
            if(sumB[prs.S]>0)
            {
                sumbig[prs.S]=kerdes(1, 0, n-1, prs.S+1, sumB[prs.S]-1);
            }
        }
        if(getSeqIndex[i]==0 || getSeqIndex[i]==seqSize) continue;
        for(pll prs: idxs[seq[getSeqIndex[i]]])
        {
            if(sumS[prs.S]>0)
            {
                sumsmall[prs.S]=kerdes(1, 0, n-1, prs.S+1, sumS[prs.S]-1);
            }
        }
    }
    possible[n]=true;
    dp[n]=0;
    for(int i=n-1; i>=0; i--)
    {
        if(getSeqIndex[t[i]]==0) continue;
        if(sumS[i]>0)
        {
            if(possible[sumS[i]])
            {
                possible[i]=true;
                dp[i]=dp[sumS[i]]+cumsum[sumS[i]]-cumsum[i+1]-sumsmall[i];
                if(p[i]<0) dp[i]+=p[i];
            }
        }
        if(sumB[i]>0)
        {
            if(possible[sumB[i]])
            {
                ll newdp=dp[sumB[i]]+cumsum[sumB[i]]-cumsum[i+1]-sumbig[i];
                if((!possible[i]) || newdp<dp[i])
                {
                    dp[i]=newdp;
                    possible[i]=true;
                }
            }
        }
    }
    /*cout<<"small: ";
    for(int i=0; i<n; i++)
    {
        cout<<possible[i]<<" ";
    }
    cout<<endl;
    cout<<"big: ";
    for(int i=0; i<n; i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;*/

    ll answer=0;

    for(int i=0; i<n; i++)
    {
        if(t[i]==seq[0])
        {
            if(!possible[i])
            {
                cout<<"NO"<<'\n';
                return 0;
            }
            cout<<"YES"<<'\n';
            cout<<answer+dp[i]<<'\n';
            return 0;
        }
        else answer+=p[i];
    }
    cout<<"NO"<<'\n';
    return 0;
}