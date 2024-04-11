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

const db eps=1e-9;

int n,m;

db query(const vector<pair<db,db>> &poly){
    cout<<"? "<<poly.size()<<'\n';
    for(auto nw:poly) cout<<fixed<<setprecision(10)<<nw.fi<<' '<<nw.se<<'\n';
    cout<<flush;
    db ret;cin>>ret;
    return ret;
}
void answer(pair<db,db> res){
    cout<<"! "<<fixed<<setprecision(10)<<res.fi<<' '<<res.se<<endl;
}

int main(){
    n=rdi(),m=rdi();
    vector<pair<db,db>> p;
    p.pb({0,m}),p.pb({0,0});
    for(int i=1;i<n;i++) p.pb({i,m-eps}),p.pb({i,0});
    p.pb({n,m});
    db y=(2*query(p)*m-1)/2;p.clear();
    p.pb({n,0}),p.pb({0,0});
    for(int i=1;i<m;i++) p.pb({n-eps,i}),p.pb({0,i});
    p.pb({n,m});
    db x=(2*query(p)*n-1)/2;
    answer({x,y});
    return 0;
}