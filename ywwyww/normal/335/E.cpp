#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
ld s[110];
void solve1()
{
	int n,h;
	scanf("%d%d",&n,&h);
	double ans=n;
	printf("%.9f\n",ans);
}
void solve2()
{
	int n,h;
	scanf("%d%d",&n,&h);
	int i,j;
	ld ans=n;
	s[0]=1;
	for(i=1;i<=100;i++)
		s[i]=s[i-1]*2;
	for(i=1;i<=h;i++)
		for(j=1;j<=n;j++)
			ans+=(n-j)*pow(1-1/s[i],j-1)/s[2*i]*(s[i]-s[i-1]*(1+(j-1)/(s[i]-1)));
	printf("%.9f\n",double(ans));
}
int main()
{
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	char s[10];
	scanf("%s",s);
	if(s[0]=='B')
		solve1();
	else
		solve2();
	return 0;
}