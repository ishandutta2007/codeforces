#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define fo(i,x,y) for(register int i=x;i<=y;++i)
//for
#define go(i,x,y) for(register int i=x;i>=y;--i)
using namespace std;

inline int read(){//
    int x=0,fh=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') fh=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x*fh;
}

const int maxn=1e5+5;
int a[maxn],ans[maxn],cnt;
//aanscnt

inline void work(){
    int n=read();
    cnt=0;
    fo(i,1,n) a[i]=read();
    sort(a+1,a+1+n);//
    int k1=1,k2=n;//k1k2
    while(k1<k2){//
        ans[++cnt]=a[k1];
        ans[++cnt]=a[k2];
        k1++;//
        k2--;//
    }
    if(n&1) printf("%d ",a[(n+1)/2]);
   //n
    go(i,cnt,1) printf("%d ",ans[i]);//
    printf("\n");//
}

int main(){
    int T=read();//
    while(T--){
        work();
    }
    return 0;
}