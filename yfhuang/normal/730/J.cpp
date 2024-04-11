#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
#define N 105

int f[N*N][N];
struct node{
    int x,y;
}a[N];

bool cmp(node a,node b){
    return a.y>b.y;
}

int main(){
    int n;
    scanf("%d",&n);
    int sum=0,V=0;
    for (int i=1;i<=n;i++) {scanf("%d",&a[i].x);sum+=a[i].x;}
    for (int i=1;i<=n;i++) {scanf("%d",&a[i].y);V+=a[i].y;}
    sort(a+1,a+n+1,cmp);
    int temp=0,m=0;
    for (int i=1;i<=n;i++){
        temp+=a[i].y;
        if (sum<=temp){
            m=i;
            break;
        }
    }
    memset(f,200,sizeof(f));
    f[0][0]=0;
    for (int i=1;i<=n;i++){
        for (int j=V;j>=a[i].y;j--){
            for (int k=m;k;k--){
                f[j][k]=max(f[j][k],f[j-a[i].y][k-1]+a[i].x);
            }
        }
    }
    int ans=0;
    for (int j=V;j>=sum;j--) ans=max(ans,f[j][m]);
    printf("%d %d\n",m,sum-ans);
    return 0;
}