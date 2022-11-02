#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#define REP(i,n) for(int i=0;i<n;i++)
#define PB push_back
using namespace std;
const int MAX_N = 100+10;
typedef long long int64;
int64 dp[MAX_N][2][2]={};//i,first,last
string s;
int n;

string my;

map<string,int64> mp[MAX_N];

string trans(string a,bool cyc=true){
	int n=a.size();
	static bool swp[MAX_N]={};
	for(int i=0;i<a.size();i++){
		if(a[i]=='A'&&a[(i+1)%n]=='B')
			swp[i]=true;
		else
			swp[i]=false;
	}
	if(!cyc)swp[n-1]=false;
	REP(i,a.size())if(swp[i])
		swap(a[i],a[(i+1)%n]);
	return a;
}

int64 rec(int at){
	//check it
	if(at>2){
		string t=trans(my.substr(0,at),false);
		if(t.size()>2 && t.substr(1,t.size()-2) != s.substr(1,t.size()-2))
			return 0;
	}
		
	string key=my.substr(0,min(3,at));
	key+=" "+my.substr(max(0,at-3),3);
	if(mp[at].count(key))
		return mp[at][key];
	int64&ret=mp[at][key]=0;
	if(at==n){
		string t=trans(my);
		return ret=s==t;
	}
	my[at]='A';
	ret+=rec(at+1);
	my[at]='B';
	ret+=rec(at+1);
	return ret;
}

int main(){
	cin>>s;
	n=s.size();
	my=s;
	cout<<rec(0)<<endl;
	return 0;
}