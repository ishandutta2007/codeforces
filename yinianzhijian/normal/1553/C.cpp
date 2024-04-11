#include<bits/stdc++.h>
#define ll long long
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
const int xx=1005;
char s[xx];
signed main(){
	int t=read();
	while(t--)
	{
		scanf("%s",s+1);
		int t[2]={0,0};
		int minn=10;
		for(int i=1;i<=10;i++)
		{
			if(s[i]=='1')t[i&1]++;
			if(s[i]=='?'&&(i&1))t[i&1]++;
			if((i&1)&&t[i&1]-t[(i-1)&1]>((10-i+1)/2))minn=min(minn,i);
			if((!(i&1))&&t[(i-1)&1]-t[i&1]>((10-i+1)/2))minn=min(minn,i);
		}
		t[0]=t[1]=0;
		for(int i=1;i<=10;i++)
		{
			if(s[i]=='1')t[i&1]++;
			if(s[i]=='?'&&(!(i&1)))t[i&1]++;
			if((!(i&1))&&t[i&1]-t[(i-1)&1]>((10-i)/2))minn=min(minn,i);
			if((i&1)&&t[(i-1)&1]-t[i&1]>((10-i)/2))minn=min(minn,i);
		}
		cout<<minn<<'\n';
	}
	return 0;
}