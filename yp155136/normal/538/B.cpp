#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main () {
	string s;
	while (cin >> s) {
		int mx=-1;
		for (auto i:s) {
			mx = max(mx,i-'0');
		}
		cout<<mx<<endl;
		while (mx--) {
			int need=0;
			int p=pow(10,s.size()-1);
			for (auto &i:s) {
				if (i>'0') {
					i-=1;
					need += p;
				}
				p/=10;
			}
			cout<<need;
			if(mx) cout<<' ';
		}
		cout<<endl;
	}
}