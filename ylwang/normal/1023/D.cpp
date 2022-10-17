#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long


using namespace std;
inline int read() {
    int num = 0, flag = 1; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 500005
set < int > Q; 
int n, m, a[MAXN];
int r[MAXN], l[MAXN], mx = 0, mn = (1 << 30);
signed main()
{
	n = read(), m = read();
	For(i, 1, n) a[i] = read(), mx = max(mx, a[i]), mn = min(mn, a[i]);
	for(int i = n; i >= 1; i--) if(!r[a[i]]) r[a[i]] = i;
	For(i, 1, n) if(!l[a[i]]) l[a[i]] = i;
	For(i, 1, n) {
		if(!a[i]) {
			if(mx < m) a[i] = mx = m;
			else if(Q.size()) a[i] = *--Q.end();
			else a[i] = 1;
		} else {
			if(l[a[i]] == i && l[a[i]] < r[a[i]])
				Q.insert(a[i]);
			if(r[a[i]] == i && l[a[i]] < r[a[i]]) 
				Q.erase(a[i]);
			if(Q.size()) if(a[i] < (*--Q.end())) {
				puts("NO"); return 0;
			} 
		}
		
	}
	if(mx < m) {puts("NO"); return 0;}
	puts("YES");
   	For(i, 1, n) printf("%d ",a[i]);puts("");
	
    return 0;
}