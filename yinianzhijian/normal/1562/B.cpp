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
const int xx=105;
int vis[xx];char s[xx];
int main(){
	for(int i=1;i<=100;i++)
	{
		int op=0;
		for(int j=2;j<i;j++)if(i%j==0)op=1;
		vis[i]=op;//10 
		vis[1]=1;
	}
	int T=read();
	while(T--)
	{
		int p=read();
		scanf("%s",s);
		int op=0;
		for(int i=0;i<p;i++)
		{
			if(vis[s[i]-'0'])
			{
				op=1;
				cout<<1<<'\n';
				cout<<s[i]<<"\n";
				break;
			}
		}
		if(op)continue;
		for(int i=0;i<p;i++)
		{
			for(int j=i+1;j<p;j++)
			{
				if(vis[(s[i]-'0')*10+s[j]-'0'])
				{
					op=1;
					cout<<2<<'\n';
					cout<<s[i]<<s[j]<<"\n";
					break;
				}
			}
			if(op)break;
		}
	}
	return 0;
}