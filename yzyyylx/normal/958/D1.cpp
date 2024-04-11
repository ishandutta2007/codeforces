#include<iostream>
#include<cstdio>
#include<map>
#define ll long long
#define db double
#define C ch=getchar()
#define N 200100
using namespace std;

int n;
char ch;
db a,b,c,ans[N];
map<db,int>cnt;

int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(;ch!='(';C);scanf("%lf",&a);
		for(;ch!='+';C);scanf("%lf",&b);
		for(;ch!=')';C);C;scanf("%lf",&c);
		ans[i]=(a+b)/c;
		cnt[(a+b)/c]++;
	}
	for(i=1;i<=n;i++) printf("%d ",cnt[ans[i]]);
}