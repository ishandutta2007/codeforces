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
int n;
int a[200009];
vi G[200009];
int szint1[200009];
int szint2[200009];
bool bejar1[200009];
bool bejar2[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(i+a[i]<=n)
        {
            G[i+a[i]].push_back(i);
        }
        if(i-a[i]>=1)
        {
            G[i-a[i]].push_back(i);
        }
    }
    queue<int> q;
    for(int i=1; i<=n; i++)
    {
        if(a[i]%2)
        {
            szint1[i]=0;
            bejar1[i]=true;
            q.push(i);
        }
    }
    while(q.size()>0)
    {
        int akt=q.front();
        q.pop();
        for(int sz: G[akt])
        {
            if(!bejar1[sz])
            {
                bejar1[sz]=true;
                szint1[sz]=szint1[akt]+1;
                q.push(sz);
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(a[i]%2==0)
        {
            szint2[i]=0;
            bejar2[i]=true;
            q.push(i);
        }
    }
    while(q.size()>0)
    {
        int akt=q.front();
        q.pop();
        for(int sz: G[akt])
        {
            if(!bejar2[sz])
            {
                bejar2[sz]=true;
                szint2[sz]=szint2[akt]+1;
                q.push(sz);
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(a[i]%2)
        {
            if(szint2[i]==0) cout<<-1<<" ";
            else cout<<szint2[i]<<" ";
        }
        else
        {
            if(szint1[i]==0) cout<<-1<<" ";
            else cout<<szint1[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}