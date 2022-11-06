#include <bits/stdc++.h>
using namespace std;
using ld=long double;
vector<int>as,bs;
bool check(vector<int>&v){
	map<int,int>mp;
	for(auto a:v)mp[a]++;
	bool ok= mp.size()==v.size();
	int ta=0,tb(0);
	for(int i=0;i<as.size();++i){
		ta+=as[i]==v[i];
		tb+=bs[i]==v[i];
	}
	return ok&&ta==as.size()-1&&tb==bs.size()-1;
}
int main() {
	int N;cin>>N;
	as.resize(N);
	bs.resize(N);
	for(int i=0;i<N;++i)cin>>as[i];
	for(int j=0;j<N;++j)cin>>bs[j];
	vector<int>difs;
	for(int i=0;i<N;++i){
		as[i]--;
		bs[i]--;
		if(as[i]!=bs[i])difs.push_back(i);
	}
	vector<int>ans;
	vector<int>notused(N);
	for(int i=0;i<N;++i){
		if(as[i]==bs[i])notused[as[i]]=true;
	}

	if(difs.size()==1){
		for(int i=0;i<N;++i){
			if(notused[i])continue;
			vector<int>mayans;
			for(int j=0;j<N;++j){
				if(j==difs[0]){
					mayans.push_back(i);
				}else{
					mayans.push_back(as[j]);
				}
			}
			if(check(mayans))ans=mayans;
		}
	}else{
		for(int ia=0;ia<N;++ia){
			if(notused[ia])continue;
			for(int ib=0;ib<N;++ib){
				if(notused[ib])continue;
				
				vector<int>mayans;
				for(int j=0;j<N;++j){
					if(j==difs[0]){
						mayans.push_back(ia);
					}else if(j==difs[1]){
						mayans.push_back(ib);
					}else{
						mayans.push_back(as[j]);
					}
				}
				if(check(mayans))ans=mayans;
			}
		}
	}
	for(int i=0;i<ans.size();++i){
		cout<<ans[i]+1;
		if(i==ans.size()-1)cout<<endl;
		else cout<<" ";
	}
	return 0;
}