#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 1000005

using namespace std;
typedef long long int ll;

char liss[SIZE],snuke[SIZE];
int pos[SIZE];
int imos[SIZE][6];

int gt(char c,char d)
{
	int ret;
	if(c=='R')
	{
		if(d=='G') ret=0;
		else ret=1;
	}
	else if(c=='G')
	{
		if(d=='R') ret=2;
		else ret=3;
	}
	else
	{
		if(d=='R') ret=4;
		else ret=5;
	}
	return ret;
}
int main()
{
	scanf("%s",&liss);
	scanf("%s",&snuke);
	int sl=strlen(liss),ss=strlen(snuke);
	int now=0;
	for(int i=0;i<sl;i++) pos[i]=ss-1;
	for(int i=0;i<ss;i++)
	{
		pos[now]=i;
		if(now<sl&&liss[now]==snuke[i]) now++;
	}
	for(int i=1;i<ss;i++)
	{
		if(snuke[i]!=snuke[i-1])
		{
			imos[i][gt(snuke[i-1],snuke[i])]++;
		}
	}
	for(int i=0;i<6;i++)
	{
		for(int j=1;j<ss;j++)
		{
			imos[j][i]+=imos[j-1][i];
		}
	}
	now=0;
	ll ret=0;
	for(int i=0;i<sl;i++)
	{
		if(pos[i]==-1||now==ss) break;
		ret+=pos[i]-now+1;
		if(i>0&&liss[i]!=liss[i-1])
		{
			int g=gt(liss[i],liss[i-1]);
			ret-=imos[pos[i]][g]-(now==0?0:imos[now-1][g]);
		}
		if(now<ss&&snuke[now]==liss[i]) now++;
	}
	printf("%I64d\n",ret);
	return 0;
}