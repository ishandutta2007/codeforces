#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e5+5;
char s[xx];
int main(){
	int T=read();
	while(T--)
	{
		int n=read();
		scanf("%s",s+1);
		if(n>1&&s[1]==s[2])
		{
			cout<<s[1]<<s[2]<<"\n";
			continue;
		}
		int id=n;
		for(int i=1;i<n;i++)
		{
			if(s[i]<s[i+1])
			{
				id=i;
				break;
			}
		}
//		while(id!=1&&s[id]==s[id-1])id--;
		for(int i=1;i<=id;i++)cout<<s[i];
		for(int i=id;i>=1;i--)cout<<s[i];puts("");
	}
	pc('1',1);
	return 0;
}