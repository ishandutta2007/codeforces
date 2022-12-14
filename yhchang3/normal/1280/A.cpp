#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int x;
		string s;
		cin>>x>>s;
		long long int r=s.size();
		s.insert(0," ");
		for(int i=1;i<=x;i++){
			r=(r+mod-1)%mod;
			int y=s[i]-'0';
			r=r*y%mod;
			if(s.size()>=x+10)
				continue;
			string tmp=s.substr(i+1);
			for(int j=1;j<y;j++){
				s+=tmp;
				if(s.size()>=x+10)
					break;
			}
		}
		cout<<(x+r)%mod<<'\n';
	}
}