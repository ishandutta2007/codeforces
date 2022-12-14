#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>q;
	while(q--){
		int n;
		long long int k;
		cin>>n>>k;
		string s;
		cin>>s;
		vector<int> zero;
		for(int i=0;i<n;i++)
			if(s[i]=='0'){
				zero.emplace_back(i);
				s[i]='1';
			}
		for(int i=0;i<zero.size();i++)
			if(k>=zero[i]-i){
				k-=(zero[i]-i);
				zero[i]=i;
			}
			else{
				zero[i]-=k;
				break;
			}
		for(int pos:zero)
			s[pos]='0';
		cout<<s<<'\n';
	}
}