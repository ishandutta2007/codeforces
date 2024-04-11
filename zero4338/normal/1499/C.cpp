#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=1e5+5;
int n;
int c[maxn],mix,miy,numx,numy;
ll ans,sumx,sumy;
int main()
{
	T=read();
	while(T--)
	{
		generate_n(c+1,n=read(),read);
		sumx=mix=c[1];sumy=miy=c[2];numx=numy=1;
		ans=(ll)mix*n+(ll)miy*n;
		for(int i=3;i<=n;i++)
		{
			if(i&1)mix=min(mix,c[i]),numx++,sumx+=c[i];
			else miy=min(miy,c[i]),numy++,sumy+=c[i];
			ans=min(ans,(ll)(n-numx)*mix+sumx+(ll)(n-numy)*miy+sumy);
		}
		printf("%lld\n",ans);
	}
	return 0;
}