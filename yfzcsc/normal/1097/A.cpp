#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	for(int i=1;i<=5;++i){
		string t;
		cin>>t;
		if(s[0]==t[0]||s[1]==t[1]){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}