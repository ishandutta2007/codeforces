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
const int inf=~0U>>1;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000000+10;
string a,b;
const int seed=13331;
int P[maxn],Pre[maxn],Suf[maxn];
int main()
{
    //freopen("in","r",stdin);
    cin>>a>>b;int n=a.size();
    int l=0,r=0;
    rep(i,n-1)if(a[i]==b[i])++l;else break;
    for(int i=n-2;i>=0;i--)if(a[i+1]==b[i])++r;else break;
    vector<int>ans;
    //cout<<l<<" "<<r<<endl;
    rep(i,n)
    {
        if((i-1)-0+1<=l&&n-1-(i+1)+1<=r)
        {
            ans.pb(i);
        }
    }
    cout<<ans.size()<<endl;
    rep(i,ans.size())cout<<ans[i]+1<<" ";cout<<endl;
}