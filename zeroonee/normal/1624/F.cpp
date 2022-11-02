#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int cur,n,x;
int ask(int y)
{
	cout<<"+ "<<y<<endl;
//x+=y;	
//return x/n;
	cin>>y;
	return y;
}
int lst;
bool ck(int num)
{
	int x=(num+cur)/n*n+n-num-cur;
	if (x==n) return lst;
	cur+=x;
	int r=ask(x);
	assert((num+cur)%n==0);
	return ((num+cur)/n==r) ;
}
int main()
{
	int l,r,mid;
	cin>>n;
//cin>>x;
	l=1;r=n;
	while (l<r)
	{
		mid=l+r+1>>1;
		if (ck(mid)) l=mid; else r=mid-1;
	}
	cout<<"! "<<l+cur<<endl;
}