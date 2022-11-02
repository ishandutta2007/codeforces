#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=300005;
int n,_x,_y,a[N];
LL x,y;
char s[N];
int main(){
	scanf("%d%d%d",&n,&_x,&_y);
	x=_x,y=_y;
	scanf("%s",s+1);
	a[1]=s[1]-'0';
	int _n=1;
	for (int i=2;i<=n;i++)
		if (s[i]!=s[i-1])
			a[++_n]=s[i]-'0';
	int tot=0;
	for (int i=1;i<=_n;i++)
		if (a[i]==0)
			tot++;
	LL ans=0;
	if (x>y)
		ans=y*tot;
	else
		ans=x*(tot-1)+y;
	if (tot==0)
		ans=0;
	printf("%I64d",ans);
	return 0;
}