#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n;
	while (cin >> n) {
		string s;
		cin >> s;
		string ans;
		for (int x=0;n>x;x++) {
			ans += " ";
		}
		int mid,t;
		
		if (n&1) {
			mid=n/2;
			t=1;
		}
		else {
			mid=(n/2)-1;
			t=-1;
		}
		int ss=0;
		int id=0;
		for (int x=0;n>x;x++) {
			ans[mid]=s[id++];
			t*=-1;
			ss++;
			mid += t*ss;
		}
		cout<<ans<<endl;
	}
}