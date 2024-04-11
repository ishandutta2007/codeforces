//#include <cstdio>
//#include <algorithm>
//#include <iostream>
//#include <cstring>
//#include <cmath>
//using namespace std;
//typedef double db;
//const db eps = 1e-8;
//
//inline int sign(db a){
//	return a < -eps ? -1 : a > eps;
//}
//
//struct P{
//	db x,y,z;
//	P(){}
//	P(db _x,db _y,db _z):x(_x),y(_y),z(_z){}
//	P operator + (P p) {return P(x + p.x,y + p.y,z + p.z);}
//	P operator - (P p) {return P(x - p.x,y - p.y,z - p.z);}
//	P operator * (db d){return P(x * d,y * d,z * d);}
//	db abs(){
//		return sqrt(x * x + y * y + z * z);
//	}
//	void read(){
//		cin >> x >> y >> z;
//	}
//}p[4];
//db r[2];
//int main(){
//	p[0].read();
//	cin >> r[0];
//	p[1].read();
//	p[2].read();
//	cin >> r[1];
//	p[3].read();
//	P v = p[2] - p[0];
//	v = v * (r[0] / (r[0] + r[1]));
//	P d = p[0] + v;
//	db ans = 2.0 * asin((p[1] - d).abs() / 2 / r[0]) * r[0] + 2.0 * asin((p[3] - d).abs() / 2 / r[1]) * r[1];
//	printf("%.4lf\n",ans);
//	return 0;
//}
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

const int maxn = 1e6 + 5;
vector<int> G[maxn];
int pre[maxn],lowlink[maxn],sccno[maxn],dfs_clock,scc_cnt;
stack<int> S;

void dfs(int u){
    pre[u] = lowlink[u] = ++dfs_clock;
    S.push(u);
    for(int i = 0;i < G[u].size();i++){
        int v = G[u][i];
        if(!pre[v]){
            dfs(v);
            lowlink[u] = min(lowlink[u],lowlink[v]);
        }else if(!sccno[v]){
            lowlink[u] = min(lowlink[u],pre[v]);
        }
    }
    if(lowlink[u] == pre[u]){
        scc_cnt++;
        for(;;){
            int x = S.top();S.pop();
            sccno[x] = scc_cnt;
            if(x == u) break;
        }
    }
}

int n,m;

struct edge{
    int u,v,w;
    edge(int u = 0,int v = 0,int w = 0):u(u),v(v),w(w){}
    void read(){
        scanf("%d%d%d",&u,&v,&w);
    }
}e[maxn];

long long cal(long long w){
    if(w == 0) return 0;
    if(w == 1) return 1;
    long long x = sqrt(w * 2) + 5;
    while(x * (x + 1) / 2 > w) x--;
    return (x + 1) * 1LL * w - 1LL * x * (x + 1) * (x + 2) / 6;
}

vector<pair<int,int> > g[maxn];
long long b[maxn];
long long dp[maxn];
int St;

long long Dp(int u){
    if(g[u].empty()) return b[u];
    long long & ret = dp[u];
    if(ret != -1) return ret;
    ret = 0;
    for(auto e : g[u]){
        ret = max(ret,Dp(e.first) + e.second);
    }
    ret += b[u];
    return ret;
}
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        e[i].read();
        G[e[i].u].push_back(e[i].v);
    }
    cin >> St;
    for(int i = 1;i <= n;i++){
        if(sccno[i] == 0){
            dfs(i);
        }
    }
    for(int i = 1;i <= m;i++){
        if(sccno[e[i].u] == sccno[e[i].v]){
            b[sccno[e[i].u]] += cal(e[i].w);
        }else{
            g[sccno[e[i].u]].push_back(make_pair(sccno[e[i].v],e[i].w));
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << Dp(sccno[St]) << endl;
    return 0;
}