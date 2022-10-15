#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int inf=1e9;
struct point{int x,y;bool operator <(const point &a)const{if(x!=a.x)return x<a.x;return y<a.y;}}p[3];
int main()
{
	for(int i=0;i<3;i++)p[i].x=read(),p[i].y=read();
	sort(p,p+3);
	if((p[0].y<=p[1].y&&p[1].y<=p[2].y)||(p[0].y>=p[1].y&&p[1].y>=p[2].y))
	{
		puts("3");
		printf("%d %d %d %d\n",p[0].x,p[0].y,p[1].x,p[0].y);
		printf("%d %d %d %d\n",p[1].x,p[0].y,p[1].x,p[2].y);
		printf("%d %d %d %d\n",p[1].x,p[2].y,p[2].x,p[2].y);
		return 0;
	}
	if(p[1].y>=p[0].y)
	{
		puts("3");
		printf("%d %d %d %d\n",p[0].x,p[0].y,p[1].x,p[0].y);
		printf("%d %d %d %d\n",p[1].x,p[2].y,p[2].x,p[2].y);
		printf("%d %d %d %d\n",p[1].x,p[1].y,p[1].x,min(p[0].y,p[2].y));
		return 0;
	}
	puts("3");
	printf("%d %d %d %d\n",p[0].x,p[0].y,p[1].x,p[0].y);
	printf("%d %d %d %d\n",p[1].x,p[2].y,p[2].x,p[2].y);
	printf("%d %d %d %d\n",p[1].x,p[1].y,p[1].x,max(p[0].y,p[2].y));
	return 0;
}