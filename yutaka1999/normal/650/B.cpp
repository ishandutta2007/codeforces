#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <cmath>
#include <map>
#define SIZE 500005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int left[SIZE],right[SIZE];
//
//{vertical -> h
//h:0,w:1
char str[SIZE];
int A[SIZE];
int n;
ll a,b,T;

int solve()
{
	for(int j=0;j<n;j++)
	{
		if(j==0) left[j]=(A[j]==0?0:b)+1;
		else
		{
			left[j]=left[j-1]+a+1;
			if(A[j]!=0) left[j]+=b;
		}
	}
	for(int j=n-1;j>=0;j--)
	{
		if(j==n-1) right[j]=a+(A[j]==0?0:b)+1;
		else
		{
			right[j]=right[j+1]+a+1;
			if(A[j]!=0) right[j]+=b;
		}
	}
	int ret=0;
	//0->lefts
	int to=0;
	for(int i=0;i<n;i++)
	{
		if(left[i]>T) break;
		ret=max(ret,i+1);
		ll now=left[i]+(ll) i*(ll) a;
		while(to<n&&now+right[to]>T) to++;
		ret=max(ret,min(n,i+1+(n-to)));
	}
	return ret;
}
int main()
{
	scanf("%d %lld %lld %lld",&n,&a,&b,&T);
	scanf("%s",&str);
	for(int i=0;i<n;i++) A[i]=str[i]=='h'?0:1;
	int ret=solve();
	for(int l=1,r=n-1;l<r;l++,r--) swap(A[l],A[r]);
	ret=max(ret,solve());
	printf("%d\n",ret);
	return 0;
}