#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int BIT=(1<<17),M=110,N=25;
int n,m,cnt[BIT],a[M];
ll f[BIT][N],b[N],p[N],year;
//f[i][j]
//i11~cnt[i](1)
//jxj
//b[i]i
void solve(int x){
    memset(f,0,sizeof(f));
    f[0][0]=1;int maxb=(1<<n);
    for(int i=0;i<maxb;i++){
        for(int j=0;j<=n;j++){
            int y=cnt[i]+1;
            if(b[y]){//
                if((a[b[y]]&i)!=a[b[y]]) continue;
                //continue
                if((1<<(b[y]-1)&i)==(1<<b[y]-1)) continue;
                //continue
                if(b[y]==x) f[i|(1<<b[y]-1)][y]+=f[i][j];
                else f[i|(1<<b[y]-1)][j]+=f[i][j];
            }
            else{
                for(int k=1;k<=n;k++){//cnt[y]+1
                    if(!(i&(1<<k-1))){
                        if((a[k]&i)!=a[k]) continue;
                        if(k==x) f[i|(1<<k-1)][y]+=f[i][j];
                        else f[i|(1<<k-1)][j]+=f[i][j];
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d%lld%d",&n,&year,&m);year-=2000;
    for(int i=1;i<BIT;i++) cnt[i]=cnt[i^(i&(-i))]+1;
    for(int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        a[y]|=(1<<x-1);
    }
    for(int i=1;i<=n;i++){
        solve(i);ll sum=0;
        for(int j=1;j<=n;j++){
            if(!b[j]&&sum+f[(1<<n)-1][j]>=year){
                b[j]=i;p[i]=j;
                year-=sum;break;
            }
            sum+=f[(1<<n)-1][j];
        }
        if(!p[i]){
            puts("The times have changed");
            return 0;
        }
    }
    for(int i=1;i<=n;i++) printf("%lld ",p[i]);
    puts("");
    return 0;
}