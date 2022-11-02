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

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        vi a;
        int mini=-1;
        int ii;
        for(ii=2; ii*ii<n; ii++)
        {
            if(n%ii!=0) continue;
            if(mini<0) mini=ii;
            a.push_back(ii);
            a.push_back(n/ii);
        }
        if(ii*ii==n) a.push_back(ii);
        a.push_back(n);
        bool pk=true;
        for(int x: a)
        {
            if(x%mini!=0)
            {
                pk=false;
                break;
            }
        }
        if(pk)
        {
            for(int x: a) cout<<x<<" ";
            cout<<'\n';
            cout<<0<<'\n';
            continue;
        }
        if(a.size()==3)
        {
            for(int x: a) cout<<x<<" ";
            cout<<'\n';
            cout<<1<<'\n';
            continue;
        }
        vi primes;
        int m=n;
        int cnt=2;
        while(cnt*cnt<=m)
        {
            if(m%cnt==0)
            {
                primes.push_back(cnt);
                while(m%cnt==0) m/=cnt;
            }
            cnt++;
        }
        if(m>1) primes.push_back(m);
        map<int, bool> ma;
        for(int pi=0; pi+1<primes.size(); pi++)
        {
            ma[primes[pi]]=true;
            ma[primes[pi]*primes[pi+1]]=true;
        }
        ma[primes.back()]=true;
        ma[n]=true;
        vector<bool> was(a.size(), false);
        for(int i=0; i<a.size(); i++)
        {
            if(ma[a[i]]) was[i]=true;
        }
        vi ans;
        for(int pi=0; pi+1<primes.size(); pi++)
        {
            ans.push_back(primes[pi]);
            for(int i=0; i<a.size(); i++)
            {
                if(!was[i] && a[i]%primes[pi]==0 && a[i]!=primes[pi+1]*primes[pi])
                {
                    was[i]=true;
                    ans.push_back(a[i]);
                }
            }
            ans.push_back(primes[pi+1]*primes[pi]);
        }
        ans.push_back(primes.back());
        for(int i=0; i<a.size(); i++)
        {
            if(!was[i] && a[i]%primes.back()==0)
            {
                was[i]=true;
                ans.push_back(a[i]);
            }
        }
        ans.push_back(n);
        for(int x: ans) cout<<x<<" ";
        cout<<'\n';
        cout<<0<<'\n';
    }
    return 0;
}