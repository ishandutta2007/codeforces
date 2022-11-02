#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cctype>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;

inline ll read() {
	char ch = getchar(); ll x = 0; int op = 1;
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') op = -1;
	for(; isdigit(ch); ch = getchar()) x = x*10+ch-'0';
	return x*op;
}
inline void write(ll a) {
	if(a < 0) putchar('-'), a = -a;
	if(a >= 10) write(a/10); putchar('0'+a%10);
}

int main() {
	puts("2000");
	for(int i = 1; i <= 1000; i ++) printf("%d 1 %d 2\n", i, i);
	for(int i = 1000; i >= 1; i --) printf("%d 1 %d 2\n", i, i);
	return 0;
}