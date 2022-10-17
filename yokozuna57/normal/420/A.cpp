#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
using namespace std;

bool f(char c){
	if(c=='A')return true;
	if(c=='H')return true;
	if(c=='I')return true;
	if(c=='M')return true;
	if(c=='O')return true;
	if(c=='T')return true;
	if(c=='U')return true;
	if(c=='V')return true;
	if(c=='W')return true;
	if(c=='X')return true;
	if(c=='Y')return true;
	return false;
}

int main(){
	string s;
	cin>>s;
	int n=s.size();
	bool t=true;
	for(int i=0;i<(n+1)/2;i++){
		if(!f(s[i]))t=false;
		if(s[i]!=s[n-1-i])t=false;
	}

	if(t)printf("YES\n");
	else printf("NO\n");


}