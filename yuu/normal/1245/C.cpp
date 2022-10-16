#include <bits/stdc++.h>
using namespace std;
string s;
const long long base=1000000007;
int f[100001];
int main(){
	cin>>s;
	f[0]=f[1]=1;
	for(int i=2; i<=100000; i++) f[i]=(f[i-1]+f[i-2])%base;
	long long ans=1;
	for(int i=0; i<s.size(); i++){
		if(s[i]!='u'&&s[i]!='n'){
			if(s[i]=='m'||s[i]=='w') ans=0;
		}
		else{
			int j=i;
			while((j+1<s.size())&&(s[j+1]==s[j])) j++;
			(ans*=f[j-i+1])%=base;
			i=j;
		}
	}
	cout<<ans<<'\n';
}