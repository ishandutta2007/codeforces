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
const int N=55,L=25,B=20,S=1<<B;
int n,m,s=0;
long long d[S]={};
double C[L][L]={},e[L]={},ans=0;
char ch[N][L]={};
long long calc(long long x)
{
	x=(x&0x5555555555555555ll)+((x>>1)&0x5555555555555555ll);
	x=(x&0x3333333333333333ll)+((x>>2)&0x3333333333333333ll);
	x=(x&0x0f0f0f0f0f0f0f0fll)+((x>>4)&0x0f0f0f0f0f0f0f0fll);
	x=(x&0x00ff00ff00ff00ffll)+((x>>8)&0x00ff00ff00ff00ffll);
	x=(x&0x0000ffff0000ffffll)+((x>>16)&0x0000ffff0000ffffll);
	x=(x&0x00000000ffffffffll)+((x>>32)&0x00000000ffffffffll);
	return x;
}
int main()
{	
	scanf("%d\n",&n);
	for(int i=0;i<n;++i)
		scanf("%s\n",ch[i]);
	m=strlen(ch[0]);
	s=(1<<m)-1;
	C[0][0]=1;
	for(int i=1;i<=m;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			if(i==j)
				continue;
			int same=0;
			for(int p=0;p<m;++p)
				if(ch[i][p]==ch[j][p])
					same|=(1<<p);
			//cout<<"same="<<same<<endl;
			d[same]|=1ll<<i;
			//cout<<"same="<<same<<endl;
		}
	for(int i=s;i>=0;--i)
		for(int j=0;j<m;++j)
			if(i&(1<<j))
				d[i^(1<<j)]|=d[i];
	//for(int i=0;i<=s;++i)
	//	cout<<"s="<<i<<" d[s]="<<d[i]<<endl;
	for(int i=0;i<=s;++i)
	{
		int deep=calc(i)+1;
		for(int j=0;j<m;++j)
			if(!(i&(1<<j)))
			{
				long long delta=d[i]^d[i^(1<<j)];
				e[deep]+=calc(delta);
			}
	}
	for(int i=1;i<=m;++i)
		ans+=e[i]/C[m][i]/n;
	printf("%.12f\n",ans);
	return 0;
}