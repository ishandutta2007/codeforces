#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=505;
int T,n;
int a[maxn],b[maxn];
vector<pair<int,int>>ans;
int main()
{
	T=read();
	for(int t=1;t<=T;t++)
	{
		n=read();
		generate_n(a+1,n,read);
		generate_n(b+1,n,read);
		ans.clear();
		bool flag=true;
		if(a[1]!=b[1])flag=false;
		else
		{
			for(int i=2;i<=n;i++)
			{
				if(a[i]==b[i])continue;
				bool ok=false;
				for(int j=i;j<n;j++)
					if(a[j]==b[i]&&a[j+1]==a[i-1])
					{
						ans.push_back({i-1,j+1});
						reverse(a+i-1,a+j+2);
						ok=true;
						break;
					}
				if(!ok)
				{
					static int pos[maxn];
					for(int i=1;i<=n;i++)pos[i]=0;
					int pos0=-1,pos1=-1,pos2=-1;
					for(int j=i;j<=n;j++)
					{
						pos[a[j]]=j;
						if(a[j]==a[i-1]&&a[j+1]==b[i])
						{
							pos0=j;
							pos1=-1;pos2=-1;
							for(int k=j+1;k<=n;k++)
								if(pos[a[k]])
								{
									pos2=k;
									pos1=pos[a[k]];
									ok=true;
									break;
								}
							if(ok)break;
						}
					}
					if(ok)
					{
						ans.push_back({pos1,pos2});
						reverse(a+pos1,a+pos2+1);
						for(int j=i;j<n;j++)
						if(a[j]==b[i]&&a[j+1]==a[i-1])
						{
							ans.push_back({i-1,j+1});
							reverse(a+i-1,a+j+2);
							break;
						}
					}
				}
				if(!ok){flag=false;break;}	
			}
		}
		if(!flag)puts("NO");
		else
		{
			puts("YES");
			printf("%lu\n",ans.size());
			for(auto&[l,r]:ans)printf("%d %d\n",l,r);
		}
	}
	return 0;
}