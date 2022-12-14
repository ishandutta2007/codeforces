#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int> v;
		for(int i=1;i<=n;i++){
			v.emplace_back(n/i);
			i=n/(n/i);
		}
		v.emplace_back(0);
		reverse(v.begin(),v.end());
		cout<<v.size()<<'\n';
		for(int it:v)
			cout<<it<<' ';
		cout<<'\n';
	}
}