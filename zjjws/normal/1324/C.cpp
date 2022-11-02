#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=2e5+10;
char a[MAX];
bool f[MAX];
int n;
bool cheak(int x)
{
	//printf("%d.\n",x);
	memset(f,0,sizeof(f));
	int last=0;
	for(;last+x<=n;)
	{
		int now=last;
		for(int i=now+x;i>=now+1;i--)if(a[i]=='R'){last=i;break;}
		//printf("%d-->%d\n",now,last);
		if(last+x>n)return true;
		if(now==last)return false;
	}
	return true;
}
LL rin()
{
    LL s=0;
    bool bj=0;
    char c=getchar();
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')bj=1,c=getchar();
    while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^'0'),c=getchar();
    if(bj)return -s;
    return s;
}
int main()
{
    int i,j;
    int t=rin();
    for(;t>0;t--)
    {
    	cin>>(a+1);
    	n=strlen(a+1);
    	a[n+1]='R';
    	int l=1,r=n+1,mid;
    	int ans=n+1;
    	while(l<=r)
    	{
    		mid=(l+r)>>1;
    		if(cheak(mid))r=mid-1,ans=mid;
    		else l=mid+1;
		}
		printf("%d\n",ans);
	}
    
    return 0;
}