#include <bits/stdc++.h>
using namespace std;

int x,y,n;

typedef pair < int , int > Intv ;
set < Intv > w,h;
multiset < int > wl , hl;

void init() {
	scanf("%d%d%d",&x,&y,&n);
	w.insert ( Intv(0,x) );
	h.insert ( Intv(0,y) );
	wl.insert(x);
	hl.insert(y);
}

void solve() {
	for (int i=0;i<n;i++) {
		char opt ;
		int  pos;
		cin >> opt >> pos;
		set < Intv > & ds = ( opt == 'V' ? w : h);
		multiset < int > & dm = ( opt == 'V' ? wl : hl);
		set < Intv > :: iterator it = ds.lower_bound ( Intv(pos,0x3f3f3f3f) );
		it--;
//		cout << (*ds.begin() < Intv(pos,0x3f3f3f3f)) << endl;
//		cout << (it == ds.end()) << endl;
		int fst = it->first;
		int lst = it->second;
//		cout << fst << ' ' << lst << endl;
		ds.erase(it);
		dm.erase( dm.find(lst - fst) );
		ds.insert( Intv(fst,pos) );
		ds.insert( Intv(pos,lst) );
		dm.insert( pos - fst );
		dm.insert( lst - pos );
		cout << 1LL * *(wl.rbegin()) * *(hl.rbegin()) << endl;   
	}
}

int main() {
	init();
	solve();
	return 0;
}