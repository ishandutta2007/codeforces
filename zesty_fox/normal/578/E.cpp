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

const int N=100010;

int n;
char s[N];

struct Node{
    vi seq;
    int st,ed;
    int& operator [] (const int &index) {return seq[index];}
};
vector<Node> p;
void find_path(){
    set<int> pos[2];
    for(int i=1;i<=n;i++) pos[s[i]=='R'].insert(i);
    while(pos[0].size()||pos[1].size()){
        if(!pos[0].size()){
            p.pb({{*pos[1].begin()},1,1});
            pos[1].erase(pos[1].begin());
            continue;
        }
        else if(!pos[1].size()){
            p.pb({{*pos[0].begin()},0,0});
            pos[0].erase(pos[0].begin());
            continue;
        }
        int st0=*pos[0].begin(),st1=*pos[1].begin();
        int st=min(st0,st1),now=(st0>st1);
        p.pb({{st},now,now}),pos[now].erase(st);
        while(true){
            auto nxt=pos[now^1].upper_bound(st);
            if(nxt==pos[now^1].end()) break;
            st=*nxt,now^=1,p.back().seq.pb(st),p.back().ed=now;
            pos[now].erase(st);
        }
    }
}

vi typ[2][2],res;
deque<int> seq;
void construct(){
    for(int i=0;i<(int)p.size();i++) typ[p[i].st][p[i].ed].pb(i);
    if(typ[0][1].size()){
        int st=typ[0][1][0];
        for(int i=1;i<(int)typ[0][1].size();i++){
            auto tmp=typ[0][1][i];
            p[st].seq.insert(p[st].seq.end(),p[tmp].seq.begin(),p[tmp].seq.end());
        }
        typ[0][1].resize(1);
    }
    if(typ[1][0].size()){
        int st=typ[1][0][0];
        for(int i=1;i<(int)typ[1][0].size();i++){
            auto tmp=typ[1][0][i];
            p[st].seq.insert(p[st].seq.end(),p[tmp].seq.begin(),p[tmp].seq.end());
        }
        typ[1][0].resize(1);
    }
    if(typ[0][1].size()&&typ[1][0].size()){
        int x=typ[0][1][0],y=typ[1][0][0];
        if(p[x].seq.back()<p[y].seq.back()) p[x].seq.pb(p[y].seq.back()),p[y].seq.pop_back();
        else p[y].seq.pb(p[x].seq.back()),p[x].seq.pop_back();
        p[x].ed^=1,p[y].ed^=1;
        typ[0][1].pop_back(),typ[0][0].pb(x);
        typ[1][0].pop_back(),typ[1][1].pb(y);
    }

    int now=(typ[1][1].size()!=typ[0][0].size()?typ[1][1].size()>typ[0][0].size():typ[1][0].size());
    while(1){
        if(typ[now][now].empty()) break;
        seq.pb(typ[now][now].back()),typ[now][now].pop_back();
        now^=1;
    }
    if(typ[0][1].size()) (seq.empty()||p[seq.front()].st?seq.pb(typ[0][1].front()):seq.push_front(typ[0][1].front()));
    if(typ[1][0].size()) (seq.empty()||p[seq.front()].st?seq.push_front(typ[1][0].front()):seq.pb(typ[1][0].front()));
    for(auto x:seq)
        for(auto y:p[x].seq) res.pb(y);
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    scanf("%s",s+1);
    n=strlen(s+1);find_path();
    cout<<p.size()-1<<'\n';
    construct();assert(res.size()==n);
    for(auto x:res) cout<<x<<' ';
    cout<<'\n';
    return 0;
}