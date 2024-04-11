#include <bits/stdc++.h>
using namespace std;
int n;
string s, t;
int main(){
	cin>>n>>s>>t;
	s='0'+s;
	t='0'+t;
	double ans=0;
	///i in s and j in t (i<j) ->i*(n-j+1)
	for(char c='A'; c<='Z'; c++){
		long long now=0;
		for(int i=1; i<=n; i++){
			if(s[i]==c)	now+=i;
			if(t[i]==c) ans+=now*(n-i+1);
		}
		now=0;
		for(int i=1; i<=n; i++){
			if(s[i]==c) ans+=now*(n-i+1);
			if(t[i]==c)	now+=i;
		}
	}
	long long sz=0;
	for(long long len=1; len<=n; len++) sz+=(n-len+1)*(n-len+1);
	cout<<setprecision(16)<<fixed<<(double(ans))/sz<<'\n';
}