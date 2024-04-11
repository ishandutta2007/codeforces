#include <bits/stdc++.h>
using namespace std;
namespace FastIO {
    const int SIZE=1<<16; char buf[SIZE], obuf[SIZE], str[64]; int bi=SIZE, bn=SIZE, opt;
    int read(char *s) {
        while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
        int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
    }
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n)return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
using namespace FastIO;
int n, m, a[1005][1005], q;
int dp[1005][1005];
int mx[1005][1005][10][10], lg[1005];
inline bool query(int x1, int y1, int x2, int y2, int k) {
	x1 += k - 1, y1 += k - 1;
	int x = lg[x2 - x1 + 1], y = lg[y2 - y1 + 1];
	int ans = max(mx[x1][y1][x][y], mx[x1][y2 - (1 << y) + 1][x][y]);
	ans = max(ans, max(mx[x2 - (1 << x) + 1][y1][x][y], mx[x2 - (1 << x) + 1][y2 - (1 << y) + 1][x][y]));
	return ans >= k;
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			read(a[i][j]);
			if (a[i][j] == 1)
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
			mx[i][j][0][0] = dp[i][j];
		}
	}
	for (int i = 2; i <= max(n, m); ++i)
		lg[i] = lg[i >> 1] + 1;
	for (int i = 1; i <= n; ++i) 
		for (int k = 1; k < 10; ++k)
			for (int j = 1; j + (1 << k) - 1 <= m; ++j)
				mx[i][j][0][k] = max(mx[i][j][0][k - 1], mx[i][j + (1 << (k - 1))][0][k - 1]);
	for (int x = 1; x < 10; ++x)
		for (int y = 0; y < 10; ++y)
			for (int i = 1; i + (1 << x) - 1 <= n; ++i)
				for (int j = 1; j + (1 << y) - 1 <= m; ++j)
					mx[i][j][x][y] = max(mx[i][j][x - 1][y], mx[i + (1 << (x - 1))][j][x - 1][y]);
	read(q);
	while (q--) {
		int x1, y1, x2, y2;
		read(x1), read(y1), read(x2), read(y2);
		int len = min(x2 - x1 + 1, y2 - y1 + 1);
		int l = 1, r = len, ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (query(x1, y1, x2, y2, mid))
				ans = mid, l = mid + 1;
			else 
				r = mid - 1;
		}
		write(ans), write('\n');
	}
	return Fflush(), 0;
}