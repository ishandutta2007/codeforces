#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int read() {
	int x = 0; char c = ' ';
	for(; !isdigit(c); c = getchar());
	for(; isdigit(c); c = getchar()) x = x * 10 - '0' + c;
	return x; 
}
int n, a[N], s[N], o[N], lst[N][2]; 
void ckmax(int &a, int b) { a = max(a, b); }
int main() {
	n = read();
	for(int i = 1; i <= n; i++)
		a[i] = read();
	int ans = 0; 
	for(int bit = 19; bit >= 0; bit--) {
		for(int i = 1; i <= n; i++) 
			s[i] = a[i] >> (bit + 1), o[i] = a[i] >> bit & 1;
		for(int i = 1; i <= n; i++) 
			s[i] ^= s[i - 1];
//		cerr << bit << endl; 
//		for(int i = 1; i <= n; i++) cerr << o[i] << ' ';
//		cerr <<endl; 
		memset(lst, -1, sizeof(lst)); lst[0][0] = 0; int L = 0; 
		for(int i = 1; i <= n; i++) {
			if(o[i]) {
				if(lst[s[i]][i & 1] != -1) {
					ckmax(ans, i - lst[s[i]][i & 1]);
//					cerr << bit << ' ' << s[i] << ' ' << i << ' ' << lst[s[i]][i & 1] << endl; 
				} else lst[s[i]][i & 1] = i;
			} else {
				for(int j = L; j < i; j++) lst[s[j]][j & 1] = -1;
				lst[s[i]][i & 1] = i; L = i;  
			}
		}
	}
	cout << ans << endl;
	return 0;
}