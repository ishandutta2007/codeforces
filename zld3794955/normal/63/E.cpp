#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;
const int N=19,S=1<<19,First_win=1,First_lost=2;
const int next[3][N]={{3,4,5,7,8,9,10,N,12,13,14,15,N,16,17,18,N,N,N},
                      {1,2,N,4,5,6,N,8,9,10,11,N,13,14,15,N,17,18,N},
                      {4,5,6,8,9,10,11,12,13,14,15,N,16,17,18,N,N,N,N}};
int f[S]={},s=0;
inline char get_unempty_char()
{
	char ch;
	while(isspace(ch=getchar())) ;
	return ch;
}
void init()
{
	for(int i=0;i<N;++i)
		s+=(get_unempty_char()=='O')*(1<<i);
}
int search(int now)
{
	if(f[now])
		return f[now];
	for(int t=0;t<=2;++t)
		for(int i=0;i<N;++i)
		{
			int tmp=now,p=i;
			while(tmp&(1<<p))
			{
				tmp^=(1<<p);
				if(search(tmp)==First_lost)
					return f[now]=First_win;
				p=next[t][p];
			}
		}
	return f[now]=First_lost;
}
int main()
{	
	init();
	puts(search(s)==First_win ? "Karlsson" : "Lillebror");
	return 0;
}