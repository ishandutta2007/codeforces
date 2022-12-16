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
 
int n,k,T;
int main(){
    T=rdi();
    while(T--){
        n=rdi(),k=rdi();
        int cnt=0,a[1010]={0};
        for(int i=k+1;i<=n;i++) a[++cnt]=i;
        for(int i=(k+1)/2;i<k;i++) a[++cnt]=i;
        printf("%d\n",cnt);
        for(int i=1;i<=cnt;i++) printf("%d ",a[i]);
        puts("");
    }
    return 0;
}