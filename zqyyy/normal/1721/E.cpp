#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef uint64_t ull;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1e6+17;
char str[N], t[11];
int n, m, fail[N], nxt[N][26];
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	scanf("%s", str+1), n=strlen(str+1);
	int j=0;
	for (int i=2; i<=n; i++) {
		while (j && str[i]!=str[j+1]) j=fail[j];
		if (str[i]==str[j+1]) j++; fail[i]=j;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<26; j++) nxt[i][j]=nxt[fail[i]][j];
		nxt[i][str[i+1]-'a']=i+1;
	}
	int Q=read();
	while (Q--) {
		scanf("%s", t+1), m=strlen(t+1);
		for (int i=n+1, k=j; i<=n+m; i++) {
			str[i]=t[i-n];
			while (k>=n && str[i]!=str[k+1]) k=fail[k];
			if (str[i]!=str[k+1]) k=nxt[k][str[i]-'a'];
			else k++;
			fail[i]=k, printf("%d%c", k, " \n"[i==n+m]);
		}
	}
	return 0;
}