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

int main(){
	int T=read();
	while(T--)
	{
		int n;
		n=read();
		for(int i=1;i<=n;i++)
		{
			char c;
			while((c=getchar())!='L'&&c!='R'&&c!='U'&&c!='D');
			if(c=='L'||c=='R')cout<<c;
			if(c=='D')cout<<'U';
			if(c=='U')cout<<'D';
		}
		puts("");
	}
	return 0;
}