#include<bits/stdc++.h>
#define ll long long
//#define int long long
using namespace std;
char gc()
{
	return getchar();
//	static char buf[1<<16],*s,*t;
//	if(s==t)
//	{
//		t=(s=buf)+fread(buf,1,1<<16,stdin);
//		if(s==t)return EOF;
//	}
//	return *s++;
}
int read()
{
	char c;
	int w=1;
	while((c=gc())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=gc())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=3e5+5;
ll n,a[xx],b[xx],c[xx],t[xx];
int lb(int x){return x&-x;}
struct szsz
{
	ll sum[xx];
	void add(int x,int y){for(;x<=n;x+=lb(x))sum[x]+=y;}
	ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
}s1,s2,s3;
//s1s2set
//s3mod 
multiset<int>s;
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("b.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=b[i]=c[i]=read();
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)t[b[i]]=i,b[i]+=b[i-1];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		s.insert(a[i]);
		s1.add(t[a[i]],1);
		s2.add(t[a[i]],a[i]);
		if(s.find(a[i])!=--s.end())
		{
			ans+=a[i]*(s1.ask(t[*--s.end()])-s1.ask(t[a[i]]));//ii 
			int last=a[i];
			for(int j=a[i];j<=3e5;j+=a[i])
			{
				int o=*--s.upper_bound(j+a[i]-1);
				ans+=(s2.ask(t[o])-s2.ask(t[last]))-(s1.ask(t[o])-s1.ask(t[last]))*j;//iinlog^2 
				last=o;
			}
		}
		int ls=t[a[i]];
		for(int j=a[i];j<=3e5;j+=a[i])
		{
			int id=upper_bound(c+1,c+n+1,j+a[i]-1)-c-1;
			s3.add(ls,j);
			s3.add(id+1,-j);
//			if(j<=10)cout<<i<<' '<<j<<" "<<ls<<" "<<id<<"\n";
			ls=id+1;
		}
		if(s.find(a[i])!=s.begin())
		{
			ans+=s2.ask(t[a[i]]-1);//ii 
			ans+=s1.ask(t[a[i]])*a[i]-s3.ask(t[a[i]]);
//			int last=t[a[i]]-1;
//			for(int j=1;j<=108;j++)//208aj<=ai<=209aj 
//			{
//				if(s.lower_bound((a[i])/(j+1)+1)!=s.begin())
//				{
//					int o=*--s.lower_bound((a[i])/(j+1)+1);
//					ans+=a[i]*(s1.ask(last)-s1.ask(t[o]))-(s2.ask(last)-s2.ask(t[o]))*j;
//					last=t[o];
//				}
//				else 
//				{
//					ans+=a[i]*(s1.ask(last))-(s2.ask(last))*j;
//					break;
//				}
//			}
//			multiset<int>::iterator it=s.begin();
//			while((*it)*109<a[i])
//			{
//				ans+=a[i]%(*it);
//				it++;
//			}
		}
		cout<<ans<<' ';
	}
	return 0;
}