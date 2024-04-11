#include<bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)

using namespace std;
#define int long long
int calcw(int x, int y, int xx, int yy) {
	if((xx - x + 1) * (yy - y + 1) & 1) {
		if((x + y) % 2) {
			return (xx - x + 1) * (yy - y + 1) / 2;
		} else {
		    return (xx - x + 1) * (yy - y + 1) / 2 + 1; 
		}
	} else {
		return (xx - x + 1) * (yy - y + 1) / 2;
	}
}
int calcb(int x, int y, int xx, int yy) {
	return (xx - x + 1) * (yy - y + 1) - calcw(x, y, xx, yy);
}
signed main()
{
	int _; cin >> _;
	while(_--) {
		int n, m, answ;
		scanf("%lld %lld", &n, &m);
		answ = calcw(1, 1, n, m);
		int X1, Y1, X2, Y2;
		scanf("%lld %lld %lld %lld", &X1, &Y1, &X2, &Y2);
		int X3, Y3, X4, Y4;
		scanf("%lld %lld %lld %lld", &X3, &Y3, &X4, &Y4);
		int jx1 = max(X1, X3), jx2 = min(X2, X4);
		int jy1 = max(Y1, Y3), jy2 = min(Y2, Y4);
		if(jx1 > jx2 || jy1 > jy2) {
			answ += calcb(X1, Y1, X2, Y2);
			answ -= calcw(X3, Y3, X4, Y4); 
		} else {
//			cout << jx1 << ' ' << jx2 << ' ' << jy1 << ' ' << jy2 << endl;
			answ += calcb(X1, Y1, X2, Y2);
			answ -= calcb(jx1, jy1, jx2, jy2);
			answ -= calcw(X3, Y3, X4, Y4); 
//			answ += calcw(jx1, jy1, jx2, jy2); 
		}
		cout << answ << ' ' << n * m - answ << endl; 
	}
	
	return 0;
}