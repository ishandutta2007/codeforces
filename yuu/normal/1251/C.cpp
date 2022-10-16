#include <bits/stdc++.h>
using namespace std;
string a;
void solve(){
	string a;
	cin>>a;
	string b, c;
	for(char &x: a) if(x%2) b+=x; else c+=x;
	merge(b.begin(), b.end(), c.begin(), c.end(), a.begin());
	cout<<a<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}