#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s;
	char now='z';
	for(int i=0; i<s.size(); i++){
		now=min(now, s[i]);
		if(s[i]>now) cout<<"Ann\n";
		else cout<<"Mike\n";
	}
}