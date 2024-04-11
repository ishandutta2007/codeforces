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
#define printTime cout<<"Time:"<<clock()-pre<<endl;pre=clock();
const int maxn=3000+10;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll inf=1LL<<60;
int n;
struct obj
{
    ll x,c;
    obj(){}
    obj(ll _x,ll _c):
        x(_x),c(_c){}
    bool operator<(const obj&o)const
    {
        return x<o.x;
    }
}P[maxn];
ll Dp[maxn];
int main()
{
    //freopen("in","r",stdin);
    cin>>n;
    rep(i,n)
    {
        cin>>P[i].x>>P[i].c;
        P[i].x*=-1;
    }
    P[n++]=obj(-inf,0);
    sort(P,P+n);
    Dp[0]=0;
    for(int i=1;i<n;i++)
    {
        ll sum=0;Dp[i]=inf;
        for(int j=i-1;j>=0;j--)
        {
            sum+=P[j+1].x;
            Dp[i]=min(Dp[i],P[i].x*(i-j)-sum+P[i].c+Dp[j]);
        }
    }
    cout<<Dp[n-1]<<endl;
}