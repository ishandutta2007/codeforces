#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define ll long long
string s[1510];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char tmp;cin>>tmp;
			if(tmp=='S')s[i].push_back(0);
			if(tmp=='E')s[i].push_back(1);
			if(tmp=='T')s[i].push_back(2);
		}
	}

	map<string,int> mp;
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			string vec;
			for(int k=0;k<m;k++){
				vec+=(s[j][k]+s[i][k])%3;
			}
			if(mp.find(vec) != mp.end()) ans += mp[vec];
		}
		string vec;
		for(auto &it:s[i]){
			vec+=(3-it)%3;
		}
		mp[vec]++;
	}
	cout<<ans<<endl;
}