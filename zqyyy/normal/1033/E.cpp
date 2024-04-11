#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+c-48, c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=607;
inline int query(vector<int>S) {
	if ((int)S.size()<=1) return 0;
	cout<<"? "<<S.size()<<endl;
	for (int x:S) cout<<x<<" "; cout<<endl;
	return read();
}
int n, fa[N], dep[N];
inline void find_tree() {
	queue<int>q; dep[1]=1, q.push(1);
	while (!q.empty()) {
		int x=q.front(); q.pop(); vector<int>vec;
		for (int i=1; i<=n; i++) if (!dep[i]) vec.push_back(i);
		function<void(vector<int>)> solve=[&](vector<int> S) {
			vector<int>tmp=S; tmp.push_back(x);
			if (query(tmp)==query(S)) return;
			if ((int)S.size()==1) {
				int y=S[0];
				q.push(y), dep[y]=dep[x]+1, fa[y]=x;
				return;
			}
			int mid=S.size()>>1;
			solve(vector<int>(S.begin(), S.begin()+mid));
			solve(vector<int>(S.begin()+mid, S.end()));
		};
		if (!vec.empty()) solve(vec);
	}
}
vector<int>a, b;
inline void find_odd_circle() {
	for (int i=1; i<=n; i++) {
		vector<int>&A=dep[i]&1?a:b; int tmp=query(A);
		for (size_t j=0; j<A.size(); j++) if (A[j]==i) {A.erase(A.begin()+j); break;}
		if (query(A)==tmp) continue;
		int l=0, r=A.size()-1;
		while (l<=r) {
			int mid=(l+r)>>1; vector<int>vec;
			for (int i=0; i<=mid; i++) vec.push_back(A[i]);
			int tmp=query(vec); vec.push_back(i);
			if (tmp!=query(vec)) r=mid-1;
			else l=mid+1;
		}
		int x=A[l]; vector<int>L, R;
		if (dep[i]>dep[x]) swap(i, x);
		while (dep[x]>dep[i]) R.push_back(x), x=fa[x];
		while (x^i) L.push_back(i), R.push_back(x), i=fa[i], x=fa[x];
		L.push_back(x), cout<<"N "<<L.size()+R.size()<<endl;
		for (auto y:L) cout<<y<<" "; reverse(R.begin(), R.end());
		for (auto y:R) cout<<y<<" "; cout<<endl;
		exit(0);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(), find_tree();
	for (int i=1; i<=n; i++) (dep[i]&1?a:b).push_back(i);
	if (!query(a) && !query(b)) {
		cout<<"Y "<<a.size()<<endl;
		for (int x:a) cout<<x<<" "; cout<<endl;
		return 0;
	}
	find_odd_circle();
	return 0;
}