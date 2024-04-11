#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s="What are you doing at the end of the world? Are you busy? Will you save us?",
s1="What are you doing while sending _",
s2="_? Are you busy? Will you send _",
s3="_?";
long double len[101000];

char que(ll n,ll k){
	if (!n) return k<s.length()? s[k]: '.';
	if (k<s1.length()) return s1[k];
	k-=s1.length();
	if (n>=100||k<len[n-1]-0.5) return que(n-1,k);
	k-=(ll)(len[n-1]+0.5);
	if (k<s2.length()) return s2[k];
	k-=s2.length();
	if (n>=100||k<len[n-1]-0.5) return que(n-1,k);
	k-=(ll)(len[n-1]+0.5);
	if (k<s3.length()) return s3[k];
	return '.';
}

ll T,a,b;
int main(){
	len[0]=s.length();
	for (int i=1;i<100;i++) len[i]=len[i-1]*2+s1.length()+s2.length()+s3.length();
	for (cin>>T;T--;cout<<(que(a,b)=='_'?'"':que(a,b))) cin>>a>>b, --b;
}