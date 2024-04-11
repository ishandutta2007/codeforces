#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
string s;
ll n;
ll preva[300009];
ll prevb[300009];
ll nexta[300009];
ll nextb[300009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    ll AB=0;
    int ac=-1;
    int bc=-1;
    for(int i=0; i<n; i++)
    {
        if(i>0 && s[i]!=s[i-1]) AB++;
        preva[i]=ac;
        prevb[i]=bc;
        if(s[i]=='A') ac=i;
        else bc=i;
    }
    ac=n;
    bc=n;
    for(int i=n-1; i>=0; i--)
    {
        nexta[i]=ac;
        nextb[i]=bc;
        if(s[i]=='A') ac=i;
        else bc=i;
    }
    ll rossz=0;
    for(ll i=0; i<n; i++)
    {
        if(s[i]=='A') rossz+=((i-preva[i])+(nexta[i]-i)-1);
        else rossz+=((i-prevb[i])+(nextb[i]-i)-1);
        //cout<<rossz<<endl;
    }
    rossz-=AB;
    ll ans=(n+1)*n/2;
    ans-=rossz;
    /*for(int i=0; i<n; i++)
    {
        int mini;
        if(s[i]=='A')
        {
            mini=min(nexta[i]-i, i-preva[i]);
        }
        else
        {
            mini=min(nextb[i]-i, i-prevb[i]);
        }
        mini--;
        ans+=(mini);
    }*/
    cout<<ans<<endl;
    return 0;
}