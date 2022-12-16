#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
#define N 100010
int n,m;
char s[N];
#define Z 7
long long F[N][Z+2];
inline int get_bit(int x,int v){
    return (x>>v)&1;
}
int Ans[Z];
int main(){
    scanf("%d%d",&n,&m);m--;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)s[i]-='a';s[n+1]=-1;
    for(int i=0;i<=m;i++){
        int Tmp=1;
        if(i==s[1])Tmp|=2;
        if(i==s[1]||i==s[2])Tmp|=4;
        F[1][Tmp]++;
    }for(int i=2;i<=n;i++){
        for(int j=0;j<=Z;j++){
            int d[4]={i-3+get_bit(j,0),i-2+get_bit(j,1),i-2+get_bit(j,2),0};
            for(int k=0;k<=m;k++){
                memset(Ans,0,sizeof(Ans));
                for(int l=1;l<=3;l++){
                    if(s[i-2+l]==k)Ans[l]=d[l-1]+1;
                    else Ans[l]=max(Ans[l-1],d[l]);
                }
                if(Ans[1]>=i-2&&min(Ans[2],Ans[3])>=i-1)F[i][(Ans[1]-(i-2))|((Ans[2]-(i-1))<<1)|((Ans[3]-(i-1))<<2)]+=F[i-1][j];
            }
        }
    }printf("%I64d\n",F[n][0]+F[n][1]+F[n][4]+F[n][5]);
}