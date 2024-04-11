//#define _GLIBCXX_IOSTREAM
#include<bits/stdc++.h>
using namespace std;
string s[110],t;
int n;
int main(){
	cin>>t>>n;
	for(int i=1;i<=n;++i)
		cin>>s[i];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if((s[i]+s[j]).find(t)!=string::npos)return puts("YES"),0;
	puts("NO");
}