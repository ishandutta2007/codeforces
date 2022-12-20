#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<ll,ll,ll> plll;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define mp make_pair

const int N=6010;
const ll INF=0x3f3f3f3f3f3f3f3f;

enum Color{red,blue,green};

struct Animal{
    array<int,3> k;
    int id,pos,nxt;
    Color c;
    int& operator [] (const int &id) {return k[id];}
};
vector<Animal> a,b;

int n;
pll ans;

void bf(){
    deque<Animal> q(a.begin()+1,a.end());
    const int lim=2e4;
    Animal cur=a[0];int cnt=0;
    for(int x=1;x<=lim;x++){
        auto now=q[0];q.pop_front();
        if(cur[cnt]>now[0]) ++cnt,q.pb(now);
        else cnt=1,swap(cur,now),q.pb(now);
        if(cnt==3) cout<<cur.id<<' '<<x<<endl,exit(0);
    } 
}

vector<plll> st;
vector<pll> reds;
void insert(ll b,ll bpos,ll pos){
    while(!st.empty()&&get<0>(st.back())>=b) st.ppb();
    st.pb({b,bpos,pos});
}

int main(){
    n=rdi();a.resize(n);
    for(int i=0;i<n;i++){
        for(int j:{0,1,2}) a[i][j]=rdi();
        a[i].id=i,a[i].c=blue,a[i].nxt=-1;
    }
    bf();
    if(a[0][0]>a[1][0]) swap(a[0],a[1]);
    a.pb(a[0]),a.erase(a.begin());
    for(int i=1;i<n;i++)
        if(a[i-1][1]>a[i][0]) a[i].c=red;

    for(int i=0;i<n;i++){
        a[i].pos=i;
        if(a[i].c==red) continue;
        int nxt=(i+1)%n;
        if(a[nxt].c==red) nxt=(nxt+1)%n;
        a[i].c=(a[i][2]>a[nxt][0]?green:blue);
    }

    a.pb(a[0]);
    for(int i=0;i<n;i++){
        if(a[i].c==red) continue;
        if(a[i+1].c==red) a[i].nxt=a[i+1].pos;
        b.pb(a[i]);
    }

    ll sum=0;
    while(1){
        st.clear(),reds.clear();

        for(int i=0;i<(int)b.size();i++){
            auto now=b[i];
            insert((now.c==blue?now[1]:-INF),now.pos,i);
        }

        ll minx=INF;
        for(int i=0;i<(int)b.size();i++){
            auto now=b[i];
            insert((now.c==blue?now[1]:-INF),now.pos,i);
            int nxtr=now.nxt;
            if(nxtr==-1) continue;
            reds.pb({nxtr,i});
            auto pos=lower_bound(st.begin(),st.end(),(plll){a[nxtr][0],-1,-1});
            if(pos==st.begin()) continue;
            pos--;
            ll dis=i-get<2>(*pos);
            if(dis<0) dis+=b.size();
            minx=min(minx,dis);
        }
        if(minx>=INF) return puts("-1 -1"),0;
        else if(minx){
            sum+=minx*(n-1);
            for(auto now:reds) b[now.se].nxt=-1;
            for(auto now:reds){
                int pos=now.se-minx;
                if(pos<0) pos+=b.size();
                b[pos].nxt=now.fi;
            }
        }

        ans={INF,INF};
        for(int i=0;i<(int)b.size();i++){
            if(b[i].nxt==-1) continue;
            auto nxt=a[b[i].nxt];
            if(b[i][1]<nxt[0]){
                b[i].nxt=-1,b.insert(b.begin()+i+1,nxt);
                b[i].c=b[i][2]>nxt[0]?green:blue;
                int nnxt=i+2;
                if(nnxt==b.size()) nnxt=0;
                b[i+1].c=b[i+1][2]>b[nnxt][0]?green:blue;
            }
            else if(b[i].c==green) ans=min(ans,{sum+nxt.pos+2,b[i].id});
        }
        if(ans.fi!=INF) return cout<<ans.se<<' '<<ans.fi<<'\n',0;
    }
    return 0;
}