#include<stdio.h>
#include<algorithm>
int t,n,m,p[2002],q[15],tot,z[15][15],g[15],ans;
struct node{
    int val,x,y;
    bool operator<(const node &p)const{return p.val<val;}
}a[500002];
void dfs(int p){
    if(p>tot){
        int cnt=0;
        for(int i=1;i<=n;i++)cnt+=g[i];
        if(cnt>ans)ans=cnt;
        return;
    }int m[15];
    for(int i=1;i<=n;i++)m[i]=g[i];
    for(int i=1;i<=n;i++){
        for(int j=1,k=i;j<=n;j++,k++){
            if(g[j]<z[p][k])g[j]=z[p][k];
            if(k>=n)k-=n;
        }dfs(p+1);
        for(int j=1;j<=n;j++)g[j]=m[j];
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);tot=0;ans=0;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i*m+j].val),a[i*m+j].x=j+1,a[i*m+j].y=i+1;
        std::sort(a,a+n*m);int h=0;
        while(tot<n&&h<n*m){
            if(!p[a[h].x]){
                q[++tot]=a[h].x;
                p[a[h].x]=tot;
            }z[p[a[h].x]][a[h].y]=a[h].val;h++;
        }for(int i=1;i<=n;i++)g[i]=z[1][i];
        dfs(2);printf("%d\n",ans);
        for(int i=1;i<=tot;i++)for(int j=1;j<=n;j++)z[i][j]=0;
        for(int i=1;i<=tot;i++)p[q[i]]=0;
    }
}