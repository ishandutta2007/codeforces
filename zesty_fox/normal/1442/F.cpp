#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int query(int x){
    cout<<"? 1 "<<x<<endl;
    string s;cin>>s;
    return s=="Lose"?-1:(s=="Draw"?0:1);
}

const int N=1010,S=20;

int n,m,T;
bitset<N> e[N];
int vis[(1<<S)+1];

int seq[N],ti,s;
void init(){
    static int deg[N];
    queue<int> q;
    for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++) deg[y]+=e[x][y];
    for(int x=1;x<=n;x++) if(!deg[x]) q.push(x);
    while(!q.empty()){
        int x=q.front();q.pop();
        seq[++ti]=x;
        for(int y=1;y<=n;y++)
            if(e[x][y]&&!(--deg[y])) q.push(y);
    }
    s=min(ti,20);
    vector<pair<bool,pii>> v;
    for(int i=n-s+1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            v.pb({true,{seq[i],seq[j]}});

    static int ord[(1<<S)+1];
    for(int i=0,tot=0;i<=s;i++)
        for(int j=0;j<(1<<s);j++)
            if(__builtin_popcount(j)==i) ord[tot++]=j;

    for(int i=1;i<=n-s;i++){
        int x=seq[i],t=0;
        v.pb({true,{x,x}});
        for(int j=0;j<s;j++)
            t|=e[x][seq[j+n-s+1]]<<j;
        for(int pos=0;pos<(1<<s);pos++){
            int i=ord[pos];
            if(!vis[t^i]){
                for(int j=0;j<s;j++){
                    if(!(i>>j&1)) continue;
                    v.pb({(t>>j&1)^1,{x,seq[j+n-s+1]}});
                }
                vis[t^i]=x;
                goto ed;
            }
        }
ed:     ;
    }
    
    cout<<v.size()<<endl;
    for(auto cur:v) cout<<(cur.fi?"+":"-")<<' '<<cur.se.fi<<' '<<cur.se.se<<endl;
}

int solve(){
    int mt=0;
    for(int i=0;i<s;i++){
        int cur=seq[n-s+1+i],res=query(cur);
        if(res==-1) return cur;
        else if(res==1) mt|=(1<<i);
    }
    return vis[mt];
}

int main(){
    n=rdi(),m=rdi(),T=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        e[x][y]=1;
    }
    init();
    while(T--){
        int res=solve();
        cout<<"! "<<res<<endl;
        
        string ver;cin>>ver;
        if(ver!="Correct") return 0;
    }
    return 0;
}