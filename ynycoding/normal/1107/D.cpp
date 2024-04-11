#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#define pb push_back
#define MAXN 5205
using std::vector;
int n, ans;
bool mp[MAXN][MAXN];
char s[MAXN];
vector<int> l, r;
namespace io {
	const int BUFSIZE = 1 << 20;
	char ibuf[BUFSIZE], *is = ibuf, *it = ibuf;
	char obuf[BUFSIZE], *os = obuf, *ot = obuf + BUFSIZE - 1;
	char read_char() {
		if (is == it) {
			it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
		}
		return *is++;
	}
	inline bool isspace(char c) { return c==' '||c=='\n'||c=='\r'; }
	void read_string(char* s) {
		char c = read_char();
		while (isspace(c)) {
			c = read_char();
		}
		while (!isspace(c)) {
			*s++ = c;
			c = read_char();
		}
		*s = 0;
	}
	void flush() {
	fwrite(obuf, 1, os - obuf, stdout);
	os = obuf;
	}
	struct flusher_t {
		~flusher_t() {
			flush();
		}
	} flusher;
}
using io::read_string;
inline int convert(char c)
{
	if('0'<=c&&c<='9') return c-'0';
	if('A'<=c&&c<='F') return 10+c-'A';
}
int gcd(int a, int b) { while(b) { a%=b; std::swap(a, b); } return a; }
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		read_string(s);
		for(int j=0; j<n/4; ++j)
		{
			int cur=convert(s[j]);
			mp[i][j*4+1]=cur&(1<<3);
			mp[i][j*4+2]=cur&(1<<2);
			mp[i][j*4+3]=cur&(1<<1);
			mp[i][j*4+4]=cur&1;
		}
	}
	r.pb(0), l.pb(0);
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			if(mp[i][j]^mp[i+1][j]||i==n) r.pb(i);
			if(mp[i][j]^mp[i][j+1]||j==n) l.pb(j);
		}
	}
	for(int i=1; i<r.size(); ++i) ans=gcd(ans, abs(r[i]-r[i-1]));
	for(int i=1; i<l.size(); ++i) ans=gcd(ans, abs(l[i]-l[i-1]));
	printf("%d", ans);
	return 0;
}