#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=505,M=505,x_[4]={0,1,0,-1},y_[4]={1,0,-1,0};
int n,m,ex,ey,qx[N*M]={},qy[N*M]={},head=0,tail=1;
bool v[N][M]={};
char ch[N][M]={};
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>(ch[i]+1);
	cin>>qx[tail]>>qy[tail];
	cin>>ex>>ey;
	v[qx[tail]][qy[tail]]=true;
}
void bfs()
{
	while(head!=tail)
	{
		++head;
		for(int k=0;k<4;++k)
		{
			int tx=qx[head]+x_[k],ty=qy[head]+y_[k];
			if(tx==ex && ty==ey)
			{
				if(ch[tx][ty]=='X')
				{
					puts("YES");
					return;
				}
				for(int d=0;d<4;++d)
				{
					int tx2=tx+x_[d],ty2=ty+y_[d];
					if(ch[tx2][ty2]=='.' && (tx2!=qx[head] || ty2!=qy[head]))
					{
						puts("YES");
						return;
					}
				}
				puts("NO");
				return;
			}
			if(ch[tx][ty]=='.' && !v[tx][ty])
			{
				v[tx][ty]=true;
				++tail;
				qx[tail]=tx;
				qy[tail]=ty;
			}
		}
	}
	puts("NO");
}
int main()
{	
	init();
	bfs();
	return 0;
}