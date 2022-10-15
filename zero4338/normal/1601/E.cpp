#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=3e5+5;
int n,m,k,a[maxn];
vector<int>mi[maxn];
vector<ll>f[maxn];
vector<vector<int>>st[maxn];
deque<int>q;
void move(int l,int r)
{
	static int nr=0;
	while(nr<r)
	{
		nr++;
		while(!q.empty()&&a[q.back()]>=a[nr])q.pop_back();
		q.push_back(nr);
	}
	while(!q.empty()&&q.front()<l)q.pop_front();
}
void prework(vector<int>&a,vector<ll>&f,vector<vector<int>>&st)
{
	static stack<int>s;while(!s.empty())s.pop();
	if(a.empty())return;
	f.resize(a.size());
	for(int i=a.size()-1;i>=0;i--)
	{
		while(!s.empty()&&a[s.top()]>a[i])s.pop();
		if(!s.empty())f[i]=(ll)(s.top()-i)*a[i]+f[s.top()];
		else f[i]=(ll)(a.size()-i)*a[i];
		s.push(i);
	}
	st.resize(log2(a.size())+1,vector<int>(a.size()));
	for(int i=0;i<st[0].size();i++)st[0][i]=i;
	for(int i=1;(1<<i)<=a.size();i++)
	{
		for(int j=0;j+(1<<i)-1<a.size();j++)
		{
			if(a[st[i-1][j]]<a[st[i-1][j+(1<<(i-1))]])st[i][j]=st[i-1][j];
			else st[i][j]=st[i-1][j+(1<<(i-1))];
		}
	}
}
int querymi(vector<int>&ori,vector<vector<int>>&st,int l,int r)
{
	int k=log2(r-l+1);
	if(ori[st[k][l]]<ori[st[k][r-(1<<k)+1]])return st[k][l];
	return st[k][r-(1<<k)+1];
}
ll query(int l,int r)
{
	if(l+k>r)return a[l];
	int be=(l-1)/k,ed=be+(r-l)/k-1,mp=querymi(mi[l%k],st[l%k],be,ed);
	return a[l]+f[l%k][be]-f[l%k][mp]+(ll)mi[l%k][mp]*(ed-mp+1);
}
int main()
{
	n=read();m=read();k=read();generate_n(a+1,n,read);
	for(int i=k+1;i<=n;i++){move(i-k,i);mi[i%k].push_back(a[q.front()]);}
	for(int i=0;i<k;i++)prework(mi[i],f[i],st[i]);
	while(m--)
	{
		int l=read(),r=read();
		printf("%lld\n",query(l,r));
	}
	return 0;	
}