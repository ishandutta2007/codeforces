#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define int long long
using namespace std;
inline int read()
{
    int num = 0; char c=' ';
    for(;c>'9'||c<'0';c=getchar()) ;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num;
}
//a,bka+kb+kk
int a, b, ans = (1ll << 62), qaq = 0;
int qwq[20378], tot = 0;
inline void getdiv(int x) {
	memset(qwq, 0, sizeof(qwq));
	int g = sqrt(x);
	for(int i = 1; i <= g; i++) {
		if(x % i == 0) {
			qwq[++tot] = i;
			if(x / i != i) {
				qwq[++tot] = x / i;
			}
		}
	} 
}
signed main()
{
    a = read(), b = read(); if(b < a) swap(a, b);
    int maxg = b - a; getdiv(maxg);
    sort(qwq + 1, qwq + 1 + tot);
    For(i, 1, tot) {
    	int k = ceil(a * 1.0 / qwq[i]) * qwq[i] - a;
    	if(ans > (a + k) * (b + k) / __gcd(a + k, maxg)) {
    		qaq = k;
    		ans = (a + k) * (b + k) / __gcd(a + k, maxg);
		}
	}
	cout << qaq << endl;
    return 0;
}