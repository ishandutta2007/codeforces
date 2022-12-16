#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=510,M=600010;

int n,m,q,res[M];
bitset<N> s[N];

struct Question{int x1,y1,x2,y2,id;};

bitset<N> f[N][N],g[N][N];
void solve(int up,int dw,const vector<Question> &q){
    if(q.empty()) return;
    int mid=(up+dw)/2;
    for(int j=1;j<=m;j++){
        f[mid][j].reset(),g[mid][j].reset();
        if(!s[mid][j]) f[mid][j][j]=1,g[mid][j][j]=1;
    }
    for(int i=mid;i>=up;i--){
        for(int j=m;j>=1;j--){
            if(i!=mid) f[i][j].reset();
            if(s[i][j]) continue;
            f[i][j]|=f[i][j+1];
            if(i!=mid) f[i][j]|=f[i+1][j];
        }
    }
    for(int i=mid;i<=dw;i++){
        for(int j=1;j<=m;j++){
            if(i!=mid) g[i][j].reset();
            if(s[i][j]) continue;
            g[i][j]|=g[i][j-1];
            if(i!=mid) g[i][j]|=g[i-1][j];
        }
    }
    vector<Question> q1,q2;
    for(auto cur:q){
        if(cur.x2<mid) q1.pb(cur);
        else if(cur.x1>mid) q2.pb(cur);
        else res[cur.id]=(f[cur.x1][cur.y1]&g[cur.x2][cur.y2]).any();
    }
    solve(up,mid-1,q1),solve(mid+1,dw,q2);
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++){
        static char buf[N];scanf("%s",buf+1);
        for(int j=1;j<=m;j++) s[i][j]=(buf[j]=='#');
    }
    q=rdi();vector<Question> Q;
    for(int i=1;i<=q;i++){
        int x1=rdi(),y1=rdi(),x2=rdi(),y2=rdi();
        Q.pb({x1,y1,x2,y2,i});
    }
    solve(1,n,Q);
    for(int i=1;i<=q;i++)
        puts(res[i]?"Yes":"No");
    return 0;
}