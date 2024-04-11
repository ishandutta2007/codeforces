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
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n,m,q;
const int maxn = 5e5 + 5;
struct edge{
    int u,v,w;
    bool operator < (const edge & rhs) const{
        return w < rhs.w;
    }
}a[maxn],b[maxn];

struct query{
    int l,r,id,w;
    bool operator < (const query & rhs) const{
        return w < rhs.w;
    }
}c[maxn];int tot;

int fa[maxn],sz[maxn];

int getfa(int x){
    if(x == fa[x]) return x;
    return getfa(fa[x]);
}

pair<int,int> rep[maxn],rep2[maxn];
int tot1;

int Union(int x,int y,bool flag = 0){
    x = getfa(x);
    y = getfa(y);
    if(x == y) return 0;
    if(sz[x] < sz[y]) swap(x,y);
    if(flag){
        ++tot1;
        rep[tot1] = make_pair(y,y);
        rep2[tot1] = make_pair(x,sz[x]);
    }
    fa[y] = x;
    sz[x] += sz[y];
    return 1;
}

int ans[maxn];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
    }
    cin >> q;
    int t = 0;
    for(int i = 1;i <= q;i++){
        int k;
        scanf("%d",&k);
        ans[i] = 1;
        for(int j = 1;j <= k;j++){
            int id;
            scanf("%d",&id);
            b[t + j] = a[id];
        }
        sort(b + t + 1,b + t + 1 + k);
        for(int j = t + 1,j1 = j;j <= t + k;j = j1 + 1,j1 = j){
            while(j1 < t + k && b[j1 + 1].w == b[j].w) j1++;
            c[++tot].l = j;
            c[tot].r = j1;
            c[tot].id = i;
            c[tot].w = b[j].w;
        }
        t += k;
    }
    sort(a + 1,a + 1 + m);
    sort(c + 1,c + 1 + tot);
    int now = 0;
    for(int i = 1;i <= n;i++){
        fa[i] = i;
        sz[i] = 1;
    }
    for(int i = 1;i <= tot;i++){
        while(now < m && a[now + 1].w < c[i].w){
            int u = a[now + 1].u;
            int v = a[now + 1].v;
            Union(u,v);
            now++;
        }
        for(int j = c[i].l;j <= c[i].r;j++){
            if(!Union(b[j].u,b[j].v,1)){
                ans[c[i].id] = 0;
                break;
            }
        }
        while(tot1){
            fa[rep[tot1].first] = rep[tot1].second;
            sz[rep2[tot1].first] = rep2[tot1].second;
            tot1--;
        }
    }
    for(int i = 1;i <= q;i++){
        if(ans[i]) puts("YES");
        else puts("NO");
    }
    return 0;
}