#include<cstdio>
#include<set>
#include<map>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<ctime>
#define read freopen("in.txt","r",stdin)
#define maxlongint 2147483647

#define fori for(i=1;i<=n;i++)
#define forj for(j=1;j<=m;j++)
#define FOR(i,n) for(i=1;i<=n;i++)
#define DOWN(i,n) for(i=n;i>=1;i--)
#define in push_back
#define out pop_back
#define ll long l#include<cstdio>
#include<set>
#include<map>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<ctime>
#define read freopen("in.txt","r",stdin)
#define maxlongint 2147483647

#define fori for(i=1;i<=n;i++)
#define forj for(j=1;j<=m;j++)
#define FOR(i,n) for(i=1;i<=n;i++)
#define REP(i,a,b) for(i=a;i<b;i++)
#define DOWN(i,n) for(i=n;i>=1;i--)
#define in push_back
#define out pop_back
#define ll long long
#define lson 2*k
#define rson 2*k+1
#define left l,mid,lson
#define right mid+1,r,rson
#define s(n) scanf("%d",&n)
#define sd(x,y) scanf("%d%d",&x,&y)
#define fillfalse(v) memset(v,false,sizeof(v))
#define filltrue(v) memset(v,true,sizeof(v))
#define Fill0(a)    memset(a,0,sizeof(a))
#define Fillm(a) memset(a,-1,sizeof(a))
#define lowbit(x) x&(-x)
using namespace std;
const int maxn=1e5+10;
int a[250000];
vector<int> ans;
map<int,int> mm;

int gcd(int a,int b)
{int r;
    while(b>0)
    {  r=a%b;a=b;b=r;}
    return a;
}
int main() {
    int n,i,j;
    cin>>n;
    FOR(i,n*n) {cin>>a[i];mm[a[i]]++;}
    sort(a+1,a+1+n*n);
    DOWN(i,n*n)
    if (mm[a[i]]!=0)
    {
        mm[a[i]]--;
        REP(j,0,ans.size())
        {
            int t=gcd(ans[j],a[i]);
            mm[t]-=2;
        }
        ans.in(a[i]);
        if (ans.size()==n) break;
    }
    REP(i,0,n-1) cout<<ans[i]<<" ";
    cout<<ans[n-1]<<endl;
}