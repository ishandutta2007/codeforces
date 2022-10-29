#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

int main () {
	string s;
	while (cin >> s) {
		s="A" + s + "A";
		set<char> st;
		st.insert('A');
		st.insert('E');
		st.insert('I');
		st.insert('O');
		st.insert('U');
		st.insert('Y');
		int ans = 0;
		for (int i=0;s.size()>i;i++) {
			if (st.find(s[i]) != st.end()) {
				for (int j=i+1;s.size()>j;j++) {
					if (st.find(s[j]) != st.end()) {
						ans = max(ans,j-i);
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}