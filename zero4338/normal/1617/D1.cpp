#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e4+5;
int T;
int n;
bool query(int i,int j,int k)
{
	printf("? %d %d %d\n",i,j,k);fflush(stdout);
	return read();
}
bool res[maxn],ans[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();	
		for(int i=1;i<=n;i++)ans[i]=0;
		for(int i=1;i<=n;i+=3)
			res[i]=query(i,i+1,i+2);
		int p=0;
		for(int i=1;i<=n;i+=3)if(res[i]^res[i+3]){p=i;break;}
		bool ans1=query(p+1,p+2,p+3),ans2=query(p+2,p+3,p+4);
		int p0=0,p1=0;
		if(res[p]!=ans1)
		{
			if(res[p]==0)p0=p,p1=p+3;
			else p0=p+3,p1=p;
		}
		else if(ans1!=ans2)
		{
			if(ans1==0)p0=p+1,p1=p+4;
			else p0=p+4,p1=p+1;
		}
		else if(ans2!=res[p+3])
		{
			if(ans2==0)p0=p+2,p1=p+5;
			else p0=p+5,p1=p+2;
		}
		for(int i=1;i<=n;i+=3)
		{
			if(i==p||i==p+3)continue;
			if(res[i])
			{
				bool ans1=query(p0,i,i+1),ans2=query(p0,i+2,i+1);
				if(ans1==ans2&&ans1==1)ans[i]=ans[i+1]=ans[i+2]=1;
				else if(ans1==ans2&&ans1==0)ans[i]=1,ans[i+1]=0,ans[i+2]=1;
				else if(ans1==0)ans[i]=0,ans[i+1]=ans[i+2]=1;
				else ans[i]=ans[i+1]=1,ans[i+2]=0;
			}
			else
			{
				bool ans1=query(p1,i,i+1),ans2=query(p1,i+2,i+1);
				if(ans1==ans2&&ans1==0)ans[i]=ans[i+1]=ans[i+2]=0;
				else if(ans1==ans2&&ans1==1)ans[i]=0,ans[i+1]=1,ans[i+2]=0;
				else if(ans1==0)ans[i]=ans[i+1]=0,ans[i+2]=1;
				else ans[i]=1,ans[i+1]=ans[i+2]=0;
			}
		}
		for(int i=p;i<=p+5;i++)
		{
			if(i==p0||i==p1)continue;
			ans[i]=query(i,p0,p1);
		}
		ans[p0]=0;ans[p1]=1;
		vector<int>pos;
		for(int i=1;i<=n;i++)if(!ans[i])pos.push_back(i);
		printf("! %lu ",pos.size());
		for(int &i:pos)printf("%d ",i);putchar('\n');fflush(stdout);
	}
	return 0;
}