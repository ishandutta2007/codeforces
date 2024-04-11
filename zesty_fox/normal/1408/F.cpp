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

const int N=500010;
int n,st[N][2],pos;
void solve(int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1;
    solve(l,mid);solve(mid+1,r);
    for(int i=l;i<=mid;i++) st[++pos][0]=i,st[pos][1]=i+mid+1-l;
}

int main(){
    n=rdi();
    int k=1;for(;(k<<1)<n;k<<=1);
    solve(1,k);solve(n-k+1,n);
    printf("%d\n",pos);
    for(int i=1;i<=pos;i++) printf("%d %d\n",st[i][0],st[i][1]);
    return 0;
}