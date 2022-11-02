//some standard head files
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
//some stl container
#include <utility>
#include <vector>
#include <set>
#include <map>
//all a,b means [a,b)
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(x) x.begin(),x.end()
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
//some typedef
typedef vector<int> VI;
typedef set<int> SI;
typedef map<int,int> MII;
//some iter
typedef VI::iterator vit;
typedef SI::iterator sit;
typedef MII::iterator mit;

int main()
{
    //freopen("in","r",stdin);
    int n,x,m,y;
    cin>>n>>x>>m>>y;
    if(x>y)swap(x,y),swap(n,m);
    long long ans=0;
    FOR(i,1,n+1)
    {
        int l=max(x+i-y,1),r=min(y-x+i-1,m);
        l=max(l,y-x-i+1);
        if(l<=r)ans+=(r-l+1)*2;
        else ans++;
    }
    int l=max(1,x+n+1-y),r=m;
    if(l<=r)ans+=(r-l+1);
    cout<<ans+1<<endl;
}