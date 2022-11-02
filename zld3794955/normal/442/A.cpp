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
int n,a[6][6]={};
char ch[10]={};
void init()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>ch;
		int l=0,r=0;	
		switch(ch[0])
		{
			case 'R': l=1; break;
			case 'G': l=2; break;
			case 'B': l=3; break;
			case 'Y': l=4; break;
			case 'W': l=5; break;
		}
		r=ch[1]-'0';
		++a[l][r];
	}
}
int calc(int x)
{
	x=(x&0x55555555)+((x>>1)&0x55555555);
	x=(x&0x33333333)+((x>>2)&0x33333333);
	x=(x&0x0f0f0f0f)+((x>>4)&0x0f0f0f0f);
	x=(x&0x00ff00ff)+((x>>8)&0x00ff00ff);
	x=(x&0x0000ffff)+((x>>16)&0x0000ffff);
	return x;
}
bool check(int sl,int sr)
{
	bool bl[6]={},br[6]={},b[6][6]={};
	for(int i=1;i<=5;++i)
		for(int j=1;j<=5;++j)
			b[i][j]=a[i][j]==0;
	for(int i=1;i<=5;++i)
		for(int j=1;j<=5;++j)
			if((sl&(1<<i)) && (sr&(1<<j)))
				b[i][j]=true;
	bool changed=true;
	while(changed) { changed=false;
	for(int i=1;i<=5;++i)
	{
		bl[i]=true;
		for(int j=1;j<=5;++j)
			bl[i]&=b[i][j];
		if(sl&(1<<i))
			bl[i]=true;
	}
	for(int j=1;j<=5;++j)
	{
		br[j]=true;
		for(int i=1;i<=5;++i)
			br[j]&=b[i][j];
		if(sr&(1<<j))
			br[j]=true;
	}
	int sl=0;
	for(int i=1;i<=5;++i)
		sl+=bl[i];
	int sr=0;
	for(int i=1;i<=5;++i)
		sr+=br[i];
	if(sl==4)
		for(int i=1;i<=5;++i)
			bl[i]=true;
	if(sr==4)
		for(int i=1;i<=5;++i)
			br[i]=true;
	for(int i=1;i<=5;++i)
	{
		if(bl[i])
		{
			int s=0;
			for(int j=1;j<=5;++j)
				s+=b[i][j];
			if(s==4)
			{
				changed=true;
				for(int j=1;j<=5;++j)
					b[i][j]=true;
			}
		}
		if(br[i])
		{
			int s=0;
			for(int j=1;j<=5;++j)
				s+=b[j][i];
			if(s==4)
			{
				changed=true;
				for(int j=1;j<=5;++j)
					b[j][i]=true;
				}
		}
	}
	}
	int s=0;	
	for(int i=1;i<=5;++i)
		for(int j=1;j<=5;++j)
			s+=b[i][j];
	return s==25;
}
void work()
{
	int ans=8;
	for(int i=0;i<64;i+=2)
		for(int j=0;j<64;j+=2)
			if(check(i,j))
			{
				//cout<<"i="<<i<<" j="<<j<<endl;
				ans=min(calc(i)+calc(j),ans);
			}
	printf("%d\n",ans);
}
int main()
{	
	init();
	work();
	return 0;
}