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
const int N=1010,D=1010;
int n,k,d,a[N]={},c[N][D]={},totd=0;
struct tmpsort
{
	int k;
	tmpsort(int k_): k(k_) {}
	bool operator() (int x,int y)
	{
		return c[x][k]<c[y][k];
	}
};
void tryy(int l,int r,int day)
{
	//cout<<"l="<<l<<" r="<<r<<" day="<<day<<endl;
	//for(int i=l;i<=r;++i)
	//	cout<<a[i]<<' ';
	//cout<<endl;
	if(l==r)
		return;
	totd=max(totd,day);
	if(totd>d)
		return;
	int t=1;
	for(int i=l;i<=r;++i)
	{
		c[a[i]][day]=t;
		t=t%k+1;
	}
	//for(int i=1;i<=n;++i)
	//	cout<<c[i][day]<<' ';
	//cout<<endl;
	sort(a+l,a+r+1,tmpsort(day));
	int last=l;
	for(int i=l+1;i<=r;++i)
	{
		if(c[a[i]][day]!=c[a[last]][day])
		{
			tryy(last,i-1,day+1);
			last=i;
		}
	}
	tryy(last,r,day+1);
}
int main()
{	
	cin>>n>>k>>d;
	for(int i=1;i<=n;++i)
		a[i]=i;
	tryy(1,n,1);
	if(totd>d)
		printf("-1\n");
	else
	{
		for(int i=1;i<=d;++i)
		{
			for(int j=1;j<=n;++j)
				if(c[j][i])
					printf("%d ",c[j][i]);
				else
					printf("1 ");
			printf("\n");
		}
	}
	return 0;
}