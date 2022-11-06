#include<stdio.h>
inline int Min(int p,int q){return p<q?p:q;}
int n,k,a[200002],b,g[22];
int dfs(int p,int *q){
    if(p>200000)return 1e9;
    int s[22],t[22];
    for(int i=0;i<=20;i++)s[i]=t[i]=0;
    int r=Min(dfs(p<<1,s),dfs(p<<1|1,t));
    for(int i=20;i>0;i--)q[i]=s[i-1]+t[i-1];
    q[0]=a[p];int ans=0,cnt=k;
    for(int i=0;i<=20;i++){
        ans+=Min(cnt,q[i])*i;
        cnt-=q[i];if(cnt<=0)break;
    }if(cnt>0)return 1e9;
    return Min(r,ans);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&b),a[b]++;
    printf("%d",dfs(1,g));
}