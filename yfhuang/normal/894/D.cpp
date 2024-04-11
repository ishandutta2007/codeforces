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

using namespace std;

int n,m;
const int maxn = 1e6 + 5;

typedef long long LL;
LL l[maxn];
LL a[maxn],h[maxn];
vector<LL> G[maxn];
vector<LL> sum[maxn];
vector<LL> dfs(int u){
    if(u > n) return vector<LL>(0);
    G[u].push_back(0);
    vector<LL> a = dfs(u * 2);
    vector<LL> b = dfs(u * 2 + 1);
    for(int i = 0;i < a.size();i++){
        a[i] += l[2 * u];
    }
    for(int i = 0;i < b.size();i++){
        b[i] += l[2 * u + 1];
    }
    int front1 = 0,front2 = 0;
    while(front1 < a.size() && front2 < b.size()){
        if(a[front1] < b[front2]){
            G[u].push_back(a[front1]);
            front1++;
        }else{
            G[u].push_back(b[front2]);
            front2++;
        }
    }
    while(front1 < a.size()){
        G[u].push_back(a[front1]);
        front1++;
    }
    while(front2 < b.size()){
        G[u].push_back(b[front2]);
        front2++;
    }
    for(int i = 0;i < G[u].size();i++){
        if(i == 0) sum[u].push_back(G[u][i]);
        else sum[u].push_back(G[u][i] + sum[u][i - 1]);
    }
    return G[u];
}

LL solve(int u,LL h){
    LL id = upper_bound(G[u].begin(),G[u].end(),h) - G[u].begin();
    id--;
    if(id < 0) return 0;
    return 1LL * h * (id + 1) - sum[u][id];
}



int main(){
    cin >> n >> m;
    for(int i = 2;i <= n;i++){
        scanf("%lld",l + i);
    }
    dfs(1);
    for(int i = 1;i <= m;i++){
        scanf("%lld%lld",a + i,h + i);
        LL ans = 0;
        ans += solve(a[i],h[i]);
        int last = a[i];
        a[i] /= 2;
        h[i] -= l[last];
        while(a[i] > 0){
           if(h[i] < 0) break;
            ans += solve(a[i],h[i]);
            ans -= solve(last,h[i] - l[last]);
            last = a[i];
            a[i] /= 2;
            h[i] -= l[last];
        }
        printf("%lld\n",ans);
    }
    return 0;
}