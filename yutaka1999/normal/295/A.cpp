#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 100005

using namespace std;
typedef long long int ll;

int l[SIZE],r[SIZE],d[SIZE];
ll im1[SIZE],im2[SIZE];
ll in[SIZE];

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++) scanf("%I64d",&in[i]);
	for(int i=0;i<m;i++) scanf("%d %d %d",&l[i],&r[i],&d[i]),l[i]--,r[i]--;
	memset(im1,0,sizeof(im1));
	memset(im2,0,sizeof(im2));
	for(int i=0;i<k;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);x--;y--;
		im1[x]++;im1[y+1]--;
	}
	for(int i=0;i<m;i++)
	{
		ll plus=im1[i]*d[i];
		im2[l[i]]+=plus;
		im2[r[i]+1]-=plus;
		im1[i+1]+=im1[i];
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%I64d",im2[i]+in[i]);
		im2[i+1]+=im2[i];
	}printf("\n");
	return 0;
}