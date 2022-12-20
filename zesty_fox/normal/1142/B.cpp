#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010,INF=0x3f3f3f3f;
int n,m,Q,p[N],a[N],id[N],last[N];

int lg2[N],nxt[N][21];
void init_lg(){
    for(int i=2;i<=max(n,m);i++) lg2[i]=lg2[i>>1]+1;
}

void init(){
    for(int i=m;i>=1;i--){
        nxt[i][0]=last[p[id[a[i]]%n+1]];
        last[a[i]]=i;
    }
    for(int i=1;i<=lg2[n];i++){
        for(int j=1;j<=m;j++) 
            nxt[j][i]=nxt[nxt[j][i-1]][i-1];
    }
}

int minx[N][21];
void init_ST(){
    memset(minx,0x3f,sizeof(minx));
    for(int i=1;i<=m;i++){
        int x=i;
        for(int j=0;j<=lg2[n-1];j++){
            if((n-1)>>j&1) x=nxt[x][j];
        }
        minx[i][0]=x?x:INF;
    }
    for(int i=1;i<=lg2[m];i++){
        for(int j=1;j<=m-(1<<i)+1;j++){
            minx[j][i]=min(minx[j][i-1],minx[j+(1<<(i-1))][i-1]);
        }
    }
}

inline int query(int l,int r){
    int k=lg2[r-l+1];
    return min(minx[l][k],minx[r-(1<<k)+1][k]);
}

int main(){
    n=rdi(),m=rdi(),Q=rdi();init_lg();
    for(int i=1;i<=n;i++) p[i]=rdi(),id[p[i]]=i;
    for(int i=1;i<=m;i++) a[i]=rdi();
    init_lg();init();init_ST();
    while(Q--){
        int l=rdi(),r=rdi();
        putchar(query(l,r)<=r?'1':'0');
    }
    puts("");
    return 0;
}