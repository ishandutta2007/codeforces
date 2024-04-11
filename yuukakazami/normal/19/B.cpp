#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <cstring>
#include <time.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define Debug(x) cout<<#x<<"="<<x<<endl;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define tr(e,x) for(typeof(x.begin()) e=x.begin();e!=x.end();e++)
#define printTime cout<<"Time:"<<pre-clock()<<endl;pre=clock();
const int maxn=2000+10;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll inf=1LL<<60;
ll Dp[maxn];
int main()
{
    //freopen("in","r",stdin);
    rep(i,maxn)Dp[i]=inf;Dp[0]=0;
    int n,c,t;cin>>n;
    rep(i,n)
    {
        cin>>t>>c;t++;
        for(int j=n;j>=0;j--)
        {
            ll tmp=c+Dp[max(j-t,0)];
            Dp[j]=min(Dp[j],tmp);
        }
    }
    cout<<Dp[n]<<endl;
}