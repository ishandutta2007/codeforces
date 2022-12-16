// LUOGU_RID: 93736244
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

const int N=3e5+10;

int n,a[N];

void init(){
    n=rdi();
    for(int i=1;i<=n;i++)
        scanf("%1d",&a[i]);
    if(count(a+1,a+n+1,1)*2>n){
        reverse(a+1,a+n+1);
        for(int i=1;i<=n;i++) a[i]^=1;
    }
}

int pos[N],c0[N];
void solve(){
    init();
    if(is_sorted(a+1,a+n+1)) puts("0");
    else{
        int sum=0;
        for(int i=1;i<=n;i++){
            sum=sum+(a[i]==0?1:-1);
            if(sum>=0) pos[sum]=i;
            c0[i]=c0[i-1]+(!a[i]);
        }
        for(int i=1;i<=n;i++) pos[i]=max(pos[i],pos[i-1]);
        int nw=0,res=0;
        while(nw<n&&!a[nw+1]) ++nw;
        while(nw<c0[n]){
            ++res;
            if(pos[nw]<=nw) break;
            else nw=c0[pos[nw]];
        }
        cout<<res<<'\n';
    }
    
    for(int i=0;i<=n;i++) c0[i]=pos[i]=0;
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}