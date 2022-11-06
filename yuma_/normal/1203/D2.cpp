#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using ld=long double;


int main() {
	ios::sync_with_stdio(false);
	string S,T;cin>>S>>T;
	vector<int>ls(S.size()+1),rs(S.size()+1);
	ls[0]=0;
	for(int i=0;i<S.size();++i){
		if(ls[i]==T.size()){
			ls[i+1]=T.size();
		}else{
			ls[i+1]=ls[i];
			if(S[i]==T[ls[i]]){
				ls[i+1]=ls[i]+2-1;
			}
		} 
	}
	rs[S.size()]=T.size();
	for(int i=S.size();i>=1;--i){
		if(rs[i]==0){
			rs[i-1]=0;
		}else{
			rs[i-1]=rs[i];
			if(S[i-1]==T[rs[i]-1]){
				rs[i-1]=rs[i]-1;
			}
		}
	}
	//cout<<0<<endl;
	//  aaabbb
	// ab
	// 0111222
	//  2221110
	//  0001112

	for(int i=0;i<ls.size();++i){
		//cout<<ls[i]<<' '<<rs[i]<<endl;
	}

	int answer=0;
	for(int l=0;l<=S.size();++l){
		int num=ls[l];
		int need=num;
		auto it=upper_bound(rs.begin(),rs.end(),num);

		int nans=(it-rs.begin())-l-1;
		answer=max(answer,nans);
	}
	cout<<answer<<endl;
	return 0;
}