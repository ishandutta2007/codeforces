#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=1<<17|7;
inline int query(int a, int b) {
	cout<<"? "<<a<<" "<<b<<endl;
	return read();
}
int n, a[N];
inline void work() {
	n=1<<read(), iota(a+1, a+n+1, 1);
	while (n>2) {
		int tot=0;
		for (int i=1; i<=n; i+=4) {
			int x=query(a[i], a[i+2]);
			if (x==1) a[++tot]=query(a[i], a[i+3])==1?a[i]:a[i+3];
			else if (x==2) a[++tot]=query(a[i+1], a[i+2])==1?a[i+1]:a[i+2];
			else a[++tot]=query(a[i+1], a[i+3])==1?a[i+1]:a[i+3];
		}
		n=tot;
	}
	if (n==2 && query(a[1], a[2])==2) a[1]=a[2];
	cout<<"! "<<a[1]<<endl; 
}
int main() {
//#ifdef LOCAL
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
//#endif
	int test=read();
	while (test--) work();
	return 0;
}