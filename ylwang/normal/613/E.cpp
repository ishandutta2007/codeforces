#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i,k,j) for(int i=(k);i>=(j);i--)
#define For(i,k,j) for(int i=(k);i<=(j);i++)
#define Foe(i,u) for(int i=lst[u],v=e[i].v;i;i=e[i].nxt,v=e[i].v)
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define Fin(s) freopen(s,"r",stdin)
#define Fout(s) freopen(s,"w",stdout)
#define file(s) Fin(s".in"),Fout(s".out")
#define INF ((1<<30)-1)
//#define int long long
const int P=1e9+7; //
using namespace std;
template<typename T>inline void ckmax(T &a,T b) {(a<b)&&(a=b);}
template<typename T>inline void ckmin(T &a,T b) {(a>b)&&(a=b);}
inline int mul(int a,int b) {return 1ll*a*b%P;}
inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
inline void mulmod(int &a,int b) {a=mul(a, b);}
inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline void fprint(const vector<int> &f) {for(int i=0;i<(int)f.size();i++) fprintf(stderr,"%d ",f[i]); fprintf(stderr,"\n");}
inline int inv(int a) {return ksm(a,P-2);}
namespace FastIO {
  const int SIZE=1<<16; char buf[SIZE],obuf[SIZE],str[64]; int bi=SIZE,bn=SIZE,opt;
  int read(char *s) {
    while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
    int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
  }
  bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
  void write(int x) {
    if(!x) obuf[opt++]='0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
    if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}
  }
  void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}}
	void Fflush() {if (opt) fwrite(obuf,1,opt,stdout); opt=0;}
};
inline int read() {int x; FI(x); return x;}
const int P1 = 998244353, P2 = 1000000007;
struct Node {
  int x, y;
  Node operator + (const Node &b) {return (Node) {(x + b.x) % P1, (y + b.y) % P2};}
  Node operator + (const int &b) {return (Node) {(x + b) % P1, (y + b) % P2};}
  Node operator - (const Node &b) {return (Node) {(x - b.x + P1) % P1, (y - b.y + P2) % P2};}
  Node operator - (const int &b) {return (Node) {(x - b + P1) % P1, (y - b + P2) % P2};}
  Node operator * (const Node &b) {return (Node) {1ll * x * b.x % P1, 1ll * y * b.y % P2};}
  Node operator * (const int &b) {return (Node) {1ll * x * b % P1, 1ll * y * b % P2};}
  bool operator == (const Node &b) const {return x == b.x && y == b.y;}
  bool operator != (const Node &b) const {return x != b.x || y != b.y;}
  void print() {fprintf(stderr, "%d %d\n", x, y);}
};
const Node BASE = (Node) {131, 13331};
const int MN = 2e3 + 5;
string s[3], t;
int n, m, ans, cl, f[2][MN][MN], g[2][MN][MN], lft[2][MN][MN], rgt[2][MN][MN];
Node H[2][3][MN], pw[MN];
Node getHash(int o, int i, int l, int r) { // o = 0 :  
	if(!o) return H[o][i][r] - pw[r - l + 1] * H[o][i][l - 1];
	else return H[o][i][l] - pw[r - l + 1] * H[o][i][r + 1];
}
int check(int o, int i, int j, int k) {
	if (!o) {
		if (j < k) return 0;
		if (getHash(1, i ^ 1, j - k + 1, j) != getHash(0, 2, 1, k)) return 0;
//		getHash(0, i, j - k + 1, j).print(), getHash(0, 2, k + 1, 2 * k).print();
		if (getHash(0, i, j - k + 1, j) != getHash(0, 2, k + 1, 2 * k)) return 0;
//		cerr << o << ' ' << i << ' ' << j << ' ' << k << endl;
		return 1;
	} else {
		if (j + k - 1 > n) return 0;
		if (getHash(0, i, j, j + k - 1) != getHash(0, 2, m - 2 * k + 1, m - k)) return 0;
		if (getHash(1, i ^ 1, j, j + k - 1) != getHash(0, 2, m - k + 1, m)) return 0;
//		cerr << o << ' ' << i << ' ' << j << ' ' << k << endl;
		return 1;
	}
}

void solve() {
//	cerr << n << ' ' << m << endl;
	For(i, 0, 2) {
		For(j, 1, i != 2 ? n : m) H[0][i][j] = H[0][i][j - 1] * BASE + s[i][j];
		foR(j, i != 2 ? n : m, 1) H[1][i][j] = H[1][i][j + 1] * BASE + s[i][j];
	}
//	cerr << s[0] << ' ' << s[1] << ' '<< s[2] << ' ' << t << endl; 
	For(i, 0, 1) For(j, 1, n) {
		For(k, 1, m) {
			f[i][j][k] = g[i][j][k] = 0;
			if(k == 1) {
				g[i][j][k] = lft[i][j][k] = (s[i][j] == t[1]);
				rgt[i][j][k] = (s[i][j] == t[m]);
			} else if(k % 2 == 0) {
				g[i][j][k] = lft[i][j][k] = check(0, i, j, k >> 1);
				rgt[i][j][k] = check(1, i, j, k >> 1);
			}
			if(k == m) {
//				cerr << "?" << ' ' << lft[i][j][k] << ' ' << rgt[i][j][k] << endl;
				addmod(cl, lft[i][j][k]);
				if(m > 2) addmod(cl, rgt[i][j][k]);
			}
		}
	}
	For(j, 1, n) {
		For(k, 1, m) {
			For(i, 0, 1) {
				if(s[i][j] == t[k]) {
					addmod(f[i][j][k], f[i][j - 1][k - 1]);
					addmod(f[i][j][k], g[i][j - 1][k - 1]);
				}
			}
			For(i, 0, 1) {
				if(s[i][j] == t[k]) {
					addmod(g[i][j][k], f[i ^ 1][j][k - 1]);
				}
			}
			For(i, 0, 1) {
				if(rgt[i][j + 1][m - k])
					addmod(ans, add(f[i][j][k], g[i][j][k]));
			}
		}		
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		file("string");	
	#endif
	cin >> s[0] >> s[1] >> s[2]; t = '#' + s[2]; 
	n = s[0].size(), m = t.size() - 1;  s[0] = '#' + s[0], s[1] = '#' + s[1], s[2] = '#' + s[2];
	pw[0] = (Node) {1, 1}; For(i, 1, max(n, m)) pw[i] = pw[i - 1] * BASE;
	solve(); reverse(++s[0].begin(), s[0].end()); reverse(++s[1].begin(), s[1].end()); solve();
//	cerr << ans << ' ' << cl << endl;	
	cout << add(ans, mul(cl, inv(2))) << endl;
	return FastIO::Fflush(),0;
}