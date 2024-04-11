#include<bits/stdc++.h>
using namespace std;
string s[500100];
int mn[500100];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;++i)cin>>s[i];
	for(int i=n-1,j;i>=1;--i){
		for(j=0;j<s[i].length()&&j<s[i+1].length();++j){
			if(s[i][j]>s[i+1][j]){
				s[i]=s[i].substr(0,j);goto end;
			} else if(s[i][j]<s[i+1][j])goto end;
		}
		if(s[i].length()>s[i+1].length())s[i]=s[i].substr(0,s[i+1].length());
		end:;
	}
//	mn[n]=s[n].length();
//	for(int i=n-1;i>=1;--i)mn[i]=min((int)s[i].length(),mn[i+1]);
	for(int i=1;i<=n;++i)
//	if(mn[i]>1)cout<<s[i]<<endl;else 
	cout<<s[i]<<endl;
}