// LUOGU_RID: 95255711
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

const int N=1e5+10;
const i64 INFl=4e18;

int n,m;
set<pair<int,pii>> g[N],e1;
map<pii,int> e;

multiset<i64> s3;
i64 sum3[N];
pair<int,pii> lim3[N];

inline bool cross(pii a,pii b){
    return a.fi==b.fi||a.fi==b.se||a.se==b.fi||a.se==b.se;
}

i64 get_ans(){
    // 3 edges
    i64 ret=(s3.empty()?INFl:*s3.begin());
    // 2 edges
    if(!e1.empty()){
        auto it1=e1.begin(),it2=next(it1);
        while(it2!=e1.end()&&cross(it1->se,it2->se)) ++it2;
        if(it2!=e1.end()) ret=min(ret,(i64)it1->fi+it2->fi);
        auto lim=it2;
        for(it1=next(e1.begin());it1!=lim;it1++)
            for(it2=next(it1);it2!=lim;it2++)
                if(!cross(it1->se,it2->se)){
                    ret=min(ret,(i64)it1->fi+it2->fi),lim=it2;
                    break;
                }
    }
    return ret;
}

pair<int,pii> get_limit(int x){
    if(g[x].size()<3) return {INT_MAX,{0,0}};
    else return *next(g[x].begin(),2);
}

void pop(int x){
    if(g[x].size()>=3) s3.erase(s3.find(sum3[x]));
    auto it=g[x].begin();
    for(int i=1;i<=3&&it!=g[x].end();i++,it++)
        e1.erase(*it);
}

void push(int x){
    auto it=g[x].begin();
    sum3[x]=0;
    for(int i=1;i<=3&&it!=g[x].end();i++,it++){
        sum3[x]+=it->fi;int x1=it->se.fi,y1=it->se.se;
        if(*it<=min(lim3[x1],lim3[y1])) e1.insert(*it);
    }

    if(g[x].size()>=3) s3.insert(sum3[x]);
}

void ins(int x,int y,int w){
    if(x>y) swap(x,y);
    e[{x,y}]=w;
    pop(x),pop(y);
    g[x].insert({w,{x,y}}),g[y].insert({w,{x,y}});
    lim3[x]=get_limit(x),lim3[y]=get_limit(y);
    push(x),push(y);
}

void del(int x,int y){
    if(x>y) swap(x,y);
    int w=e[{x,y}];
    pop(x),pop(y);
    g[x].erase({w,{x,y}}),g[y].erase({w,{x,y}});
    lim3[x]=get_limit(x),lim3[y]=get_limit(y);
    push(x),push(y);
    e.erase({x,y});
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi(),w=rdi();
        ins(x,y,w);
    }
    cout<<get_ans()<<'\n';
    int q=rdi();
    while(q--){
        int op=rdi();
        if(op==0){
            int x=rdi(),y=rdi();
            del(x,y);
        }
        else{
            int x=rdi(),y=rdi(),w=rdi();
            ins(x,y,w);
        }
        cout<<get_ans()<<'\n';
    }
    return 0;
}