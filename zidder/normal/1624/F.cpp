#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int a = 0;
int n;
int prv = 0;

int ask(int c){
	if (c == 0) {
		return prv;
	}
	a += c;
	cout << "+ " << c << endl;
	cout.flush();
	int r;
	cin >> r;
	return r;
}

void answer(int x){
	(x += n - a % n) %= n;
	x += a;
	cout << "! " << x << endl;
}

void solve(int test_ind){
	cin >> n;
	int l = 1, r = n;
	while (l + 1 < r){
		// cout << l << " " << r << endl;
		int m = (l + r) / 2;
		int c = (n - m%n) % n;
		int v = ask(c);
		if (v == prv)
			r = m;
		else
			l = m;
		(l += c);
		(r += c);
		// cout << l << " " << r << endl;
		prv = v;
	}
	answer(l);
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}