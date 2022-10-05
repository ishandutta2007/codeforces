#include<bits/stdc++.h>
using namespace std;

int tot,n,an0,an1,t,l,r,mid;

void que(int x,int fl){
    printf("? ");for (int i=1;i<=n;i++) printf("%c",i<=x?'0':'1');printf("\n");
    fflush(stdout);
    scanf("%d",&t);
    if (fl) t=(tot+t-n+x)>>1;
}

int main(){
    scanf("%d",&n);
    que(n,0);
    tot=t;
    que(1,1);
    if (t){
        for (l=2,r=n;l<r;t==mid?l=mid+1:r=mid){
            que(mid=(l+r)/2,1);
        }
        while (1){
            que(l,1);
            if (t==l) l++;
            else break;
        }
        printf("! %d %d\n",l,1);
    }else{
        for (l=2,r=n;l<r;t==0?l=mid+1:r=mid){
            que(mid=(l+r)/2,1);
        }
        while (1){
            que(l,1);
            if (t==0) l++;
            else break;
        }
        printf("! %d %d\n",1,l);
    }
    fflush(stdout);
}