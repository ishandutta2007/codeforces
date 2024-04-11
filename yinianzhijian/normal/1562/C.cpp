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
const int xx=2e4+5;
char s[xx];
int sum[xx];
int main(){
	int T=read();
	while(T--)
	{
		int n=read();
		scanf("%s",s+1);
		int op=0;
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+s[i]-'0';
		for(int i=n/2;i<=n;i++)
		{
			if(sum[i]-sum[i-n/2]==0)
			{
				cout<<i-n/2+1<<" "<<i<<" "<<1<<" "<<n<<'\n';
				op=1;
				break;
			}
		}
		if(op)continue;
		for(int i=1;i<=(n+1)/2;i++)
		{
			if(s[i]=='0')
			{
				cout<<i<<" "<<n<<" "<<i+1<<" "<<n<<'\n';
				op=1;
				break;
			}
		}
		if(op)continue;
		if(s[n/2+1]=='1')cout<<1<<" "<<n/2<<" "<<2<<" "<<n/2+1<<'\n';
		else cout<<1<<" "<<n/2+1<<" "<<1<<" "<<n/2<<" "<<'\n';
	}
	return 0;
}