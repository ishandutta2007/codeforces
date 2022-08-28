#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 4005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

int gcd[SIZE][SIZE];
int cnt[2][2];

void make()
{
	for(int i=0;i<SIZE;i++) gcd[0][i]=i;
	for(int i=1;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			if(i>j) gcd[i][j]=gcd[j][i];
			else gcd[i][j]=gcd[j%i][i];
		}
	}
}
int main()
{
	int w,h;
	scanf("%d %d",&w,&h);
	make();
	ll ln=0;
	for(int i=0;i<=w;i++)
	{
		for(int j=0;j<=h;j++)
		{
			if(i==0&&j==0) continue;
			ll pd=(w-i+1)*(h-j+1);
			ln+=pd*(ll) (gcd[i][j]-1)*((i!=0&&j!=0)?2LL:1LL)*6LL%MOD;
			if(ln>=MOD) ln%=MOD;
		}
	}
	for(int i=0;i<=w;i++)
	{
		for(int j=0;j<=h;j++)
		{
			cnt[i%2][j%2]++;
		}
	}
	ll ret=0;
	int all=(w+1)*(h+1);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			int g=cnt[i][j];
			ret+=(ll) g*(ll) (g-1)%MOD*(ll) (all-g)*3LL%MOD;
			if(ret>=MOD) ret-=MOD;
			ret+=(ll) g*(ll) (g-1)%MOD*(ll) (g-2)%MOD;
			if(ret>=MOD) ret-=MOD;
		}
	}
	printf("%llld\n",(ret-ln+MOD)%MOD);
	return 0;
}