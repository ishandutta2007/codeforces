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
int n, k, f[N], lef[N], rig[N];
char s[N];
void Main() {
	n = read();
	scanf("%s", s + 1);
	
	lef[1] = 1;
	lef[0] = 0;
	L(i, 1, n) {
		if(s[i] == 'L') {
			if(i && s[i - 1] == 'R') lef[i + 1] = lef[i - 1];
			else lef[i + 1] = i;
		}
		else lef[i + 1] = i + 1;
	}
	rig[n + 1] = n + 1;
	rig[n + 2] = n + 2;
	R(i, n, 1) {
		if(s[i] == 'R') {
			if(i <= n && s[i + 1] == 'L') rig[i] = rig[i + 2];
			else rig[i] = i + 1;
		}
		else rig[i] = i;
	}
	L(i, 1, n + 1) printf("%d ", rig[i] - lef[i] + 1);
	puts("");
}
int main() {
	int T = read();
	while(T--) Main(); 
	return 0;
}