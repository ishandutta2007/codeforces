#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n;
ll t[300009];
ll hs[300009];
ll khs[300009];
int inp[300009];
int ans=0;
void checking(int le, int ri)
{
    if(le<1 || ri>n) return;
    if((t[ri]^t[le-1])==khs[ri-le+1])
    {
        //cout<<le<<" "<<ri<<endl;
        ans++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    mt19937_64 rnd(time(NULL));
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        hs[i]=rnd();
        //cout<<hs[i]<<endl;
        khs[i]=(hs[i]^khs[i-1]);
    }
    for(int i=1; i<=n; i++)
    {
        cin>>inp[i];
        if(inp[i]==1) ans++;
        t[i]=(t[i-1]^hs[inp[i]]);
    }
    int maxi=1;
    for(int i=1; i<=n; i++)
    {
        if(inp[i]==1)
        {
            maxi=1;
            continue;
        }
        else
        {
            maxi=max(maxi, inp[i]);
            checking(i-maxi+1, i);
        }
    }
    maxi=1;
    for(int i=n; i>=1; i--)
    {
        if(inp[i]==1)
        {
            maxi=1;
            continue;
        }
        else
        {
            maxi=max(maxi, inp[i]);
            checking(i, i+maxi-1);
        }
    }
    cout<<ans<<endl;
    return 0;
}