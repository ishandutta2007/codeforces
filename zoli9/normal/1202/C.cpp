#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int test;
string s;
vi a, b;
vi mina, maxa, minb, maxb;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>s;
        a.clear();
        b.clear();
        mina.clear();
        maxa.clear();
        minb.clear();
        maxb.clear();
        a.push_back(0);
        b.push_back(0);
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='W') a.push_back(a.back()+1);
            else if(s[i]=='S') a.push_back(a.back()-1);
            else if(s[i]=='D') b.push_back(b.back()+1);
            else if(s[i]=='A') b.push_back(b.back()-1);
        }
        mina.push_back(0);
        maxa.push_back(0);
        minb.push_back(0);
        maxb.push_back(0);
        for(int i=1; i<a.size(); i++)
        {
            mina.push_back(min(mina.back(), a[i]));
            maxa.push_back(max(maxa.back(), a[i]));
        }
        for(int i=1; i<b.size(); i++)
        {
            minb.push_back(min(minb.back(), b[i]));
            maxb.push_back(max(maxb.back(), b[i]));
        }
        int ares=maxa.back()-mina.back();
        int amax=a.back();
        int amin=a.back();
        for(int i=(int)(a.size())-1; i>=1; i--)
        {
            int kicsi=min(mina[i-1], amin-1);
            kicsi=min(kicsi, a[i-1]-1);
            int nagy=max(maxa[i-1], amax-1);
            ares=min(ares, nagy-kicsi);
            kicsi=min(mina[i-1], amin+1);
            nagy=max(maxa[i-1], amax+1);
            nagy=max(nagy, a[i-1]+1);
            ares=min(ares, nagy-kicsi);
            amax=max(amax, a[i-1]);
            amin=min(amin, a[i-1]);
        }
        for(int i=1; i<a.size(); i++)
        {
            mina.push_back(min(mina.back(), a[i]));
            maxa.push_back(max(maxa.back(), a[i]));
        }
        for(int i=1; i<b.size(); i++)
        {
            minb.push_back(min(minb.back(), b[i]));
            maxb.push_back(max(maxb.back(), b[i]));
        }
        int bres=maxb.back()-minb.back();
        int bmax=b.back();
        int bmin=b.back();
        for(int i=(int)(b.size())-1; i>=1; i--)
        {
            int kicsi=min(minb[i-1], bmin-1);
            kicsi=min(kicsi, b[i-1]-1);
            int nagy=max(maxb[i-1], bmax-1);
            bres=min(bres, nagy-kicsi);
            kicsi=min(minb[i-1], bmin+1);
            nagy=max(maxb[i-1], bmax+1);
            nagy=max(nagy, b[i-1]+1);
            bres=min(bres, nagy-kicsi);
            bmax=max(bmax, b[i-1]);
            bmin=min(bmin, b[i-1]);
        }
        ll alapa=maxa.back()-mina.back();
        ll alapb=maxb.back()-minb.back();
        ll al=ares;
        ll bl=bres;
        cout<<min((alapa+1)*(bl+1), (alapb+1)*(al+1))<<endl;
    }

    return 0;
}