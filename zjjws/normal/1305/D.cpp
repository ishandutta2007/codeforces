#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAX=1e3+3;
struct milk
{
	int to,next;
}a[MAX<<1];
int h[MAX];
int du[MAX];
int d[MAX];
inline void add(int x,int y,int i){a[i].to=y;a[i].next=h[x];h[x]=i;}
LL rin()
{
	LL s=0;
	char c=getchar();
	bool bj=0;
	for(;(c>'9'||c<'0')&&c!='-';c=getchar());
	if(c=='-')bj=true,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
	if(bj)return -s;
	return s;
}
int main() {
	int i,j;
	//1
	int n;
	std::cin>>n;
	int x,y;
	for(i=1;i<n;i++)
	{
		std::cin>>x;std::cin>>y;
		add(x,y,i),add(y,x,i+n-1);
		du[x]++;du[y]++;
	}
	int head=1,tail=0;
	for(i=1;i<=n;i++)if(du[i]==1)d[++tail]=i;
	for(;head<=tail;)
	{
		if(tail==head){std::cout<<"! "<<d[head]<<std::endl;return 0;}
		x=d[head];y=d[head+1];
		std::cout<<"? "<<x<<" "<<y<<std::endl;
		int z;
		std::cin>>z;
		if(du[z]==1){std::cout<<"! "<<z<<std::endl;return 0;}
		for(i=h[x];i>0;i=a[i].next){du[a[i].to]--;if(du[a[i].to]==1)d[++tail]=a[i].to;}
		for(i=h[y];i>0;i=a[i].next){du[a[i].to]--;if(du[a[i].to]==1)d[++tail]=a[i].to;}
		head+=2;
	}
	return 0;
}