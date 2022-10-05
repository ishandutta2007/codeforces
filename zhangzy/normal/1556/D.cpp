#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const int N=1e4+5;
using namespace std;

int n,k,Or[N],And[N],a[N],or13,bit[N];

void doit(int c){
    rep(i,1,n)bit[i]=-1;
    rep(i,1,n-1){
        int orbit=(Or[i]>>c)&1;
        int andbit=(And[i]>>c)&1;
        if(orbit==0)bit[i]=bit[i+1]=0;else
        if(andbit==1)bit[i]=bit[i+1]=1;else{
            if(bit[i]!=-1)bit[i+1]=bit[i]^1;
        }
    }
    for(int i=n-1;i;--i){
        int orbit=(Or[i]>>c)&1;
        int andbit=(And[i]>>c)&1;
        if(orbit==0)bit[i]=bit[i+1]=0;else
        if(andbit==1)bit[i]=bit[i+1]=1;else{
            if(bit[i+1]!=-1)bit[i]=bit[i+1]^1;
        }
    }
    if(bit[1]==-1){
        int orbit=(or13>>c)&1;
        if(orbit==0){
            rep(i,1,n)bit[i]=(i&1)^1;
        }else{
            rep(i,1,n)bit[i]=(i&1);
        }
    }
    rep(i,1,n)a[i]+=(1<<c)*bit[i];
}

int main() {
    scanf("%d%d",&n,&k);
    rep(i,1,n-1){
        printf("or %d %d\n",i,i+1);
        fflush(stdout);
        scanf("%d", &Or[i]);
        printf("and %d %d\n",i,i+1);
        fflush(stdout);
        scanf("%d", &And[i]);
    }
    puts("or 1 3");
    fflush(stdout);
    scanf("%d",&or13);
    rep(i,1,n)a[i]=0;
    rep(i,0,30)doit(i);
    sort(a+1,a+n+1);
    printf("finish %d\n", a[k]);
    return 0;
}