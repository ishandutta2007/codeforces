#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		string s,h;
		cin>>s>>h;
		sort(s.begin(),s.end());
		bool ok=false;
		for(int i=0;i+s.size()<=h.size();i++){
			string t=h.substr(i,s.size());
			sort(t.begin(),t.end());
			if(s==t){
				ok=true;
				break;
			}
		}
		if(ok)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
	}
}