#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using db=double;
using vi=vector<int>;
using pii=pair<int,int>;

template <typename T>
T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N=70;

i64 m,k;

int bit[N];
i64 f[N][N][2];
i64 dfs(int x,int c,bool lim=true){
    if(x<0) return !c;
    auto &val=f[x][c][lim];
    if(val!=-1) return val;
    val=0,val+=dfs(x-1,c,lim&&!bit[x]);
    if(c&&(!lim||bit[x])) val+=dfs(x-1,c-1,lim);
    return val;
}

const int L=63;

i64 count(i64 n,int k){
    memset(f,-1,sizeof(f));
    for(int i=0;i<L;i++) bit[i]=n>>i&1;
    return dfs(L-1,k);
}

int main(){
    m=rdi64(),k=rdi();
    i64 l=1,r=1e18;
    while(l<r){
        i64 mid=(l+r)/2;
        if(count(mid-1,k-1)>=m) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}