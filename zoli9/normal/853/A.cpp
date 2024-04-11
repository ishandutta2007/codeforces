#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
long long n;
long long k;
pair<long long, long long> parok;
set<pair<long long, long long> > s;
long long sorszam[300009];
long long w[300009];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    int cnt=1;
    for(int i=1; i<=n; i++)
    {
        cin>>w[i];
    }
    for(int i=1; i<=k; i++)
    {
        s.insert({-w[i], i});
    }
    cnt=k+1;
    for(int i=1; i<=n; i++)
    {
        if(cnt<=n)
        {
            s.insert({-w[cnt], cnt});
            cnt++;
        }
        pair<long long, long long> lo=*s.begin();
        sorszam[lo.S]=k+i;
        s.erase(s.begin());
    }
    long long ans=0;
    for(int i=1; i<=n; i++)
    {
        long long vv=(sorszam[i]-i)*w[i];
        ans+=(vv);
    }
    cout<<ans<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<sorszam[i]<<" ";
    }
cout<<endl;

    return 0;
}