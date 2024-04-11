#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n;
char s[maxn];
int nxt[maxn];
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	nxt[1]=n;
	for(int i=2,l=0,r=0;i<=n;i++)
	{
		if(i<=r)nxt[i]=min(nxt[i-l+1],r-i+1);
		while(i+nxt[i]<=n&&s[i+nxt[i]]==s[nxt[i]+1])nxt[i]++;
		if(i+nxt[i]-1>r)r=i+nxt[i]-1,l=i;
	}
	int mx=0;
	for(int i=2;i<=n;i++)
	{
		if(i+nxt[i]==n+1&&mx>=nxt[i]){puts(s+i);return 0;}
		mx=max(mx,nxt[i]);
	}
	puts("Just a legend");
	return 0;
}