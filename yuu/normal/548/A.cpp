#include <bits/stdc++.h>
using namespace std;
string s;
int k;
bool done[1000][1000];
bool p[1000][1000];
bool P(int l, int r){
	if(l>=r) return 1;
	if(done[l][r]) return p[l][r];
	if(s[l]!=s[r]) return p[l][r]=0;
	else return p[l][r]=P(l+1, r-1);
}
int main(){
	cin>>s>>k;
	if(s.size()%k){
		cout<<"NO\n";
		return 0;
	}
	k=s.size()/k;
	for(int i=0, j=k-1; i<s.size(); i+=k, j+=k){
		if(!P(i, j)){
			cout<<"NO\n";
			return 0;
			
		}
	}
	cout<<"YES\n";
}