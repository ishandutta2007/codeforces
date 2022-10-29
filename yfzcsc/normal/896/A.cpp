#include<bits/stdc++.h>
using namespace std;
string s="What are you doing at the end of the world? Are you busy? Will you save us?";
string t1="What are you doing while sending \"";
string t2="\"? Are you busy? Will you send \"";
string t3="\"?";
long long len[100];
char solve(int n,long long k){
	if(len[n]<k)return '.';
	if(n==0)return s[k-1];
	if(k<=t1.length())return t1[k-1];
	else if(k<=t1.length()+len[n-1])return solve(n-1,k-t1.length());
	else if(k<=t1.length()+len[n-1]+t2.length())return t2[k-t1.length()-len[n-1]-1];
	else if(k<=t1.length()+len[n-1]*2+t2.length())return solve(n-1,k-t1.length()-len[n-1]-t2.length());
	else return t3[k-t1.length()-len[n-1]*2-t2.length()-1];
}
int main(){
	int Q,n,M=0;
	long long k;
	len[0]=s.length();
	for(int i=1;len[i-1]<=(long long)1e18;++i)
		len[i]=t1.length()+len[i-1]+t2.length()+len[i-1]+t3.length(),M++;
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%lld",&n,&k);
		if(n<=M)putchar(solve(n,k));
		else if(k<=n*t1.length())putchar(t1[(k-1)%t1.length()]);
		else putchar(solve(M,k-(n-M)*t1.length()));
	} 
}