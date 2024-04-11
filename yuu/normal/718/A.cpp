#include <bits/stdc++.h>
using namespace std;
int n, t;
string s;
int main(){
	cin>>n>>t>>s;
	vector <int> before, after;
	bool seen=0;
	for(char c: s) if(c=='.') seen=1; else if(seen) after.push_back(c-48); else before.push_back(c-48);
	int old=0;
	while(t--){
		if(after.empty()) break;
		bool good=0;
		for(int i=old; i<after.size(); i++) if(after[i]>=5){
			while(after.size()>i+1) after.pop_back();
			good=1;
			if(i==0){
				before.back()++;
			}
			else{
				after[i-1]++;
			}
			after.pop_back();
			old=i-1;
			break;
		}
		if(!good) break;
	}
	reverse(before.begin(), before.end());
	for(int i=0; i<before.size(); i++) if(before[i]==10){
		if(i+1==before.size()) before.push_back(0);
		before[i+1]++;
		before[i]=0;
	}
	reverse(before.begin(), before.end());
	for(int x: before) cout<<x;
	if(!after.empty()){
		cout<<'.';
		for(int x: after) cout<<x;
	}
}