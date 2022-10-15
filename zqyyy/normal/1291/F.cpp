#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
inline int query(int x) {
	cout<<"? "<<x<<endl;
	char c; while (!isalpha(c=getchar())); return c=='Y';
}
inline void clear() {cout<<"R"<<endl;}
int n, K, cnt;
bool vis[1145];
inline void work(int id) {
	for (int i=id*K+1; i<=(id+1)*K; i++)
		if (!vis[i] && query(i)) vis[i]=true;	
}
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), K=read(), cnt=n/K;
	for (int i=0; i<cnt; i++) {
		int d=0;
		for (int j=0; j<cnt; j++) work((i+cnt+d)%cnt), d=-d-(d>=0);
		clear();
	}
	cout<<"! "<<n-count(vis+1, vis+n+1, true)<<endl;
	return 0;
}