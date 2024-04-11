//
//  main.cpp
//  b
//
//  Created by  on 16/3/4.
//  Copyright  2016 . All rights reserved.
//

/*#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m,k;

const int maxn=5005;

int grid[maxn][maxn];

int main(int argc, const char * argv[]) {
    scanf("%d%d%d",&n,&m,&k);
    memset(grid,0,sizeof(grid));
    for(int i=1;i<=k;i++){
        int type,x,a;
        scanf("%d%d%d",&type,&x,&a);
        if(type==1){
            for(int j=1;j<=m;j++){
                grid[x][j]=a;
            }
        }else{
            for(int j=1;j<=n;j++){
                grid[j][x]=a;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d%c",grid[i][j],j==m?'\n':' ');
        }
    }
    return 0;
}*/
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
#define sch(s) scanf("%s",s)
#define fillfalse(v) memset(v,false,sizeof(v))
#define filltrue(v) memset(v,true,sizeof(v))
#define Fill0(a)    memset(a,0,sizeof(a))
#define Fillplus(a)    memset(a,-1,sizeof(a))
#define lowbit(x) x&(-x)
using namespace std;
const int maxn=5000+5;
struct app{
    int t,c;
    
};
int i,j,k,n,m,l,x,y,z;
app r[maxn];
app c[maxn];
int main() {
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        scanf("%d%d%d",&x,&y,&z);
        if (x==1) {r[y].t=i; r[y].c=z;}
        else {c[y].t=i; c[y].c=z;}
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        {
            if (r[i].t==0&&c[j].t==0) printf("0");
            if (r[i].t<c[j].t) printf("%d",c[j].c);
            if (r[i].t>c[j].t) printf("%d",r[i].c);
            if (j!=m) printf(" ");
        }
        printf("\n");
    }
}