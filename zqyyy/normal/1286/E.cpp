#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t lll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
inline char getc() {
	char c; while (!isalpha(c=getchar())); return c;
}
void write(lll x) {
	if (x>9) write(x/10);
	putchar(x%10+48);
}
inline void write(lll x, char c) {
	write(x), putchar(c);
}
const int N=6e5+7;
int n, tp, stk[N], fa[N], w[N], nxt[N];
char str[N];
map<int, int>h;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), str[1]=getc(), write(w[1]=read(), 10), stk[++tp]=1;
	lll ans=w[1], sum=0;
	for (int i=2, j=0; i<=n; i++) {
		str[i]=(getc()-'a'+ans)%26+'a', w[i]=read()^(int)(ans&((1<<30)-1));
		while (j && str[i]!=str[j+1]) j=nxt[j];
		if (str[i]==str[j+1]) j++; nxt[i]=j, fa[i]=str[i]!=str[nxt[i-1]+1]?nxt[i-1]+1:fa[nxt[i-1]+1];
		for (int j=i; j>1;) {
			if (str[j]==str[i]) {j=fa[j]; continue;}
			int v=w[*lower_bound(stk+1, stk+tp+1, i-j+1)];
			if (!--h[v]) h.erase(v); sum-=v, j=nxt[j-1]+1;
		}
		int num=0;
		for (auto it=h.upper_bound(w[i]); it!=h.end(); h.erase(it++))
			num+=it->se, sum-=(ll)(it->fi-w[i])*it->se;
		if (str[1]==str[i]) num++, sum+=w[i];
		h[w[i]]+=num;
		while (tp && w[stk[tp]]>=w[i]) tp--;
		stk[++tp]=i, write(ans+=sum+w[stk[1]], 10);
	}
	return 0;
}