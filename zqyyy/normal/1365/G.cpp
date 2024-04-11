#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	ll f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=1007;
int n, id[N];
ll t[13];
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read();
	for (int i=1, j=0; i<(1<<13); i++)
		if (__builtin_popcount(i)==6) {
			id[++j]=i;
			if (j==n) break;
		}
	for (int i=0; i<13; i++) {
		vector<int>vec;
		for (int j=1; j<=n; j++)
			if (id[j]>>i&1) vec.push_back(j);
		if (vec.empty()) continue;
		cout<<"? "<<vec.size()<<" ";
		for (int x:vec) cout<<x<<" "; cout<<endl;
		t[i]=read();
	}
	cout<<"! ";
	for (int i=1; i<=n; i++) {
		ll res=0;
		for (int j=0; j<13; j++)
			if (!(id[i]>>j&1)) res|=t[j];
		cout<<res<<" ";
	}
	return 0;
}