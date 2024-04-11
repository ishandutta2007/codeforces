#include<stdio.h>
int n,c[102],ans=0,a[102][2];
int main(){
    scanf("%d",&n);int p,q;
    while(getchar()!='\n');
    for(int i=1;i<=n;i++)c[i]=getchar()=='1',ans+=c[i];
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i][0],&a[i][1]);
    for(int i=1;i<=1000;i++){int cnt=0;
        for(int j=1;j<=n;j++)if(i>=a[j][1]&&(i-a[j][1])%a[j][0]==0)c[j]^=1;
        for(int j=1;j<=n;j++)cnt+=c[j];if(cnt>ans)ans=cnt;
    }printf("%d ",ans);
}