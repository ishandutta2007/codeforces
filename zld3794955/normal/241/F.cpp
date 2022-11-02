#include<bits/stdc++.h>
using namespace std;
const int N=110,M=110,C=26,L=1100;
int n,m,l,k,sx,sy,ex,ey,cx[C]={},cy[C]={},x[L]={},y[L]={};
char ch[N][M]={},way[L]={};
void init()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("\n%s",ch[i]+1);
	scanf("%d%d%s%d%d",&sx,&sy,way+1,&ex,&ey);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(isalpha(ch[i][j]))
				cx[ch[i][j]-'a']=i,cy[ch[i][j]-'a']=j;
	l=strlen(way+1);
	for(int i=1;i<=l;++i)
		x[i]=cx[way[i]-'a'],y[i]=cy[way[i]-'a'];
	x[0]=sx,y[0]=sy;
	++l,x[l]=ex,y[l]=ey;
}
void work()
{
	int lx=x[0],ly=y[0],s=0;
	for(int i=1;i<=l;++i)
	{
		int rx=x[i],ry=y[i];
		int len=abs(rx-lx)+abs(ry-ly), dx=(rx-lx)/len, dy=(ry-ly)/len;
		while(lx!=rx || ly!=ry)
		{
			s+=isalpha(ch[lx][ly]) ? 1 : ch[lx][ly]-'0';
			if(s>k)
			{
				printf("%d %d\n",lx,ly);
				return;
			}
			lx+=dx,ly+=dy;
		}
	}
	printf("%d %d\n",lx,ly);
}
int main()
{	
	init();
	work();
	return 0;
}