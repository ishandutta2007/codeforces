#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
typedef long long int ll;

int fl(int x)
{
	if(x>=0) return x/2;
	return -(abs(x)+1)/2;
}
ll cnt(int S,int L,int R)//0<=y,z  0<=y+z<=S,L<=y-z<=R
{
	//yA
	//0<=z<=S-y && y-R<=z<=y-L A
	//max(y-R,0) <= z <= min(S-y,y-L)
	//max(y-R,0)=0 <=> y<=R  R+1<=y
	//min(S-y,y-L)=S-y <=> (S+L)/2<=y <=> [(S+L+1)/2]<=y  y<=[(S+L+1)/2]-1
	//0`S-y  S-y+1
	//max(0,(S+L)/2)<=y<=R 
	ll ret=0;
	int left=S-R+1,right=S-max(0,fl(S+L+1))+1;
	left=max(left,0);
	if(left<=right)
	{
		ret+=(ll) (right-left+1)*(ll) (left+right)/2;
	}
	//0`y-L  y-L+1
	//0<=y<=min(R,[(S+L+1)/2]-1) 
	left=-L+1,right=min(R,fl(S+L+1)-1)-L+1;
	left=max(left,0);
	if(left<=right)
	{
		ret+=(ll) (right-left+1)*(ll) (left+right)/2;
	}
	if(S+R+1>=0)
	{
		//y-R`S-y  S+R-2*y+1
		//max(R+1,[(S+L+1)/2])<=y<=[(S+R)/2]
		left=(S+R+1)%2,right=S+R-2*max(0,max(R+1,fl(S+L+1)))+1;
		if(left<=right)
		{
			ret+=(ll) (left+right)*(ll) ((right-left)/2+1)/2;
		}
	}
	//y-R`y-L  R-L+1
	//R+1<=y<=[(S+L+1)/2]-1
	left=max(0,R+1),right=fl(S+L+1)-1;
	if(left<=right)
	{
		ret+=(ll) (R-L+1)*(ll) (right-left+1);
	}
	return ret;
}
int main()
{
	int a,b,c,l;
	scanf("%d %d %d %d",&a,&b,&c,&l);
	ll ret=0;
	for(int i=0;i<=l;i++)
	{
		int A=a+i;
		//|B-C|<A<B+C A
		//B=b+y,C=c+z A
		//A-b-c<y+z<=l-i , -A<b+y-c-z<A <=> -A+c-b < y-z < A+c-b
		int left=A-b-c+1,right=l-i;//left<=y+z<=right
		if(left>right) continue;
		int down=-A+c-b+1,up=A+c-b-1;//down<=y-z<=up
		//0<=y,z
		//0<=y,z  y+z<=S,L<=y-z<=R ?
		//printf("[%d %d] [%d %d] %lld %lld\n",left,right,down,up,left==0?0:cnt(left-1,down,up),cnt(right,down,up));
		ret+=cnt(right,down,up)-(left==0?0:cnt(left-1,down,up));
	}
	printf("%I64d\n",ret);
	return 0;
}