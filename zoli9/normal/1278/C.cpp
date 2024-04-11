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
int test;
int a[200009];
int b[200009];
int best[400009];
int maxi=200001;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        int sum=0;
        for(int i=n; i>=1; i--)
        {
            cin>>a[i];
            if(a[i]==2) sum++;
            else sum--;
        }
        for(int i=1; i<=n; i++)
        {
            cin>>b[i];
            if(b[i]==2) sum++;
            else sum--;
        }
        for(int i=0; i<=2*maxi+5; i++) best[i]=-1;
        best[maxi]=0;
        int s=0;
        for(int i=1; i<=n; i++)
        {
            if(b[i]==2) s++;
            else s--;
            if(best[s+maxi]==-1) best[s+maxi]=i;
        }
        int ans=2*n;
        s=0;
        //cout<<sum<<" : "<<s<<endl;
        if(best[sum-s+maxi]>=0) ans=min(ans, best[sum-s+maxi]);
        for(int i=1; i<=n; i++)
        {
            if(a[i]==2) s++;
            else s--;
            if(best[sum-s+maxi]>=0)
            {
                ans=min(ans, best[sum-s+maxi]+i);
                //cout<<i<<" es "<<best[sum-s+maxi]+i<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}