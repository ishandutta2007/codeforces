#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 200005

using namespace std;

struct BIT
{
	int bit[SIZE];
	int n;
	
	void add(int k,int x)
	{
		while(k<=n)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int sum(int k)
	{
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
};
BIT bit[26];
char str[2005];
bool ok[SIZE];

int main()
{
	int k;
	scanf("%d",&k);
	scanf("%s",&str);
	int sz=strlen(str);
	for(int i=0;i<26;i++)
	{
		bit[i].n=sz*k+2;
	}
	for(int i=0;i<sz;i++)
	{
		for(int j=0;j<k;j++)
		{
			bit[str[i]-'a'].add(i+j*sz+1,1);
			ok[i+j*sz]=true;
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int a;
		char c;
		scanf("%d %c",&a,&c);
		int v=c-'a';
		int s=-1,e=sz*k+2;
		while(e-s>1)
		{
			int med=(s+e)/2;
			if(bit[v].sum(med+1)<a) s=med;
			else e=med;
		}
		bit[v].add(e+1,-1);
		ok[e]=false;
	}
	for(int i=0;i<sz*k;i++)
	{
		if(ok[i])
		{
			printf("%c",str[i%sz]);
		}
	}
	puts("");
	return 0;
}