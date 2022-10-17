#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
int a[300005];
int b[300005];
int lastans;
int mx[415][415];
int mix[415][415];
int id[300005];
int st[300005];
int ed[300005];
int t[300005];
int sum[415][300005];
signed main(){
//	cout<<sizeof(sum)/1024/1024<<"\n";
//	freopen("a.in","r",stdin);
//	freopen("b.out","w",stdout);
	n=read();
	m=read();
	int B=ceil(n/410.0);
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]=a[i];
		id[i]=(i-1)/B+1;
		if(!st[id[i]])st[id[i]]=i;
		ed[id[i]]=i;
	}
	int tot;
	sort(b+1,b+n+1);
	tot=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
	}
	int z=id[n];
	for(int i=1;i<=z;i++)
	{
		memset(t,0,sizeof(t));
		int maxxs=0;
		int ooo=0;
		for(int j=i;j<=z;j++)
		{
			for(int k=st[j];k<=ed[j];k++)
			{
				t[a[k]]++;
				if(t[a[k]]==ooo&&maxxs>a[k])maxxs=a[k];
				if(t[a[k]]>ooo)ooo=t[a[k]],maxxs=a[k];
			}
			mx[i][j]=maxxs;
			mix[i][j]=t[maxxs];
		}
	}
//	return 0;
	for(int i=1;i<=id[n];i++)
	{
		for(int j=1;j<=tot;j++)sum[i][j]=sum[i-1][j];
		for(int j=st[i];j<=ed[i];j++)sum[i][a[j]]++;
//		cout<<i<<" "<<j<<" "<<cst<<'\n';
//		for(int j=1;j<=3;j++)cout<<i<<" "<<j<<" "<<sum[i][j]<<endl;
	}
	while(m--)
	{
		int s,e;
		s=read();
		e=read();
//		s=(s+lastans-1)%n+1;
//		e=(e+lastans-1)%n+1;
		if(s>e)swap(s,e);
		int now=0;
		if(id[e]-id[s]<=1)
		{
//			cout<<"wqeqwe"<<endl;
			int maxxs=0;
			int ooo=0;
			for(int i=s;i<=e;i++)t[a[i]]=0;
			for(int i=s;i<=e;i++)
			{
				t[a[i]]++;
				if(t[a[i]]==ooo&&maxxs>a[i])maxxs=a[i];
				if(t[a[i]]>ooo)ooo=t[a[i]],maxxs=a[i];
//				cout<<ooo<<' '<<maxxs<<endl;
			}
			now=ooo;
//			printf("%d\n",(lastans=b[maxxs]));
		}
		else 
		{
			int maxxs=0;
			int ooo=0;
			for(int i=s;i<=ed[id[s]];i++)
			{
				t[a[i]]=0;
			}
			for(int i=st[id[e]];i<=e;i++)
			{
				t[a[i]]=0;
			}
			t[mx[id[s]+1][id[e]-1]]=sum[id[e]-1][mx[id[s]+1][id[e]-1]]-sum[id[s]][mx[id[s]+1][id[e]-1]];
			for(int i=s;i<=ed[id[s]];i++)
			{
				t[a[i]]=sum[id[e]-1][a[i]]-sum[id[s]][a[i]];
			}
			for(int i=st[id[e]];i<=e;i++)
			{
				t[a[i]]=sum[id[e]-1][a[i]]-sum[id[s]][a[i]];
			}
			for(int i=s;i<=ed[id[s]];i++)
			{
				t[a[i]]++;
				if(t[a[i]]==ooo&&maxxs>a[i])maxxs=a[i];
				if(t[a[i]]>ooo)ooo=t[a[i]],maxxs=a[i];
			}
			for(int i=st[id[e]];i<=e;i++)
			{
				t[a[i]]++;
				if(t[a[i]]==ooo&&maxxs>a[i])maxxs=a[i];
				if(t[a[i]]>ooo)ooo=t[a[i]],maxxs=a[i];
			}
			int as=mix[id[s]+1][id[e]-1]+t[mx[id[s]+1][id[e]-1]]-sum[id[e]-1][mx[id[s]+1][id[e]-1]]+sum[id[s]][mx[id[s]+1][id[e]-1]];
			if(ooo>as)
			{
				lastans=maxxs;
//				ooo=as;
			}
			else if(ooo==as&&maxxs<mx[id[s]+1][id[e]-1])
			{
				lastans=maxxs;
			}
			else lastans=mx[id[s]+1][id[e]-1],ooo=as;
			now=ooo;
//			printf("%d\n",(lastans=b[lastans]));
		}
//		cout<<now<<"\n";
		if(now<=(e-s+2)/2)puts("1");
		else cout<<now-((e-s+1)-now)<<"\n";
	}
	return 0;
}
/*
100 1
1 2 3 5 5 5 5 1 3 5 1 2 3 5 5 5 5 1 3 5 1 2 3 5 5 5 5 1 3 5 1 2 3 5 5 5 5 1 3 5 1 2 3 5 5 5 5 1 3 5 1 2 3 5 5 5 5 1 3 5 1 2 3 5 5 5 5 1 3 5 1 2 3 5 5 5 5 1 3 5 1 2 3 5 5 5 5 1 3 5 1 2 3 5 5 5 5 1 3 5 
1 100
*/