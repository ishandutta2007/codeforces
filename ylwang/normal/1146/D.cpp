#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define LL long long
using namespace std;
inline int read()
{
    int num = 0; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) ;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num;
}
inline int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a % b);
}

int m, a, b, g, mini[5000005];
int c[5000005];
inline int lowbit(int x) {return x & (-x);}
inline void update(int x, int val, int m) {for(int i = x; i <= m; i += lowbit(i))c[i] += val; }
inline int getsum(int x) {int ans = 0;for(int i = x; i > 0; i -= lowbit(i)) ans += c[i];return ans;}
struct Node {
	int u, val;
	bool operator < (const Node b) const {return val > b.val;}
};

priority_queue < Node > q;
long long Subtask1(int m) {
	memset(mini, -1, sizeof(mini));
	q.push((Node){0, 0}); mini[0] = 0;
	while(!q.empty()) {
		int u = q.top().u;
		q.pop();	
		int v = u - b;
		if(mini[v] == -1 && v >= 1) {
			mini[v] = mini[u];
			q.push((Node){v, mini[v]});
		}
		v = u + a;
		if(mini[v] == -1 && v <= m) {
			mini[v] = max(v, mini[u]);
			q.push((Node){v, mini[v]});
		}
		
	}
	long long ans = m+1; //0
	For(i, 1, m) {
		if(mini[i] != -1) update(mini[i], 1, m);
		ans += getsum(i);
	} 
	return ans; 
}
LL orz(LL x) {
    return x*(x+1)>>1;
}

LL sqz(LL x,LL mo)
{
    if(x % mo == 0) return x/mo;
    else return x/mo+1;
}

LL qwq(LL n, LL x) {
    return orz((n+1)/x)*x + ((n+1)%x)*(sqz(n+1,x));
}

signed main()
{
	m = read(), a = read(), b = read(), g = gcd(a, b);
	if(m <= 200002) cout << Subtask1(m) << endl;
	else {
		cout << Subtask1(200002) + qwq(m, g) - qwq(200002, g);
	}
	return 0;
}