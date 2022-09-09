#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string s1="What are you doing while sending \"";
string s2="\"? Are you busy? Will you send \"";
string s3="\"?";
string s4="What are you doing at the end of the world? Are you busy? Will you save us?";
typedef long long ll;
const ll inf=1000000000000000001;
int q,n,i,dd=s1.size()+s2.size()+s3.size(),m;
ll k,f[100];
char solve(int n,ll k){
	if(n<m && k>f[n])return '.';
	if(n==1)return s4[k-1];
	ll x=n<m?f[n-1]:inf;
	if(k<=s1.size())return s1[k-1];
	if(n>=m || k<=s1.size()+x)return solve(n-1,k-s1.size());
	if(k<=s1.size()+x+s2.size())return s2[k-s1.size()-x-1];
	if(k>s1.size()+x*2+s2.size())return s3[k-s1.size()-x*2-s2.size()-1];
	return solve(n-1,k-s1.size()-x-s2.size());
}
int main(){
	cin>>q;
	for(f[1]=s4.size(),m=2;f[m-1]<=inf;f[m]=f[m-1]*2+dd,++m);
	while(q--){
		cin>>n>>k;++n;
		cout<<solve(n,k);
	}
	return 0;
}