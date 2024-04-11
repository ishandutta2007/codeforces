#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	set<string> st;
	while(getline(cin, s)) {
		st.insert(s);
	}
	cout << st.size() << endl;
}