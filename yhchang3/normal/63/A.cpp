#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> cap, rat, wc, m;
	while(n--) {
		string s, t;
		cin >> s >> t;
		if(t == "rat")
			rat.emplace_back(s);
		else if(t == "captain")
			cap.emplace_back(s);
		else if(t == "man")
			m.emplace_back(s);
		else
			wc.emplace_back(s);
	}
	for(auto x:rat)
		cout << x << '\n';
	for(auto x:wc)
		cout << x << '\n';
	for(auto x:m)
		cout << x << '\n';
	for(auto x:cap)
		cout << x << '\n';
}