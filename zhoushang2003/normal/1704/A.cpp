#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,v;
string s,t;
signed main(){
	for(cin>>n;cin>>n>>m>>s>>t;){
		v=0;
		for(int i=0;i<=n-m;i++)
			if(s[i]==t[0])
				v=1;
		puts(v&&(m==1||s.substr(n-m+1,m-1)==t.substr(1,m-1))?"YES":"NO");
	}
}