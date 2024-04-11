#include <bits/stdc++.h>
using namespace std;
void solve(){
	int a, b;
	cin>>a>>b;
	if(__gcd(a, b)==1){
		cout<<"Finite\n";
	}
	else cout<<"Infinite\n";
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}