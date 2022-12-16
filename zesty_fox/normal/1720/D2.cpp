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

template<typename T>
inline void ckmax(T &a,const T &b) {if(a<b) a=b;}

const int N=300010;

struct Trie{
    static const int D=30;
    struct Node{
        int ch[2],mx[2][2];
    }t[N*D];
    int tot,rt;
    int new_n() {t[++tot]={{0},{0}};return tot;}
    void clear() {tot=rt=0;}
    void insert(int &nw,int id,int v,int f,int d=D-1){
        if(!nw) nw=new_n();
        if(d<0) return;
        ckmax(t[nw].mx[id>>d&1][v>>d&1],f);
        insert(t[nw].ch[(id^v)>>d&1],id,v,f,d-1);
    }
    int query(int nw,int id,int v,int d=D-1){
        if(!nw||d<0) return 0;
        int ret=t[nw].mx[(v>>d&1)^1][id>>d&1];
        return max(ret,query(t[nw].ch[(id^v)>>d&1],id,v,d-1));
    }
}t;

int n;
void solve(){
    t.clear();

    n=rdi();int ans=0;
    for(int i=0;i<n;i++){
        int x=rdi();
        int f=t.query(t.rt,i,x)+1;
        ans=max(ans,f),t.insert(t.rt,i,x,f);
    }
    cout<<ans<<'\n';
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}