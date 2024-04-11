#include<bits/stdc++.h>
using namespace std;
int n,q,c;
int cnt[110][110][13];
int main(){
    scanf("%d%d%d",&n,&q,&c);
    int a,b,aa,bb,d,s,t,ans,tot;
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++){
        scanf("%d%d%d",&a,&b,&s);
        cnt[a][b][s]++;
    }
    for (int i=1;i<=100;i++){
        for (int j=2;j<=100;j++){
            for (int k=0;k<=c;k++){
                cnt[i][j][k]+=cnt[i][j-1][k];
            }
        }
    }
    for (int j=1;j<=100;j++){
        for (int i=2;i<=100;i++){
            for (int k=0;k<=c;k++){
                cnt[i][j][k]+=cnt[i-1][j][k];
            }
        }
    }
    
    while (q--){
        scanf("%d%d%d%d%d",&t,&a,&b,&aa,&bb);
        t%=(c+1);
        ans=0;
        for (int k=0;k<=c;k++){
            tot=cnt[aa][bb][k]-cnt[a-1][bb][k]-cnt[aa][b-1][k]+cnt[a-1][b-1][k];
            ans+=tot*((k+t)%(c+1));
        }
        printf("%d\n",ans);
    }
}