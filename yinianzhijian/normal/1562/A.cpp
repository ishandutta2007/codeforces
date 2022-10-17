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
int main(){
	int T=read();
	while(T--)
	{
		int l,r;
		l=read(),r=read();
		cout<<r-max(l,(r+2)/2)<<"\n";
	}
	return 0;
}