#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, U, R, D, L;
		cin >> n >> U >> R >> D >> L;
		bool ok = false;
		for(int i=0;i<16;i++) {
			int cu = U, cr = R, cd = D, cl = L; 
			if(i&1)
				cu--, cl--;
			if(i&2)
				cu--, cr--;
			if(i&4)
				cd--, cl--;
			if(i&8)
				cd--, cr--;
			if(min({cu,cd,cl,cr}) >= 0 && max({cu,cd,cl,cr})<=n-2)
				ok = true;
		}
		if(ok)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}