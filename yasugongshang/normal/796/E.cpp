#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#define lc root<<1
#define rc root<<1|1
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define reg(i,x) for(int i=first[x];i;i=next[i])
using namespace std;
typedef long long LL;
const int MAXN = 1002;
int n,p,k,a[MAXN],b[MAXN],ans;
int n1,n2,f[2][MAXN][52][52];
inline void upd(int &x,int y){ if(y>x) x=y; }
inline int getint() {
    int w=0,q=0; char c=getchar(); while((c<'0'||c>'9') && c!='-') c=getchar();
    if(c=='-') q=1,c=getchar(); while (c>='0'&&c<='9') w=w*10+c-'0',c=getchar(); return q?-w:w;
}
 
inline void work(){
    n=getint(); p=getint(); k=getint();
    n1=getint(); for(int i=1;i<=n1;i++) a[getint()]++;
    n2=getint(); for(int i=1;i<=n2;i++) b[getint()]++;
    int lim=n/p; if(n%p!=0) lim++; lim<<=1;
    if(k>=lim) {
        for(int i=1;i<=n;i++) ans+=a[i]|b[i];
        printf("%d",ans);
        return ;
    }
 
    memset(f,-0x3f,sizeof(f));
 
    f[0][0][0][0]=0; int to,tag=1;
    for(int i=1;i<=n;i++) {
        to=tag; memset(f[to],-0x3f,sizeof(f[to]));
        tag^=1;
        for(int j=0;j<=p;j++) {
            for(int ii=0;ii<=k;ii++) {
                for(int jj=0;jj<=k;jj++) {
                    if(!ii && !jj) {
                        upd(f[to][j][0][0],f[tag][j][0][0]);
                        upd(f[to][j+1][k-1][0],f[tag][j][0][0]+a[i]);
                        upd(f[to][j+1][0][k-1],f[tag][j][0][0]+b[i]);
                        upd(f[to][j+2][k-1][k-1],f[tag][j][0][0]+(a[i]|b[i]));
                    }
                    else if(!ii) {
                        upd(f[to][j][0][jj-1],f[tag][j][0][jj]+b[i]);
                        upd(f[to][j+1][k-1][jj-1],f[tag][j][0][jj]+(a[i]|b[i]));
                        upd(f[to][j+2][k-1][k-1],f[tag][j][0][jj]+(a[i]|b[i]));
                    }
                    else if(!jj) {
                        upd(f[to][j][ii-1][0],f[tag][j][ii][0]+a[i]);
                        upd(f[to][j+1][ii-1][k-1],f[tag][j][ii][0]+(a[i]|b[i]));
                        upd(f[to][j+2][k-1][k-1],f[tag][j][ii][0]+(a[i]|b[i]));
                    }
                    else upd(f[to][j][ii-1][jj-1],f[tag][j][ii][jj]+(a[i]|b[i]));
                }
            }
        }
    }
    tag^=1;
    for(int l=0;l<=p;l++)
        for(int i=0;i<=k;i++)
            for(int j=0;j<=k;j++)
                ans=max(ans,f[tag][l][i][j]);
    printf("%d",ans);
 }
 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("796.in","r",stdin);
    freopen("796.out","w",stdout);
#endif
    work();
    return 0;
}