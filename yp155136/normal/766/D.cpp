#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

const int MAX_N =2e5 + 6;

struct DisjointSet {
	int p[MAX_N];
	void init(int n) {
		for(int i=0;n>=i;i++) p[i]=i;
	}
	int Find(int x) {
		return p[x] == x?x:p[x] = Find(p[x]);
	}
	void Union(int x,int y) {
		p[Find(x)] = Find(y);
	}
} djs;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q;
	while (cin >> n >> m>> q) {
		djs.init(2*n);
		map<string,int> mp;
		for (int i=1;n>=i;i++) {
			string a;
			cin >>a;
			mp[a]=i;
		}
		for (int i=1;m>=i;i++) {
			int t;
			string _0,_1;
			cin >>t>> _0>>_1;
			int a=mp[_0],b=mp[_1];
			if (t==1 && djs.Find(a) == djs.Find(b)) cout<<"YES\n";
			else if (t==1 && djs.Find(a) == djs.Find(b+n)) cout<<"NO\n";
			else if (t==1) {
				djs.Union(a,b);
				djs.Union(a+n,b+n);
				cout<<"YES\n";
			}
			else if (t==2 && djs.Find(a+n) ==djs.Find(b)) cout<<"YES\n";
			else if (t==2&& djs.Find(a) == djs.Find(b)) cout<<"NO\n";
			else if (t==2){
				cout<<"YES\n";
				djs.Union(a,b+n);
				djs.Union(a+n,b);
			}
		}
		while (q--) {
			string _0,_1;
			cin >> _0 >> _1;
			int a=mp[_0];
			int b=mp[_1];
			if (djs.Find(a) == djs.Find(b)) cout<<"1\n";
			else if (djs.Find(a) == djs.Find(b+n)) cout<<"2\n";
			else cout<<"3\n";
		}
	}
}