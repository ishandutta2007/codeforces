#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=2e5+3;
LL a[MAX];
LL rin()
{
	LL s=0;
	char c=getchar();
	bool bj=0;
	for(;(c>'9'||c<'0')&&c!='-';c=getchar());
	if(c=='-')bj=1,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
	if(bj)return -s;
	return s;
}
int main()
{
    int i,j;
    int n=rin();
    for(i=1;i<=n;i++)a[i]=rin();sort(a+1,a+n+1);
    int l,r;
    r=1;
    int ans=1;
    for(l=1;l<=n;l++){for(;r<n&&a[r+1]-a[l]<=5;r++);ans=max(ans,r-l+1);}
    printf("%d",ans);
	return 0;
}