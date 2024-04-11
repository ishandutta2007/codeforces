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
int pre;
const int maxn=150;
typedef pair<int,int> pi;
int A[maxn],n,Dp[maxn],Pre[maxn];
int main()
{
    //freopen("in","r",stdin);
    int now=1,x;vector<int>p;
    cin>>n;rep(i,n)
    {
        cin>>x;
        if(x==now)
        {
            p.pb(i+1);
            now++;
        }
    }
    cout<<p.size()<<endl;
    rep(i,p.size())cout<<2000+p[i]<<" ";cout<<endl;
}