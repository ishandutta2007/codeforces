#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
#define pii pair<int, int>
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=2e6+7;
namespace sam {
	int lst=1, tot=1, link[N], len[N], sz[N], nxt[N][26];
	inline void insert(int c) {
		int cur=++tot, p=lst; sz[cur]=1, len[cur]=len[p]+1, lst=cur;
		while (p && !nxt[p][c]) nxt[p][c]=cur, p=link[p];
		if (!p) link[cur]=1;
		else {
			int q=nxt[p][c];
			if (len[q]==len[p]+1) link[cur]=q;
			else {
				int r=++tot; link[r]=link[q], memcpy(nxt[r], nxt[q], 26<<2);
				len[r]=len[p]+1, link[cur]=link[q]=r;
				while (p && nxt[p][c]==q) nxt[p][c]=r, p=link[p];
			}
		}
	}
	inline void init() {
		static int deg[N]; for (int i=2; i<=tot; i++) deg[link[i]]++;
		queue<int>q; for (int i=1; i<=tot; i++) if (!deg[i]) q.push(i);
		while (!q.empty()) {
			int x=q.front(); q.pop();
			if (x!=1) {
				int y=link[x]; sz[y]+=sz[x];
				if (!--deg[y]) q.push(y);
			}
		}
	}
	inline void query(char *str) {
		static int vis[N], tim; tim++;
		int n=strlen(str+1), p=1, Len=0, ans=0;
		for (int i=1; i<=n; i++) str[i+n]=str[i];
		for (int i=1; i<=n+n; i++) {
			int c=str[i]-'a';
			if (nxt[p][c]) p=nxt[p][c], Len++;
			else {
				while (p && !nxt[p][c]) p=link[p];
				if (!p) p=1, Len=0;
				else Len=len[p]+1, p=nxt[p][c];
			}
			if (Len>=n) {
				while (len[link[p]]>=n) p=link[p];
				if (vis[p]!=tim) vis[p]=tim, ans+=sz[p];
				Len=n;
			}
		}
		printf("%d\n", ans);
	}
}
int n, m;
char str[N];
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	scanf("%s", str+1), n=strlen(str+1);
	for (int i=1; i<=n; i++) sam::insert(str[i]-'a');
	sam::init(), m=read();
	while (m--) scanf("%s", str+1), sam::query(str);
	return 0;
}