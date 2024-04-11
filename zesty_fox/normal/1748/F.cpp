// LUOGU_RID: 96126224
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

int n;
vi op;

void process(int s,int t){
    int len=(t+n-s)%n+1;
    for(int k=0;k<len/2;k++){
        for(int i=(t-k+n)%n;i!=(s+k)%n;i=(i+n-1)%n) 
            op.pb((i+n-1)%n);
        for(int i=(s+k+1)%n;i!=(t-k+n)%n;i=(i+1)%n)
            op.pb(i);
    }
    for(int k=0;k<(len-1)/2;k++)
        op.pb((s+k)%n);
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=rdi();

    process(0,n-1);
    if(n&1) process(n/2+1,n/2-1);
    else process(n/2,n/2-1);
    process(0,n-1);

    cout<<op.size()<<'\n';
    for(auto x:op) cout<<x<<' ';
    return 0;
}