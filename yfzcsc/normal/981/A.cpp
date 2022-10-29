#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<=s.length();++i)
		for(int j=0;i+j<=s.length();++j){
			string a,b;
			a=b=s.substr(j,i);
			reverse(b.begin(),b.end());
			if(a!=b)ans=i;
		}
	printf("%d",ans);
}