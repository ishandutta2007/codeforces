#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int put[100005];
int whr[100005];
vector <int> in;
int rui[100005];// [ 0 , i )
int up;//0 -> up , 1 -> down , 2 -> the same

int way(int x,int y)
{
	if(x<y) return 0;
	if(x>y) return 1;
	return 2;
}
int sum(int a,int b)//[ a , b ) = [ 0 , b ) - [ 0 , a )
{
	return rui[b]-rui[a];
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&put[i]);
		in.push_back(put[i]);
	}
	in.erase(unique(in.begin(),in.end()),in.end());
	int s=0;
	for(int i=0;i<n;i++)
	{
		if(in[s]==put[i]) whr[i]=s;
		else whr[i]=++s;
	}
	up=2;rui[0]=0;
	for(int i=1;i<in.size();i++)
	{
		rui[i]=rui[i-1];
		int nxt=way(in[i-1],in[i]);
		if(up==1&&nxt==0) rui[i]++;
		if(nxt!=2) up=nxt;
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		a=whr[a],b=whr[b];
		if(a==b) printf("Yes\n");
		else
		{
			if(sum(a+1,b)==0) printf("Yes\n");// ( a , b ) == 0 <==> [ a + 1 , b ) ==0
			else printf("No\n");
		}
	}
	return 0;
}