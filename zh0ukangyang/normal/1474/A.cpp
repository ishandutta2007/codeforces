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
int n, m;
char s[N];
void Main() {
	scanf("%d%s", &n, s + 1);
	int las = -1;
	L(i, 1, n) {
		if(s[i] - '0' + 1 != las) putchar('1'), las = s[i] - '0' + 1;
		else putchar('0'), las = s[i] - '0' + 0;
	} 
	printf("\n");
}
int main() {
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}