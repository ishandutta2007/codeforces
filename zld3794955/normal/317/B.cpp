#include<bits/stdc++.h>
using namespace std;
const int N=70,M=70,x_[4]={0,1,0,-1},y_[4]={1,0,-1,0};
int n,t,tot[N+N+5][M+M+5]={},tmp[N+N+5][M+M+5]={};
void init()
{
	scanf("%d%d",&n,&t);
	tot[N][M]=n;
	bool flag=true;
	int sum=0;
	while(flag)
	{
		flag=false;
		for(int i=0;i<N+N;++i)
			for(int j=0;j<M+M;++j)
				tmp[i][j]=0;
		for(int i=0;i<N+N;++i)
			for(int j=0;j<M+M;++j)
			{
				tmp[i][j]+=tot[i][j]&3;
				if(tot[i][j]>=4)
				{
					flag=true;
					for(int k=0;k<4;++k)
						tmp[i+x_[k]][j+y_[k]]+=tot[i][j]>>2;
				}
			}
		for(int i=0;i<N+N;++i)
			for(int j=0;j<M+M;++j)
				tot[i][j]=tmp[i][j];
		++sum;
	}
}
void work()
{
	int x,y;
	for(int i=1;i<=t;++i)
	{
		scanf("%d%d",&x,&y);
		if(-N<x && x<N && -M<y && y<M)
			printf("%d\n",tot[x+N][y+M]);
		else
			puts("0");
	}
}
int main()
{
	init();
	work();
	return 0;
}