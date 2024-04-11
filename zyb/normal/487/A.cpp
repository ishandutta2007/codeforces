#include<stdio.h>
#include<algorithm>
using namespace std;
struct node {
    int x,y,z;
}a,b,c;
int i,j,k,l,s,m,n,ans=10000000;
int main() {
    scanf("%d%d%d",&a.x,&a.y,&a.z);
    scanf("%d%d%d",&b.x,&b.y,&b.z);
    scanf("%d%d%d",&c.x,&c.y,&c.z);
    for (i=1;i<=100 ;i++) {
        int gt=b.z*i+b.x;
        int yy=gt/i+((gt%i)>0);
        if (yy>a.y) s=(yy-a.y)*c.y;
        else s=0;
        int gtw=b.y*i;
        int pp=10000000;
        for (j=0;j<=10000;j++) {
            int uu=gtw-a.x-j;
            if (uu<0) break;
            int uuu=uu/i+1;
            int rrrr=max(0,uuu-a.z);
            pp=min(pp,j*c.x+rrrr*c.z);
        }
        ans=min(ans,s+pp);
    }
    printf("%d\n",ans);
}