#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	int a, b, c, d;
	cin>>t;
	string res[]={"Tidak", "Ya"};
	while(t--){
		cin>>a>>b>>c>>d;
		int neg=(a+b)%2;
		int pos=1-neg;
		int large=(a+d)>0;
		int small=(b+c)>0;
		cout<<res[large*neg]<<" "<<res[small*neg]<<' '<<res[small*pos]<<" "<<res[large*pos]<<'\n';
	}
}