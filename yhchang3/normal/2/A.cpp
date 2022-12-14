#include<bits/stdc++.h>
using namespace std;

string s[1001];
int x[1001];

int main() {
	int n;
	cin >> n;
	map<string,int> m, mm;
	for(int i=1;i<=n;i++) {
		cin >> s[i] >> x[i];
		m[s[i]] += x[i];
	}
	int M = -1e9;
	for(auto it:m)
		M = max(M, it.second);
	for(int i=1;i<=n;i++) {
		mm[s[i]] += x[i];
		if(mm[s[i]] >= M && m[s[i]] == M) {
			cout << s[i] << endl;
			return 0;
		}
	} 
}