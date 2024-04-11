#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int maxn=2e6+5;

int n,c[maxn],cnt[maxn],d0,d[maxn];

int T;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		fo(i,1,n) scanf("%d",&c[i]), cnt[c[i]]++;
		
		d0=0;
		fo(i,1,n) if (cnt[c[i]]) d[++d0]=cnt[c[i]], cnt[c[i]]=0;
		int nmin=maxn;
		fo(i,1,d0) nmin=min(nmin,d[i]);
		
		int ans=n;
		fo(s,1,nmin+1)
		{
			int ans1=0;
			bool pd=1;
			fo(i,1,d0)
			{
				int t=(d[i]+s-1)/s;
				if (t*(s-1)>d[i]) pd=0; else ans1+=t;
			}
			if (pd) ans=min(ans,ans1);
		}
		
		printf("%d\n",ans);
	}
}