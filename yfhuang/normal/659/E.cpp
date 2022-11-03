//
//  main.cpp
//  E
//
//  Created by  on 16/3/31.
//  Copyright  2016 . All rights reserved.
//

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
typedef  long long LL;
typedef  unsigned long long ULL;
#define fori for(i=1;i<=n;i++)
#define forj for(j=1;j<=m;j++)
#define FOR(i,n) for(i=1;i<=n;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define DREP(i,a,b) for(i=a;i>=b;i--)
#define DOWN(i,n) for(i=n;i>=1;i--)
#define enter cout<<endl;
#define in push_back
#define out pop_back
#define ll long long
#define lson 2*k
#define rson 2*k+1
#define left l,mid,lson
#define offcin ios::sync_with_stdio(false)
#define right mid+1,r,rson
#define s(n) scanf("%d",&n)
#define sd(x,y) scanf("%d%d",&x,&y)
#define sch(s) scanf("%s",s)
#define fillfalse(v) memset(v,false,sizeof(v))
#define filltrue(v) memset(v,true,sizeof(v))
#define Fill0(a)    memset(a,0,sizeof(a))
#define Fillplus(a)    memset(a,-1,sizeof(a))
#define lowbit(x) x&(-x)
using namespace std;
const int maxn=100000+5;
int i,j,k,l,n,h,m,x,y,z,ans,tt;
int v[maxn];
int f[maxn];
vector<int> a[maxn];
int dsu(int u) {
    return u == f[u]
    ? u : f[u] = dsu (f[u]) ;
}
void dfs (int x,int fa)
{
    int u,i,w;
    v[x]=1;
    if (a[x].size()==0) return;
    w=(int)a[x].size()-1;
    REP(i,0,w)
    if (a[x][i]!=fa)
    {
        u=a[x][i];
        if (dsu(x)==
            dsu(u)) k=0;
        else f[u]=dsu(x);
        if (v[u]==0) dfs(u,x);
    }
}
int main(){
    cin>>n>>m;
    for(int i =1;i<=n;i++)f[i]=i;
    FOR(i,m)
    {
        sd(x,y);
        a[x].in(y);
        a[y].in(x);
    }
    ans=0;
    for(int i =1;i<=n;i++)
    if (v[i]==0)
    {
        k=1;
        dfs(i,-1);
        ans+=k;
    }
    cout<<ans<<endl;
}
/*
 
 #include <iostream>
 #include <cstring>
 #include <cstdio>
 #include <algorithm>
 #include <cmath>
 using namespace std;
 
 const int INF=0x3f3f3f3f;
 const int maxn=50010;
 
 typedef long long ll;
 
 ll num[maxn],up[maxn],dw[maxn],aa,bb,cc,ans;
 int col[maxn],pos[maxn];
 
 struct qnode{
 int l,r,id;
 }qu[maxn];
//
 //  main.cpp
 //  HYSBZ2038
 //
 //  Created by  on 16/1/24.
 //  Copyright  2016 . All rights reserved.
 ////
 //  main.cpp
 //  HYSBZ2038
 //
 //  Created by  on 16/1/24.
 //  Copyright  2016 . All rights reserved.
 //
 //
 //  main.cpp
 //  HYSBZ2038
 //
 //  Created by  on 16/1/24.
 //  Copyright  2016 . All rights reserved.
 //
 //
 //  main.cpp
 //  HYSBZ2038
 //
 //  Created by  on 16/1/24.
 //  Copyright  2016 . All rights reserved.
 //
 //
 //  main.cpp
 //  HYSBZ2038
 //
 //  Created by  on 16/1/24.
 //  Copyright  2016 . All rights reserved.
 //
 //
 //  main.cpp
 //  HYSBZ2038
 //
 //  Created by  on 16/1/24.
 //  Copyright  2016 . All rights reserved.
 //
 //
 //  main.cpp
 //  HYSBZ2038
 //
 //  Created by  on 16/1/24.
 //  Copyright  2016 . All rights reserved.
 //
 //
 //  main.cpp
 //  HYSBZ2038
 //
 //  Created by  on 16/1/24.
 //  Copyright  2016 . All rights reserved.
 //
 //
 //  main.cpp
 //  HYSBZ2038
 //
 //  Created by  on 16/1/24.
 //  Copyright  2016 . All rights reserved.
 //
 //
 //  main.cpp
 //  HYSBZ2038
 //
 //  Created by  on 16/1/24.
 //  Copyright  2016 . All rights reserved.
 //
 //
 //  main.cpp
 //  HYSBZ2038
 //
 //  Created by  on 16/1/24.
 //  Copyright  2016 . All rights reserved.
 //
 //
 //  main.cpp
 //  HYSBZ2038
 //
 //  Created by  on 16/1/24.
 //  Copyright  2016 . All rights reserved.
 //
 //
 //  main.cpp
 //  HYSBZ2038
 //
 //  Created by  on 16/1/24.
 //  Copyright  2016 . All rights reserved.
 //
 
 
 
 
*/