#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
int n, k;
vi dia;
vi G[200009];
bool bejar[200009];
int szint[200009];
int apa[200009];
int szin[200009];
int croot;
 
bool dfs(int x, int cl, int df)
{
    bejar[x]=true;
    szin[x]=cl;
    if(x!=dia[croot] && min(croot, (int)(dia.size())-1-croot)+szint[x]-szint[dia[croot]]>=k-1) return false;
    for(int sz: G[x])
    {
        if(!bejar[sz])
        {
            int clnew=(cl+df+k)%k;
            if(!dfs(sz, clnew, df)) return false;
        }
    }
    return true;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin>>n>>k;
    for(int i=1; i<n; i++)
    {
        int aa, bb;
        cin>>aa>>bb;
        G[aa].push_back(bb);
        G[bb].push_back(aa);
    }
    queue<int> q;
    q.push(1);
    szint[1]=0;
    bejar[1]=true;
    while(!q.empty())
    {
        int akt=q.front();
        q.pop();
        for(int sz: G[akt])
        {
            if(!bejar[sz])
            {
                szint[sz]=szint[akt]+1;
                q.push(sz);
                bejar[sz]=true;
            }
        }
    }
    if(k==2)
    {
        cout<<"Yes"<<endl;
        for(int i=1; i<=n; i++)
        {
            cout<<szint[i]%2+1<<" ";
        }
        cout<<endl;
        return 0;
    }
    int kezd=1;
    for(int i=1; i<=n; i++)
    {
        if(szint[i]>szint[kezd]) kezd=i;
        bejar[i]=false;
    }
    q.push(kezd);
    szint[kezd]=0;
    bejar[kezd]=true;
    while(!q.empty())
    {
        int akt=q.front();
        q.pop();
        for(int sz: G[akt])
        {
            if(!bejar[sz])
            {
                szint[sz]=szint[akt]+1;
                q.push(sz);
                bejar[sz]=true;
                apa[sz]=akt;
            }
        }
    }
    int veg=1;
    for(int i=1; i<=n; i++)
    {
        if(szint[i]>szint[veg]) veg=i;
        bejar[i]=false;
    }
    int akt=veg;
    dia.push_back(akt);
    bejar[akt]=true;
    while(akt!=kezd)
    {
        akt=apa[akt];
        dia.push_back(akt);
        bejar[akt]=true;
    }
    reverse(dia.begin(), dia.end());
 
    for(int idx=0; idx<dia.size(); idx++)
    {
        croot=idx;
        if(2*idx<dia.size())
        {
            if(!dfs(dia[idx], idx%k, -1))
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
        else
        {
            if(!dfs(dia[idx], idx%k, 1))
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<szin[i]+1<<" ";
    }
    cout<<endl;
    return 0;
}