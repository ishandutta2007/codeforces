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
int n,l,a[110];
int main()
{
    //freopen("in","r",stdin);
    cin>>n>>l;rep(i,n)cin>>a[i];int ans=-inf;
    for(int i=l;i<=110;i++)
    {
        int t=0;rep(j,n)t+=a[j]/i;
        ans=max(ans,t*i);
    }
    cout<<ans<<endl;
}