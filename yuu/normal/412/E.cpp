#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	long long ans=0;
	for(int i=0; i<s.size(); i++) if(s[i]=='@'){
		int j=i+1;
		while((j<s.size())&&(s[j]!='.')&&(s[j]!='@')) j++;
		if(j>=s.size()) break;
		if(s[j]=='@'){
			i=j-1;
			continue;
		}
		if(j!=i+1){
			long long x=0;
			long long y=0;
			long long z=1;
			for(int k=i-1; (k>=0)&&(s[k]!='.')&&(s[k]!='@'); k--)	x+=bool(isalpha(s[k]));
			for(int k=j+1; (k<s.size())&&(isalpha(s[k])); k++) y++;
			for(int k=i+1; k<j; k++) if(!isalnum(s[k]))	z=0;
			ans+=x*y*z;
		}
		i=j;
	}
	cout<<ans<<'\n';
}