#include<bits/stdc++.h>
using namespace std;
const int L=5050,Base=233,mod=1000000009,T=13000000,root=0;
struct node
{
	int s[2],v;
}t[T]={};
char ch[L]={},ans[L]={};
int n,k,tot=0;
long long p[L]={1},hpre[L]={},hsuf[L]={};
bool dfs(int now,int d)
{
	if(k<=t[now].v)
	{
		puts(ans);
		return true;
	}
	k-=t[now].v;
	for(int c=0;c<2;++c)
		if(t[now].s[c])
		{
			ans[d]='a'+c;
			if(dfs(t[now].s[c],d+1))
				return true;
			ans[d]=0;
		}
	return false;
}
bool half_palindrome(int l,int r)
{
	int mid=(l+r)>>1,lp=0,rp=0;
	if((r-l)%2==0)
		lp=rp=mid;
	else
		lp=mid,rp=mid+1;
	if((lp-l)%2)
		--lp;
	if((r-rp)%2)
		++rp;
	long long h1=hpre[lp]+mod-(l==1 ? 0ll : hpre[l-2]);
	long long h2=hsuf[rp]+mod-hsuf[r+2];
	h1=h1*p[n-lp]%mod;
	h2=h2*p[rp-1]%mod;
	return h1==h2;
}
int main()
{	
	cin>>(ch+1)>>k;
	n=strlen(ch+1);
	for(int i=1;i<=n;++i)
		p[i]=p[i-1]*Base%mod;
	hpre[1]=ch[1]*p[1];
	for(int i=2;i<=n;++i)
		hpre[i]=(hpre[i-2]+ch[i]*p[i])%mod;
	for(int i=n;i>=1;--i)
		hsuf[i]=(hsuf[i+2]+ch[i]*p[n-i+1])%mod;

	for(int i=1;i<=n;++i)
	{
		int now=root;
		for(int j=i;j<=n;++j)
		{
			if(t[now].s[ch[j]-'a']==0)
				t[now].s[ch[j]-'a']=++tot;
			now=t[now].s[ch[j]-'a'];
			
			if(half_palindrome(i,j))
				++t[now].v;
		}
	}
	dfs(root,0);
	return 0;
}