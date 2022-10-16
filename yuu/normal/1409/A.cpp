#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t, a, b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		a=abs(a-b);
		if(a==0) cout<<"0\n";
		else cout<<(a-1)/10+1<<'\n';
	}
}