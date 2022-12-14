#include<bits/stdc++.h>
using namespace std;

vector<pair<int,char> > v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	s.insert(0," ");
	for(int i=1;i<s.size();i++)
		if(s[i]==s[i-1])
			v.back().first++;
		else
			v.emplace_back(1,s[i]);
	int n=v.size();
	if(n%2==0||(v[n>>1].first<2))
		cout<<0<<endl;
	else{
		for(int i=0;i<(n>>1);i++)
			if(v[i].second!=v[n-i-1].second||v[i].first+v[n-i-1].first<3){
				cout<<0<<endl;
				return 0;
			}
		cout<<v[n>>1].first+1<<endl;
	}

}