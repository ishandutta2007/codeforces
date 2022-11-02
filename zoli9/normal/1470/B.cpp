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

bool com[1000009];
int sqf[1000009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    sqf[1]=1;

    for(int i=2; i<=1000000; i++)
    {
        if(com[i])
        {
            continue;
        }
        sqf[i]=i;
        for(int j=2*i; j<=1000000; j+=i)
        {
            com[j]=true;
            sqf[j]=sqf[j/i];
            if(sqf[j]%i==0) sqf[j]/=i;
            else sqf[j]*=i;
        }
    }

    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        map<int, int> ma;
        for(int i=1; i<=n; i++)
        {
            int x;
            cin>>x;
            ma[sqf[x]]++;
        }

        int ans0=1, ans1=1;
        int sum=0;
        for(auto it=ma.begin(); it!=ma.end(); it++)
        {
            ans0=max(ans0, it->second);
            ans1=max(ans1, it->second);
            if((it->second)%2==0 || (it->first)==1) sum+=(it->second);
        }
        ans1=max(ans1, sum);

        int q;
        cin>>q;
        for(int i=1; i<=q; i++)
        {
            ll x;
            cin>>x;
            if(x==0) cout<<ans0<<'\n';
            else cout<<ans1<<'\n';
        }
    }
    return 0;
}