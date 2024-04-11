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

const int N=610;

int n;

int T;
int query(const vi &v){
    if(v.size()<=1)
        return 0;
    ++T;
    cout<<"? "<<v.size()<<'\n';
    for(auto x:v) cout<<x<<' ';
    cout<<endl;
    return rdi();
}

int count(vi v1,vi v2){
    if(v1.empty()||v2.empty())
        return 0;
    int e1=query(v1),e2=query(v2);
    v1.insert(v1.end(),v2.begin(),v2.end());
    int e3=query(v1);
    return e3-e1-e2;
}

vi t[N];
int dep[N];
void bfs(int s){
    queue<int> q;
    dep[s]=1,q.push(s);
    auto get_edge = [&](auto &&self,int x,const vi &s,vi &res){
        if(!count({x},s))
            return;
        if(s.size()==1){
            res.pb(s[0]);
            return;
        }
        int mid=s.size()/2;
        self(self,x,vi(s.begin(),s.begin()+mid),res);
        self(self,x,vi(s.begin()+mid,s.end()),res);
    };
    while(!q.empty()){
        int x=q.front();q.pop();
        vi to,s;
        for(int i=1;i<=n;i++)
            if(!dep[i]) s.pb(i);
        get_edge(get_edge,x,s,to);
        for(auto y:to){
            dep[y]=dep[x]+1;
            t[x].pb(y),t[y].pb(x);
            q.push(y);
        }
    }
}

pii get_edge(int a[],int n){
    int mid=n/2;
    if(query(vi(a,a+mid)))
        return get_edge(a,mid);
    if(query(vi(a+mid,a+n)))
        return get_edge(a+mid,n-mid);
    int cnt=query(vi(a,a+n));
    int l=0,r=mid-1;
    while(l<r){
        int mid1=(l+r+1)/2;
        if(count(vi(a,a+mid1),vi(a+mid,a+n))!=cnt)
            l=mid1;
        else
            r=mid1-1;
    }
    int p=a[l];
    l=mid,r=n-1,cnt=count({p},vi(a+mid,a+n));
    while(l<r){
        int mid1=(l+r+1)/2;
        if(count({p},vi(a+mid,a+mid1))!=cnt)
            l=mid1;
        else
            r=mid1-1;
    }
    return {p,a[l]};
}

bool get_path(int x,int fa,int to,vi &res){
    res.pb(x);
    if(x==to) return true;
    for(auto y:t[x])
        if(y!=fa&&get_path(y,x,to,res)) return true;
    res.pop_back();
    return false;
}

vi d[N];
void solve(){
    bfs(1);
    for(int i=1;i<=n;i++)
        d[dep[i]].pb(i);
    for(int i=1;i<=n;i++){
        if(query(d[i])){
            pii p=get_edge(d[i].data(),d[i].size());
            vi nod;get_path(p.fi,0,p.se,nod);
            cout<<"N "<<nod.size()<<endl;
            for(auto x:nod) cout<<x<<' ';
            cout<<endl;
            return;
        }
    }

    vi nod;
    for(int i=1;i<=n;i+=2)
        nod.insert(nod.end(),d[i].begin(),d[i].end());
    cout<<"Y "<<nod.size()<<endl;
    for(auto x:nod) cout<<x<<' ';
    cout<<endl;
}

int main(){
    n=rdi();
    solve();
    return 0;
}