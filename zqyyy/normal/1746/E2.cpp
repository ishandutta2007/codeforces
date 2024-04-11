#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() { //Don't to use in interactive problems!!! 
	return getchar();
	static char *p1, *p2, buf[1<<23];
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<23, stdin), p1==p2?EOF:*p1++):*p1++;
}
inline void read(char *s) {
	char c; while (isspace(c=getc()));
	while (!isspace(c)) (*s++)=c, c=getc();
}
inline int read() {
	int f=1, r=0; char c=getc();
	while (!isdigit(c)) f^=c=='-', c=getc();
	while (isdigit(c)) r=r*10+c-48, c=getc();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1007, mod=998244353;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int add(int x, int y) {return inc(x, y), x;}
inline int sub(int x, int y) {return dec(x, y), x;}
inline int qpow(int a, ll b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
inline int query(vector<int>S) {
	cout<<"? "<<S.size()<<" ";
	for (int x:S) cout<<x<<" "; cout<<endl;
	string s; cin>>s;
	return s=="YES"?1:0;
}
inline void answer(int x) {
	cout<<"! "<<x<<endl;
	string s; cin>>s;
	if (s==":)") exit(0);
}
vector<int> operator +(vector<int>a, const vector<int> &b) {
	for (int x:b) a.push_back(x);
	return a;
}
void solve(vector<int>vec) {
	if ((int)vec.size()<=3) {
		int sz=vec.size();
		if (sz==1) answer(vec[0]);
		else if (sz==2) answer(vec[0]), answer(vec[1]);
		else {
			int x=vec[0], y=vec[1], z=vec[2];
			int a=query({x, y});
			if (!a) {
				int b=query({x});
				if (!b) solve({y, z});
				else solve({x, z});
			}
			a=query({z});
			if (!a) solve({x, y});
			a=query({y, z});
			if (a==1) solve({y, z});
			else solve({x, z});
		}
		exit(0);
	}
}
int n, f[N][N], g[N][N], h[N][N]; //yz, nz
inline void work() {
	n=120, memset(f, 0x3f, sizeof f);
	for (int s=2; s<=n; s++)
		for (int i=0; i<=s; i++) {
			int j=s-i;
			if (s==2) {f[i][j]=0; continue;}
			for (int k=0; k<=i; k++)
				for (int l=0; l<=j; l++) {
					int tmp=max(f[k+l][i-k], f[i-k+j-l][k])+1;
					if (tmp<f[i][j]) f[i][j]=tmp, g[i][j]=k, h[i][j]=l;
				}
		}
	n=read();
	vector<int>vec(n);
	iota(vec.begin(), vec.end(), 1);
	if (n<=3) solve(vec);
	vector<int>Y=vec, N;
	while (true) {
		int yz=Y.size(), nz=N.size(), m=nz/2, m2=yz/2;
		if (yz+nz<=2) solve(Y+N);
		if (yz+nz<=120) m2=g[yz][nz], m=h[yz][nz];
		vector<int>A(Y.begin(), Y.begin()+m2);
		vector<int>B(Y.begin()+m2, Y.end());
		vector<int>C(N.begin(), N.begin()+m);
		vector<int>D(N.begin()+m, N.end());
		vector<int>tmp=A+C;
		if (query(tmp)) Y=tmp, N=B;
		else  Y=B+D, N=A;
	}
}
int main() {
	int test=1; //read();
	while (test--) work();
	return 0;
}