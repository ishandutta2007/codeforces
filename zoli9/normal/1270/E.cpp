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
int x[1009];
int y[1009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int max2=25;
    for(int i=1; i<=n; i++)
    {
        cin>>x[i]>>y[i];
        if(i>1)
        {
            x[i]=abs(x[i]-x[1]);
            y[i]=abs(y[i]-y[1]);
            int z, db;
            if(x[i]!=0)
            {
                z=x[i];
                db=0;
                while(z%2==0)
                {
                    z/=2;
                    db++;
                }
                max2=min(max2, db);
            }
            if(y[i]!=0)
            {
                db=0;
                z=y[i];
                while(z%2==0)
                {
                    z/=2;
                    db++;
                }
                max2=min(max2, db);
            }
        }
    }
    vi ptlps;
    for(int i=2; i<=n; i++)
    {
        x[i]/=(1<<max2);
        y[i]/=(1<<max2);
        if(x[i]%2!=y[i]%2)
        {
            ptlps.push_back(i);
        }
    }
    if(ptlps.size()>0)
    {
        //cout<<"ok"<<endl;
        cout<<ptlps.size()<<endl;
        for(int u: ptlps)
        {
            cout<<u<<" ";
        }
        cout<<endl;
        return 0;
    }
    vi ptl;
    for(int i=2; i<=n; i++)
    {
        if(x[i]%2==1)
        {
            ptl.push_back(i);
        }
    }
    cout<<ptl.size()<<endl;
    for(int u: ptl)
    {
        cout<<u<<" ";
    }
    cout<<endl;
    return 0;
}