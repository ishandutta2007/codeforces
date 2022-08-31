#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;

int in[100005];
ll time;
int n,x;

int dist(int a,int b)
{
	if(b>=a) return b-a;
	return b+n-a;
}

int main()
{
	scanf("%d %d",&n,&x);x--;
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	int pos=x;
	int pla;
	ll val=INF;
	do
	{
		time=dist(pos,x)+(ll) n*in[pos];
		if(time<val)
		{
			val=time;
			pla=pos;
		}
		pos--;
		if(pos<0) pos+=n;
	}while(pos!=x);
	//printf("%d %I64d\n",pla,val);
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		ll ans=in[i];
		if(i==pla) printf("%I64d",val);
		else if(dist(pla,i)<=dist(pla,x)) printf("%I64d",in[i]-val/n-1);
		else printf("%I64d",in[i]-val/n);
	}printf("\n");
	return 0;
}