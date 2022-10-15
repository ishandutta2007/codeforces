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
const int maxn=2e5+5;
int n,k;
vector<int>s;
int sa[maxn],rk[maxn],h[maxn],be[maxn],st[21][maxn];
void build()
{
	static int x[maxn],y[maxn],c[maxn];
	int n=s.size()-1,m='z'+1e5;
	for(int i=1;i<=n;i++)x[i]=s[i],c[s[i]]++;
	for(int i=1;i<=m;i++)c[i]+=c[i-1];
	for(int i=1;i<=n;i++)sa[c[x[i]]--]=i;
	for(int k=1;k<=n;k<<=1)
	{
		int num=0;
		for(int i=n;i>=n-k+1;i--)y[++num]=i;
		for(int i=1;i<=n;i++)if(sa[i]>k)y[++num]=sa[i]-k;
		for(int i=1;i<=m;i++)c[i]=0;
		for(int i=1;i<=n;i++)c[x[i]]++;
		for(int i=1;i<=m;i++)c[i]+=c[i-1];
		for(int i=n;i>=1;i--)sa[c[x[y[i]]]--]=y[i],y[i]=0;
		swap(x,y);
		x[sa[1]]=1;num=1;
		for(int i=2;i<=n;i++)x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?num:++num;
		if(num==n)break;
		m=num;
	}
	for(int i=1;i<=n;i++)rk[sa[i]]=i;
	for(int i=1,j=0;i<=n;i++)
	{
		if(rk[i]==1)continue;
		if(j)j--;
		int p=sa[rk[i]-1];
		while(j+p<=n&&j+i<=n&&s[j+p]==s[j+i])j++;
		h[rk[i]]=j;
	}
	for(int i=1;i<=n;i++)st[0][i]=h[i];
	for(int i=1;(1<<i)<=n;i++)for(int j=1;j+(1<<i)-1<=n;j++)st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
int query(int l,int r)
{
	l++;int k=log2(r-l+1);
	return min(st[k][l],st[k][r-(1<<k)+1]);
}
int exi[maxn],cur;
void add(int p){exi[be[p]]++;if(exi[be[p]]==1)cur++;}
void del(int p){exi[be[p]]--;if(exi[be[p]]==0)cur--;}
int mx[maxn];ll ans[maxn];
int main()
{
	n=read();k=read();s={0};
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			string t;cin>>t;
			printf("%lld ",(ll)t.size()*(t.size()+1)/2);
		}
		putchar('\n');
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		string t;cin>>t;
		for(char &c:t)s.push_back(c-'a');
		s.push_back(100+i);
	}
	build();
	int now=1;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]<26)be[i]=now;
		else now++;
	}
	deque<pair<int,int>>q;
	int r=0;
	for(int l=1;l<s.size();l++)
	{
		while(r+1<s.size()&&cur<k)add(sa[++r]);
		if(cur==k)
		{
			int now=query(l,r);
			while(!q.empty()&&q.back().second<now)q.pop_back();
			q.push_back({r,now});
		}
		del(sa[l]);
		while(!q.empty()&&q.front().first<l)q.pop_front();
		if(!q.empty())mx[l]=max(mx[l],q.front().second);
	}
	cur=0;for(int i=1;i<=n;i++)exi[i]=0;q.clear();
	int l=s.size();
	for(int r=s.size()-1;r>=1;r--)
	{
		while(l>1&&cur<k)add(sa[--l]);
		if(cur==k)
		{
			int now=query(l,r);
			while(!q.empty()&&q.back().second<now)q.pop_back();
			q.push_back({l,now});
		}
		del(sa[r]);
		while(!q.empty()&&q.front().first>r)q.pop_front();
		if(!q.empty())mx[r]=max(mx[r],q.front().second);
	}
	for(int i=1;i<s.size();i++)ans[be[sa[i]]]+=mx[i];
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);putchar('\n');
	return 0;
}