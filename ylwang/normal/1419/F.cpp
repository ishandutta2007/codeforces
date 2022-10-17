#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define rint register int
#define INF ((1 << 30) - 1)
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Pair pair < int, int >
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i, k, j) for(rint i = (k); i >= (j); i--)
#define For(i, k, j) for(rint i = (k); i <= (j); i++)
#define Foe(i, u) for(rint i = lst[u], v = e[i].v; i; i = e[i].nxt, v = e[i].v)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define file(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
const int P = 1000000007; //
using namespace std;
inline void ckmax(int &a, int b) {a = max(a, b);}
inline void ckmin(int &a, int b) {a = min(a, b);}
inline void mulmod(int &a, int b) {a = 1ll * a * b % P;}
inline void addmod(int &a, int b) {int t = a + b; a = (t >= P ? t - P : t); }
inline int ksm(int a, int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline int inv(int a) {return ksm(a, P-2);}
 
inline void printarray(int *a, int n) {For(i, 1, n) fprintf(stderr, "%d ", a[i]); fprintf(stderr, "\n");}
namespace FastIO {
    const int SIZE=1<<16; char buf[SIZE], obuf[SIZE], str[64]; int bi=SIZE, bn=SIZE, opt;
    int read(char *s) {
        while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
        int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
    }
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
const int MAXN = 3e3 + 5;
struct Node {
	int x, y;
}a[MAXN], b[MAXN];
int n, dx[MAXN], dy[MAXN], L[MAXN], R[MAXN], U[MAXN], D[MAXN], col[MAXN], tx, ty, m;
vector < int > row[MAXN], clm[MAXN];
struct Tri {
	int o, x, ad;
	bool operator < (const Tri &b) const {return x < b.x;}
};
vector < Tri > tmp, ad[MAXN];

bool cmp1(int i, int j) {return a[i].y < a[j].y;}
bool cmp2(int i, int j) {return a[i].x < a[j].x;}
#define ls (k << 1)
#define rs (k << 1 | 1)
#define mid ((l + r) >> 1)
const int N = MAXN << 2;
struct Segment_tree {
	int o[N][16];
	int now[MAXN][4], st[MAXN];
	void build(int k, int l, int r) {
		mst(o[k], 0); o[k][0] = 1;
		if(l == r) return st[l] = now[l][0] = now[l][1] = now[l][2] = now[l][3] = 0, o[k][0] = 1, void();
		build(ls, l, mid), build(rs, mid+1, r);
	}
	void update(int k, int l, int r, int pos, int val, int ad) {
		if(l == r) { 
			if(ad == 1) {
				if(!now[l][val]++) o[k][st[l]] = 0, st[l] ^= (1 << val), o[k][st[l]] = 1;
			} else {
				if(!--now[l][val]) o[k][st[l]] = 0, st[l] ^= (1 << val), o[k][st[l]] = 1;
			}
			return;
		}
		pos <= mid ? update(ls, l, mid, pos, val, ad) : update(rs, mid+1, r, pos, val, ad);
		For(i, 0, (1 << m) - 1) o[k][i] = o[ls][i] | o[rs][i];
	}
	inline int query(int k, int l, int r, int ql, int qr, int t) {
		if(l == ql && r == qr) {
//			cerr << "*" << t << ' ';
			t = ((1 << m) - 1) ^ t;
//			cerr << t << endl;
			For(i, 0, (1 << m) - 1) if(((t | i) == i) && o[k][i]) return 1;
			return 0;
		}
		if(qr <= mid) return query(ls, l, mid, ql, qr, t);
		if(mid < ql) return query(rs, mid+1, r, ql, qr, t);
		return query(ls, l, mid, ql, mid, t) | query(rs, mid+1, r, mid+1, qr, t);
	}
}tr;
#undef mid
int f[MAXN];
inline int find(int x) {while(x != f[x]) x = f[x] = f[f[x]]; return x;}
inline void merge(int x, int y) {x = find(x), y = find(y); if(x != y) f[y] = x;}
inline void init() {
	m = 0; memset(col, -1, sizeof(col));
	For(i, 1, tx) row[i].clear(); For(i, 1, tx) ad[i].clear(); tx = 0;
	For(i, 1, ty) clm[i].clear(); ty = 0;
	memcpy(a, b, sizeof(a));
	For(i, 1, n) f[i] = i;
}
inline int Handle(ll x) {
	if(x > INT_MAX) return INT_MAX;
	if(x < INT_MIN) return INT_MIN;
	return x;
}

bool check(int mid) {
//	fprintf(stderr, "mid = %d : \n", mid);
	init();
	For(i, 1, n) dx[++tx] = a[i].x, L[i] = dx[++tx] = Handle((ll)a[i].x - mid), R[i] = dx[++tx] = Handle((ll)a[i].x + mid);
	For(i, 1, n) dy[++ty] = a[i].y, U[i] = dy[++ty] = Handle((ll)a[i].y - mid), D[i] = dy[++ty] = Handle((ll)a[i].y + mid);
	sort(dx + 1, dx + 1 + tx); sort(dy + 1, dy + 1 + ty); tx = unique(dx + 1, dx + 1 + tx) - dx - 1, ty = unique(dy + 1, dy + 1 + ty) - dy - 1;
    For(i, 1, n) row[a[i].x = lower_bound(dx + 1, dx + 1 + tx, a[i].x) - dx].pb(i), clm[a[i].y = lower_bound(dy + 1, dy + 1 + ty, a[i].y) - dy].pb(i);
    For(i, 1, n) {
    	L[i] = lower_bound(dx + 1, dx + 1 + tx, L[i]) - dx;
    	R[i] = lower_bound(dx + 1, dx + 1 + tx, R[i]) - dx;
    	U[i] = lower_bound(dy + 1, dy + 1 + ty, U[i]) - dy;
    	D[i] = lower_bound(dy + 1, dy + 1 + ty, D[i]) - dy;
	}
	For(i, 1, tx) sort(row[i].begin(), row[i].end(), cmp1);
	For(i, 1, ty) sort(clm[i].begin(), clm[i].end(), cmp2);
	For(i, 1, tx)
		for(rint j = 1; j < (int)row[i].size(); j++)
			if(dy[a[row[i][j]].y] - dy[a[row[i][j-1]].y] <= mid) merge(row[i][j], row[i][j-1]);
	For(i, 1, ty)
		for(rint j = 1; j < (int)clm[i].size(); j++)
			if(dx[a[clm[i][j]].x] - dx[a[clm[i][j-1]].x] <= mid) merge(clm[i][j], clm[i][j-1]);
	
	For(i, 1, n) {
		if(col[find(i)] == -1) col[i] = col[find(i)] = m++;
		else col[i] = col[find(i)];
	}
	if(m > 4) return 0;
	if(m == 1) return 1;
//	For(i, 1, n) {
//		fprintf(stderr, "%d %d %d %d %d %d\n", i, a[i].x, a[i].y, L[i], R[i], col[i]);
//	}
//	cerr << m << ' ' << tx << ' ' << ty << endl;
	tr.build(1, 1, ty);
	For(i, 1, n) {
		ad[L[i]].pb((Tri) {col[i], a[i].y, 1});
		if(R[i] != tx) ad[R[i] + 1].pb((Tri) {col[i], a[i].y, 0});
	}
	int now[4], st;
	For(i, 1, tx) { 
//		cerr << i << " :" << endl;
		for(auto it : ad[i])
			tr.update(1, 1, ty, it.x, it.o, it.ad);
		if(tr.o[1][(1 << m) - 1]) return 1;
		tmp.clear(); st = now[0] = now[1] = now[2] = now[3] = 0; 
		for(int it : row[i]) {
//			cerr << U[it] << ' ' << D[it] << endl;
			tmp.pb((Tri) {col[it], U[it], 1}); 
			if(D[it] != ty) tmp.pb((Tri) {col[it], D[it] + 1, 0});
		}
		sort(tmp.begin(), tmp.end()); tmp.pb((Tri) {-1, ty + 1, -1});
		for(int j = 0; j < (int)tmp.size() - 1; j++) {
			Tri it = tmp[j];
			if(it.ad == 1) {
				if(!now[it.o]++) st ^= (1 << it.o);
			} else {
				if(!--now[it.o]) st ^= (1 << it.o);
			}
//			cerr << tmp[j].x << " ? " << it.x << ' ' << tmp[j + 1].x - 1 << ' ' << st << endl;
			if(tmp[j + 1].x != it.x && tr.query(1, 1, ty, it.x, tmp[j + 1].x - 1, st)) return 1;
		}
//		cerr << endl;
	}
	return 0;
}

signed main()
{
    #ifndef ONLINE_JUDGE
        file("pro");
    #endif
    
    cin >> n;
    For(i, 1, n) cin >> a[i].x >> a[i].y, b[i] = a[i];
//    cerr << check(199) << endl;
//	if(n == 841) {
//		cout << check(968891509) << ' ' << check(976408099) << endl;
//	}
    ll l = 1, r = 2e9, res = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			r = mid - 1, res = mid;
		} else l = mid + 1;
	}
	cout << res << endl;
    return FastIO::Fflush(), 0;
}