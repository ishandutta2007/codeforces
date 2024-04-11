#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, j, k) for(int i=(j);i<=(k);i++)
#define INF (2147483647>>1)
using namespace std;
inline int read()
{
    int num=0;
    char c=' ';
    bool flag=1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag=0;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return flag?num:-num;
}
#define N 200005
int a[N], w[N];
int db[20] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
map < int, int > mp[11];
int main()
{
	int n = read(), k = read();
	For(i, 1, n) {
		a[i] = read();
		int tmp = a[i];
		while(tmp) {
			w[i]++;
			tmp /= 10;
		}
	}
	For(i, 1, 9) db[i] %= k;
	db[10] = (long long)(db[9] * 10) % k;
	For(i, 1, n) {
		For(j, 1, 10) {
			mp[j][(long long)(a[i]) * db[j] % k]++;
		}
	}
	long long ans = 0;
	For(i, 1, n) {
		int tmp = k - a[i] % k;
		if(tmp == k) tmp = 0; 
		if((long long)a[i] * db[w[i]] % k == tmp) ans--;
		ans += mp[w[i]][tmp];
	}
	cout << ans << endl;
	return 0;
}