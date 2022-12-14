#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		vector<int> op;
		char cur = s[0];
		for(int i=1;i<n;i++)
			if(cur != s[i]){
				op.emplace_back(i-1);
				cur = (int) cur ^ 1;
			}
		for(int i=n-1;i>=0;i--)
			if(cur != t[i]){
				op.emplace_back(i);
				cur = (int) cur ^ 1;
			}
		cout << op.size();
		for(int it:op)
			cout << ' ' << it + 1;
		cout << '\n';
	}
}