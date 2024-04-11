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
const int inf=~0U>>1,maxn=100+10;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,m,k,d[maxn],p[maxn],A[maxn];
int main()
{
    //freopen("in","r",stdin);
    cin>>n>>m>>k;
    rep(i,m)cin>>d[i];
    rep(i,k)cin>>p[i];
    int Min=inf;
    rep(i,m)
    {
        A[i]=0;
        rep(j,k)
        {
            if(p[j]%d[i]==0)
                A[i]++;
        }
        Min=min(Min,A[i]);
    }
    vector<int>ans;
    rep(i,m)
    {
        if(A[i]==Min)ans.pb(i+1);
    }
    cout<<ans.size()<<endl;
    rep(i,ans.size())cout<<ans[i]<<" ";cout<<endl;
}