#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int cnt[30]={};
	for(int i=0;i<s.size();i++)cnt[s[i]-'a']++;
	
	while(1){
		int a=0,b=25;
		while(a<b&&cnt[a]%2==0)a++;
		while(a<b&&cnt[b]%2==0)b--;
		if(a==b)break;
		cnt[a]++; cnt[b]--;
	}
	
	string ret="";
	string mid="";
	for(int i=0;i<26;i++){
		ret+=string(cnt[i]/2,'a'+i);
		mid+=string(cnt[i]%2,'a'+i);
	}
	cout<<ret<<mid;
	reverse(ret.begin(),ret.end());
	cout<<ret<<endl;
}