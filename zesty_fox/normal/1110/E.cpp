#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdl read<ll>

const int N=100010;
int n,c[N],t[N],c1[N],t1[N];
int main(){
    n=rdi();
    for(int i=1;i<=n;i++) c[i]=rdi(),c1[i]=c[i]-c[i-1];
    for(int i=1;i<=n;i++) t[i]=rdi(),t1[i]=t[i]-t[i-1];
    if(c1[1]!=t1[1]) puts("No"),exit(0);
    sort(c1+1,c1+n+1);sort(t1+1,t1+n+1);
    if(memcmp(c1,t1,sizeof(int)*(n+2))==0) puts("Yes");
    else puts("No");
    return 0;
}