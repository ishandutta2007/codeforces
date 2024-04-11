#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 110, BAS = 233, MP = 20;
typedef unsigned long long ull;
struct edge {
  int la,b;
  char v;
} con[N << 1];
int tot,fir[N],n,q;
void add(int from,int to,char val) {
  con[++tot] = (edge) {fir[from],to,val};
  fir[from] = tot;
}
ull val[N][M],nowv[N];
int anc[N][MP],dep[N],rt[N],ans[N];
void dfs(int pos,int fa) {
  dep[pos] = dep[fa] + 1;
  for (int i = 2, j = fa ; i <= 100 ; ++ i, j = anc[j][0])
    val[pos][i] = val[pos][i-1] * BAS + val[j][1];
  anc[pos][0] = fa;
  for (int i = 1 ; i < MP ; ++ i) {
    anc[pos][i] = anc[anc[pos][i-1]][i-1];
    if (!anc[pos][i]) break;
  }
  for (int i = fir[pos] ; i ; i = con[i].la) {
    if (con[i].b == fa) continue;
    val[con[i].b][1] = con[i].v - 'a';
    dfs(con[i].b,pos);
  }
}
int lca(int x,int y) {
  if (dep[x] < dep[y]) swap(x,y);
  for (int i = MP - 1 ; i >= 0 ; -- i)
    if (dep[anc[x][i]] >= dep[y])
      x = anc[x][i];
  if (x == y) return x;
  for (int i = MP - 1 ; i >= 0 ; -- i)
    if (anc[x][i] != anc[y][i])
      x = anc[x][i], y = anc[y][i];
  return anc[x][0];
}
int la(int x,int k) {
  for (int i = MP - 1 ; i >= 0 ; -- i)
    if ((k >> i)&1) x = anc[x][i];
  return x;
}
string str;
struct data {
  int u,v,id;
  string s;
};
vector<data> vec[M];
void init(int u,int v,int id) {
  cin >> str;
  vec[str.size()].push_back((data) {u,v,id,str});
}
vector<ull> tmp;
struct node {
  int sum,ls,rs;
} t[N * 50];
int cnt,m;
void update(int& x,int y,int p,int lp=1,int rp=m) {
  x = ++cnt, t[x] = t[y], ++ t[x].sum;
  if (lp == rp) return;
  int mid = (lp + rp) >> 1;
  if (p <= mid) update(t[x].ls,t[y].ls,p,lp,mid);
  else update(t[x].rs,t[y].rs,p,mid+1,rp);
}
int query(int p,int x,int px,int lp=1,int rp=m) {
  if (lp == rp) return t[x].sum-t[px].sum;
  int mid = (lp + rp) >> 1;
  if (p <= mid) return query(p,t[x].ls,t[px].ls,lp,mid);
  else return query(p,t[x].rs,t[px].rs,mid+1,rp);
}
ull dval[M],rval[M];
int solve(data que) {
  int ret = 0;
  int z = lca(que.u,que.v), l = que.s.size();
  dval[0] = 0;
  for (int i = 0 ; i < l ; ++ i)
    dval[i+1] = dval[i] * BAS + que.s[i] - 'a';
  rval[0] = 0;
  for (int i = 0 ; i < l ; ++ i)
    rval[i+1] = rval[i] * BAS + que.s[l-i-1] - 'a';
  if (dep[que.u] - dep[z] >= l) {
    do {
      int v = lower_bound(tmp.begin(),tmp.end(),dval[l]) - tmp.begin() + 1;
      if (v > m || dval[l] != tmp[v-1]) break;
      ret += query(v,rt[que.u], rt[la(que.u,dep[que.u]-dep[z]-l+1)]);
    } while (0);
  }
  if (dep[que.v] - dep[z] >= l) {
    do {
      int v = lower_bound(tmp.begin(),tmp.end(),rval[l]) - tmp.begin() + 1;
      if (v > m || rval[l] != tmp[v-1]) break;
      ret += query(v,rt[que.v], rt[la(que.v,dep[que.v]-dep[z]-l+1)]);
    } while (0);
  }
  for (int i = la(que.u,max(0,dep[que.u]-dep[z]-l+1)), j ; i != z ; i = anc[i][0]) {
    int step = dep[que.v] - dep[z] - (l - (dep[i] - dep[z]));
    if (step < 0) continue;
    j = la(que.v,step);
    if (val[i][dep[i]-dep[z]] == dval[dep[i]-dep[z]] && val[j][dep[j]-dep[z]] == rval[dep[j]-dep[z]]) ++ ret;
  }
  return ret;
}
void clear() {
  tmp.clear();
//  memset(t,0,sizeof(node) * (cnt+5));
  cnt = 1;
}
void fsd(int pos) {
  update(rt[pos],rt[anc[pos][0]],nowv[pos]);
  for (int i = fir[pos] ; i ; i = con[i].la) {
    if (con[i].b == anc[pos][0]) continue;
    fsd(con[i].b);
  }
}
void doit() {
  for (int i = 1 ; i <= 100 ; ++ i) {
    if (vec[i].size()) {
      clear();
      for (int j = 1 ; j <= n ; ++ j)
	tmp.push_back(val[j][i]);
      sort(tmp.begin(),tmp.end());
      tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
      for (int j = 1 ; j <= n ; ++ j)
	nowv[j] = lower_bound(tmp.begin(),tmp.end(),val[j][i]) - tmp.begin() + 1;
      m = tmp.size();
      fsd(1);
      for (int j = 0 ; j < (int)vec[i].size() ; ++ j)
	  ans[vec[i][j].id] = solve(vec[i][j]);
    }
  }
}
int main() {
  int x,y;
  char z;
  scanf("%d",&n);
  for (int i = 1 ; i < n ; ++ i) {
    scanf("%d%d %c",&x,&y,&z);
    add(x,y,z);
    add(y,x,z);
  }
  dfs(1,0);
  scanf("%d",&q);
  for (int i = 1 ; i <= q ; ++ i) {
    scanf("%d%d",&x,&y);
    init(x,y,i);
  }
  doit();
  for (int i = 1 ; i <= q ; ++ i)
    printf("%d\n",ans[i]);
  return 0;
}