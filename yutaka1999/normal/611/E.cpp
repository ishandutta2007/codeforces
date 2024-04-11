#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
#include <cstring>
#define SIZE 200005

using namespace std;

int T[SIZE];
bool use[SIZE];
int a,b,c;
int ord[3];
int n;

bool check(int x)
{
	int A=x,B=x,C=x;
	int sa=0,sb=0;
	memset(use,false,sizeof(use));
	for(int i=0;i<n;i++)
	{
		if(T[i]>a+b+c) return false;
		if(T[i]>b+c) A--,B--,C--;
		else if(T[i]>a+c) sa++,A--,B--,C--;
		else if(T[i]>max(a+b,c)) sb++,A--,B--,C--;
		else if(T[i]<=c&&C>0) C--;
		else if(T[i]>a+b) return false;
		else if(T[i]>b) A--,B--;
		else use[i]=true;
	}
	if(A<0||B<0||C<0) return false;
	sa+=A,sb+=B;
	for(int i=0;i<n;i++)
	{
		if(use[i])
		{
			if(T[i]<=a&&sa>0) sa--;
			else if(sb>0) sb--;
			else return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	scanf("%d %d %d",&ord[0],&ord[1],&ord[2]);
	sort(ord,ord+3);
	a=ord[0],b=ord[1],c=ord[2];
	for(int i=0;i<n;i++) scanf("%d",&T[i]);
	sort(T,T+n,greater <int>());
	int l=0,r=n+1;
	while(r-l>1)
	{
		int m=(l+r)/2;
		if(check(m)) r=m;
		else l=m;
	}
	if(r>n) puts("-1");
	else printf("%d\n",r);
	return 0;
}