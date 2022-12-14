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
		for(int i= n - 1;i>=0;i--){
			if(s[i] != t[i]){
				if(s[0] == t[i]){
					op.emplace_back(0);
					s[0] = (int) s[0] ^ 1;
				}
				op.emplace_back(i);
				reverse(s.begin(), s.begin() + i + 1);
				for(int j=0;j<=i;j++)
					s[j] = (int) s[j] ^ 1;
			}
		}
		cout << op.size();
		for(int it:op)
			cout << ' ' << it + 1;
		cout << '\n';
	}
}