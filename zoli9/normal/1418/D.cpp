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
multiset<int> df;
set<int> s;

int n, q;

void er(int d)
{
    df.erase(df.lower_bound(d));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        s.insert(x);
        int z1=-1;
        int z2=-1;
        auto it=s.find(x);
        if(it!=s.begin())
        {
            it--;
            int y=(*it);
            it++;
            df.insert(abs(x-y));
            z1=y;
        }
        it++;
        if(it!=s.end())
        {
            int y=(*it);
            df.insert(abs(x-y));
            z2=y;
        }
        if(z1>=0 && z2>=0)
        {
            er(abs(z2-z1));
        }
    }
    if(s.size()<=2)
    {
        cout<<0<<'\n';
    }
    else
    {
        int small=(*s.begin());
        auto bigit=s.end();
        bigit--;
        int big=*bigit;
        auto dfit=df.end();
        dfit--;
        int bigdf=*dfit;
        cout<<big-small-bigdf<<'\n';
    }

    for(int tt=1; tt<=q; tt++)
    {
        int tp;
        int x;
        cin>>tp>>x;
        if(tp==1)
        {
            s.insert(x);
            int z1=-1;
            int z2=-1;
            auto it=s.find(x);
            if(it!=s.begin())
            {
                it--;
                int y=(*it);
                it++;
                df.insert(abs(x-y));
                z1=y;
            }
            it++;
            if(it!=s.end())
            {
                int y=(*it);
                df.insert(abs(x-y));
                z2=y;
            }
            if(z1>=0 && z2>=0)
            {
                er(abs(z2-z1));
            }
        }
        else
        {
            auto it=s.find(x);
            int z1=-1;
            int z2=-1;
            if(it!=s.begin())
            {
                it--;
                int y=(*it);
                it++;
                er(abs(x-y));
                z1=y;
            }
            it++;
            if(it!=s.end())
            {
                int y=(*it);
                er(abs(x-y));
                z2=y;
            }
            s.erase(x);
            if(z1>=0 && z2>=0)
            {
                df.insert(abs(z2-z1));
            }
        }
        if(s.size()<=2)
        {
            cout<<0<<'\n';
            continue;
        }
        int small=(*s.begin());
        auto bigit=s.end();
        bigit--;
        int big=*bigit;
        auto dfit=df.end();
        dfit--;
        int bigdf=*dfit;
        cout<<big-small-bigdf<<'\n';
    }

    return 0;
}