#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
	int n;cin>>n;
	string s;
	cin>>s;
	vector<bool> can(s.size(),true);
	rep(i,s.size()){
		if(s[i]=='<')
			can[i] = false;
		else
			break;
	}

	rep(i,s.size()){
		if(s[s.size()-1-i]=='>')
			can[s.size()-1-i]=false;
		else
			break;
	}

	int cnt = count(can.begin(), can.end(),false);
	cout<<cnt<<endl;
}