#include<bits/stdc++.h>
#define ll long long
#define ld long double
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
int vis[500005];
int main(){
	int T=read();
	while(T--)
	{
		int a=read(),b=read();
		memset(vis,0,sizeof(vis[0])*(a+b+1));
		vector<int>v;
		int mn=a+b>>1;
//		cout<<mn<<'\n';
		for(int i=0;i<=mn;i++)
		{
			if(a-mn+i>=0&&a-mn+i<=(a+b-mn))
			{
				if(!vis[i+a-mn+i])
				{
					vis[i+a-mn+i]=1;
					v.push_back(i+a-mn+i);
				}
			}
		}
		mn=a+b-mn;
		for(int i=0;i<=mn;i++)
		{
			if(a-mn+i>=0&&a-mn+i<=(a+b-mn))
			{
				if(!vis[i+a-mn+i])
				{
					vis[i+a-mn+i]=1;
					v.push_back(i+a-mn+i);
				}
			}
		}
//		for(int i=0;i<=a+b;i++)
//		{
//			if((mn+i==a&&(a+b-mn)-i==b)||((a+b-mn)+i==a&&mn-i==b)||(mn+i==b&&(a+b-mn)-i==a)||((a+b-mn)+i==b&&mn-i==a))
//			{
//				v.push_back(i),vis[i]=1;
//				
//			}
//		}
		sort(v.begin(),v.end());
		cout<<v.size()<<"\n";
		for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
		puts("");
	}
	return 0;
}