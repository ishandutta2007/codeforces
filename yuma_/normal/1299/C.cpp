#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<stack>
#include<complex>
#include<memory>
#include<numeric>
/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
    
using namespace std;
    
using ll=long long;
using ld =long double;
    
#define WHATS(var)cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
    
template<class S, class T> ostream& operator <<(ostream &os, const pair<S, T> v){
    os << "( " << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<T> &v){
    for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<vector<T>> &v){
    for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<set<T>> &v){
    for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const set<T> &v){
    int i=0;
    for(auto it:v){
        if(i > 0){os << ' ';}
        os << it;
        i++;
    } 
    return os;
}
class Tree {
public:
    Tree(int V, int root) : V(V), root(root), cnum(V), place(V), id(V) {
        T.resize(V);
        for (int i = 0; i < MAXLOGV; i++) {
            parent[i].resize(V);
        }
        depth.resize(V);
    }
    // uv
    // lcaIOt
    void unite(int u, int v) {
        T[u].push_back(v);
        T[v].push_back(u);
    }
    // init
    // RXgN^lca
    void init() {
        dfs(root, root, 0);
        int id = 0;
        getid(root, root, id);
    }
    // uvlca
    int lca(int u, int v) const {
        if (depth[u] > depth[v]) swap(u, v);
        for (int k = 0; k < MAXLOGV; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if (u == v) return u;
        for (int k = MAXLOGV - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
    // uv
    // edge`_
    int dist(int u, int v) const {
        int p = lca(u, v);
        return (depth[u] - depth[p]) + (depth[v] - depth[p]);
    }
    int dfs(int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        cnum[v] = 0;
        for (int i = 1; i < MAXLOGV; i++) {
            parent[i][v] = parent[i - 1][parent[i - 1][v]];
        }
        for (int next : T[v]) {
            if (next != p) cnum[v] += dfs(next, v, d + 1);
        }
        return cnum[v] + 1;
    }
    
    void getid(const int v, const int p, int &nplace) {
        place[v] = nplace;
        id[nplace] = v;
        nplace++;
        for (int next : T[v]) {
            if (next != p) getid(next, v, nplace);
        }
    }
    static const int MAXLOGV = 25;
    // OtXg\
    vector<vector<int> > T;
    // _
    int V;
    // m[h
    int root;
    
    // em[h
    vector<int> parent[MAXLOGV];
    // [
    vector<int> depth;
    
    //q
    vector<int>cnum;
    
    //
    vector<int>place;
    vector<int>id;
    
};
    
struct query{
    int l;
    int r;
    int c;
    
};
bool operator<(const query&l,const query&r){
    return l.c>r.c;
}
    
struct Edge{
    int src;
    int dst;
    int id;
};
using Graph=vector<vector<Edge>>;
Graph graph;
vector<int>get_root(int s,int t){
    vector<pair<int,int>>comes(graph.size(),make_pair(-1,-1));
    queue<int>que;
    que.emplace(s);
    while(!que.empty()){
        int now=que.front();
        que.pop();
        for(auto e:graph[now]){
            if(comes[e.dst].first==-1){
                comes[e.dst]=make_pair(e.src,e.id);
                que.emplace(e.dst);
            }
        }
    }
    assert(comes[t].first!=-1);
    int now=t;
    vector<int>roots;
    while(now!=s){
        roots.push_back(comes[now].second);
        now=comes[now].first;
    }
    return roots;
}
    vector<vector<int>>sums(int(2e5)+1,vector<int>(26));
    
vector<int>aget(int l,int r){
    vector<int>v(26);
    for(int i=0;i<26;++i){
        v[i]=sums[r][i]-sums[l][i];
    }
    sort(v.begin(),v.end(),greater<int>());
    while(!v.empty()&&v.back()==0)v.pop_back();
    return v;
}
    
struct aUnionFind {
    vector<pair<int, long long int>> data;
    aUnionFind(int size) : data(size, make_pair(-1, 0)) { }
    
    //y is w bigger than x
    bool unionSet(const int x, const int y, const long long int w) {
        const int rx(root(x).first), ry(root(y).first);
        if (rx != ry) {
            data[rx].first += data[ry].first; data[ry].first = rx;
            data[ry].second = (w + data[x].second - data[y].second+8)%2;
            return true;
        }
        else {
            return root(x).second + w == root(y).second;
        }
    }
    bool findSet(const int x, const int y) {
        return root(x) == root(y);
    }
    
    //x is belong to first
    //x is second bigger than first
    pair<int, long long int> root(const int x) {
        if (data[x].first < 0) {
            return make_pair(x, 0);
        }
        else {
            pair<int, long long int>ndata;
            ndata.first = root(data[x].first).first;
            ndata.second = (8+data[x].second + root(data[x].first).second)%2;
            return data[x] = ndata;
        }
    }
    int root2(const int x){
        return root(x).first;
    }
    int size(const int x) {
        return -data[root(x).first].first;
    }
};
    
ll nanswer=0;
void add(pair<ll,ll>p,ll mul){
    // WHATS(p)
    // WHATS(mul)
    nanswer+=min(p.first,p.second)*mul;
}
    
int main() {
    int N;cin>>N;
    vector<ld>answer(N);
    stack<pair<ld,int>>sta;
    for(int i=0;i<N;++i){
        int a;scanf("%d",&a);
        pair<ld,int>p(a,1);
        while(!sta.empty()&&sta.top().first>p.first){
            ld sum=p.first*p.second+sta.top().first*sta.top().second;
            int num=p.second+sta.top().second;
            sta.pop();
            p=make_pair(sum/num,num);
        }
        {
            sta.emplace(p);
        }
    }
    int now=N-1;
    while(!sta.empty()){
        auto p=sta.top();
        sta.pop();
        for(int i=0;i<p.second;++i){
            answer[now]=p.first;
            now--;
        }
    }
    //WHATS(answer)
    for(int i=0;i<N;++i){
        
        printf("%.12lf\n",double(answer[i]));
    }
    
    return 0;
}