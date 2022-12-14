#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	set<int> st;
	for(int i=0,x;i<n;i++)
		cin >> x, st.insert(x);
	if(next(st.begin()) == st.end())
		cout << "NO" << endl;
	else
		cout << *next(st.begin()) << endl;
}