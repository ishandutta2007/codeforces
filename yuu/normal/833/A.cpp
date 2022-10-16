#include <bits/stdc++.h>
using namespace std;
void solve(){
	long long a, b;
	cin>>a>>b;
	//can be reduced to at most two turns of first player win and second player win
	if(a>b) swap(a, b);
	if(a*a==b){
		cout<<"Yes\n";
		return;
	}
	//a=x^2*y
	//b=y^2*x
	long long ab=a*b;
	long long d=pow(ab, ((double)(1))/3)-5;
	d=max(d, 0LL);
	while(d*d*d<ab) d++;
	if(d*d*d!=ab){
		cout<<"No\n";
		return;
	}
	if(a%d||b%d){
		cout<<"No\n";
		return;
	}
	cout<<"Yes\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--) solve();
}