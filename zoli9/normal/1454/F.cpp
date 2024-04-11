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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        int n;
        cin>>n;
        vpii a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i].F;
            a[i].S=i+1;
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        int cnt=0;

        set<int> s;
        for(int i=0; i<=n+1; i++) s.insert(i);

        int i1=-1;
        int i2=-1;

        vi ans;

        while(cnt<n)
        {
            vpii lvl;
            lvl.push_back(a[cnt]);
            cnt++;
            while(cnt<n && a[cnt].F==a[cnt-1].F)
            {
                lvl.push_back(a[cnt]);
                cnt++;
            }
            if(i1==-1)
            {
                if(lvl.size()>=3)
                {
                    ans.push_back(lvl[1].S-1);
                    ans.push_back(1);
                    ans.push_back(n-lvl[1].S);
                    break;
                }
                for(pii& p: lvl)
                {
                    s.erase(p.S);
                }
                i1=lvl.back().S;
                i2=lvl[0].S;
                continue;
            }
            for(int i=1; i+1<lvl.size(); i++)
            {
                s.erase(lvl[i].S);
            }
            bool ok=false;
            for(int i=1; i+1<lvl.size(); i++)
            {
                auto it=s.lower_bound(lvl[i].S+1);
                int v2=(*it);
                it--;

                int v1=(*it);

                if(v1<i1 && i2<v2 && i1>1 && i2<n)
                {
                    i1=min(i1, lvl[i].S);
                    i2=max(i2, lvl[i].S);
                    ans.push_back(i1-1);
                    ans.push_back(i2-i1+1);
                    ans.push_back(n-i2);
                    ok=true;
                    break;
                }
            }
            if(ok) break;
            s.erase(lvl[0].S);
            s.erase(lvl.back().S);
            for(pii& p: lvl)
            {
                //s.erase(p.S);
                i1=min(i1, p.S);
                i2=max(i2, p.S);
            }
        }
        if(ans.size()>0)
        {
            cout<<"YES"<<endl;
            for(int i=0; i<3; i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}