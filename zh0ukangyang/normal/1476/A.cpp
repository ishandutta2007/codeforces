#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
const db eps = 1e-5;
inline int read() {
	int x = 0, f = 1; char ch=getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
	return x * f; 
}
int n, k, f[N];
void Main() {
	n = read(), k = read();	
	if(n % k == 0) puts("1");
	else if(n > k) puts("2");
	else printf("%d\n", (k - 1) / n + 1);
}
int main() {
	int T = read();
	while(T--) Main(); 
	return 0;
}