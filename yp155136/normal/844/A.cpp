#include <iostream>
#include <stdio.h>
#include <set>
#include <cmath>
using namespace std;

int main () {
	string s;
	cin >> s;
	int k;
	cin >> k;
	if (k > s.size()) puts("impossible");
	else {
		int cnt=0;
		set<char> st;
		for (char i:s) {
			if (st.find(i) == st.end()) {
				cnt++;
				st.insert(i);
			}
		}
		cout<<max(0,k-cnt)<<endl;
	}
}