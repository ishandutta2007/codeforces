#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

int main () {
	int n;
	while (cin >> n) {
		multiset<char> st;
		string s;
		cin >> s;
		int ans=0;
		for (auto i:s) {
			if (i<='Z') {
				if (st.find(i+('a'-'A')) != st.end()) {
					st.erase(st.find(i+'a'-'A'));
				}
				else {
					ans++;
				}
			}
			else {
				st.insert(i);
			}
		}
		cout<<ans<<endl;
	}
}