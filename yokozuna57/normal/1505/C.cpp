#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int a[12];
	for(int i=0;i<s.size();i++){
		a[i]=s[i]-'A';
	}
	bool ret=true;
	for(int i=0;i+2<s.size();i++){
		if((a[i]+a[i+1])%26==a[i+2]){}
		else ret=false;
	}
	if(ret)puts("YES");
	else puts("NO");
}