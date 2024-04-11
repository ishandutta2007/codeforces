#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;
string s;
int n;
ll x, y;
ll infi=1e18;
ll ans;

ll a[2][100009];
ll b[2][100009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    cin>>x>>y;
    ans=infi;
    n=s.size();
    ll db[2]={0, 0};
    ll xx[2]={x, y};
    ll qs=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='?')
        {
            qs++;
        }
        else
        {
            db[s[i]-'0']++;
        }
        a[0][i]=db[0];
        a[1][i]=db[1];
    }
    db[0]=0;
    db[1]=0;
    for(int i=n-1; i>=0; i--)
    {
        if(s[i]!='?')
        {
            db[s[i]-'0']++;
        }
        b[0][i]=db[0];
        b[1][i]=db[1];
    }

    ll baseans=0;

    for(int i=0; i<n; i++)
    {
        if(s[i]!='?')
        {
            int w=(s[i]-'0');
            baseans+=(b[1-w][i]*xx[w]);
        }
    }


    for(int t=0; t<2; t++)
    {
        ll ansc=baseans;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='?')
            {
                ansc+=(a[1-t][i]*xx[1-t]);
                ansc+=(b[1-t][i]*xx[t]);
            }
        }
        ans=min(ans, ansc);
        ll qcnt=0;

        for(int i=0; i<n; i++)
        {
            if(s[i]=='?')
            {
                //if(t==0 && i==0) cout<<". "<<ansc<<endl;
                ansc-=(a[1-t][i]*xx[1-t]);
                //if(t==0 && i==0) cout<<". "<<ansc<<endl;
                ansc-=(b[1-t][i]*xx[t]);
                //if(t==0 && i==0) cout<<". "<<ansc<<endl;
                ansc+=(a[t][i]*xx[t]);
                //if(t==0 && i==0) cout<<". "<<ansc<<endl;
                ansc+=(b[t][i]*xx[1-t]);
                //if(t==0 && i==0) cout<<". "<<ansc<<endl;
                qcnt++;

                ll newans=ansc+(xx[1-t]*(qs-qcnt)*(qcnt));
                ans=min(ans, newans);
                //if(t==0 && i==0) cout<<". "<<ansc<<endl;
            }

        }
    }
    cout<<ans<<endl;

    return 0;
}