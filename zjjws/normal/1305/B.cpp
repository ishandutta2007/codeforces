#include <bits/stdc++.h>
#define LL long long
using namespace std;
char a[1010];
int x[1010];
int y[1010];
int z[1010];
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
    int t1,t2;
    int h;
    cin>>a;
    int n=strlen(a);
    t1=t2=0;
    h=1;
	for(i=0;i<n;i++)
	if(a[i]=='(')x[++t1]=i+1;
    else y[++t2]=i+1;
    
    int ans=0;
    for(i=h,j=t2;i<=t1&&j>0&&x[i]<y[j];)
    {
    	z[++ans]=x[i],z[++ans]=y[j];
    	i++;j--;
	}
	if(ans>0)
	{
	printf("1\n%d\n",ans);
	sort(z+1,z+ans+1);
	for(i=1;i<=ans;i++)printf("%d ",z[i]);		
	}
	else printf("0");
    return 0;
}