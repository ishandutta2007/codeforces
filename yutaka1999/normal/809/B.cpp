#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>

using namespace std;

char str[5];

bool ask(int i,int j)
{
	printf("1 %d %d\n",i+1,j+1);
	fflush(stdout);
	scanf("%s",&str);
	return str[0]=='T';
}
int naive_check(int l,int r)//(  [l,r)  ]
{
	if(l+1==r) return l;
	//printf("%5d %d\n",l,r);
	vector <int> vec;
	for(int i=l;i+1<r;i++)
	{
		if(ask(i,i+1)) vec.push_back(0);//f(i)<=f(i+1)
		else vec.push_back(1);//f(i)>f(i+1)
	}
	for(int i=0;i+1<vec.size();i++)
	{
		if(vec[i]==1&&vec[i+1]==0) return l+i+1;
	}
	if(vec[0]==1) return r-1;
	if(vec[vec.size()-1]==0) return l;
	if(ask(l,r-1)) return l;
	return r-1;
}
int find(int l,int r)//(  [l,r)  ]
{
	if(r-l<=3)
	{
		return naive_check(l,r);
	}
	int t=(r-l+1)/2;
	if(t%2==0) t++;
	int f=l+t/2,s=r-t/2-1;
	if(ask(f,s)) return find(f-t/2,f+t/2+1);
	return find(s-t/2,s+t/2+1);
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int c=find(0,n);
	int d=-1;
	if(c>0)
	{
		int g=find(0,c);
		if(ask(g,c)) d=g;
	}
	if(d==-1)
	{
		int g=find(c+1,n);
		assert(c!=g);//
		d=g;
	}
	//assert(d!=c);
	printf("2 %d %d\n",c+1,d+1);
	return 0;
}