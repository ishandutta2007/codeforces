#include <bits/stdc++.h>
#define LL long long
using namespace std;
struct milk
{
	int s;
	int x;
}b[30];
bool vit[30];
string a;
inline bool myru(milk x,milk y){return x.s<y.s;}
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
	int n,k;
	cin>>a;
	n=a.length();
	k=rin();
	for(i=0;i<26;i++)b[i].x=i;
	for(i=0;i<n;i++)b[a[i]-'a'].s++;
	sort(b,b+26,myru);
	int ans=26;
	for(i=0;i<26;i++)if(b[i].s<=k)ans--,k-=b[i].s,vit[b[i].x]=true;
	printf("%d\n",ans);
	for(i=0;i<n;i++)if(!vit[a[i]-'a'])printf("%c",a[i]);
	return 0;
}