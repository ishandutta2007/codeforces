#include <bits/stdc++.h>
using namespace std;
const int P=2520;
int a[P+2],t,d[20];
long long f[20][P+2][50],l,r;
long long D(int l,int y,int m,bool v)
{
	if(!l)
		return y%m==0;
	if(!v&&~f[l][y][a[m]])
		return f[l][y][a[m]];
	int e=v?d[l]:9;
	long long s=0;
	for(int i=0;i<=e;i++)
		s+=D(l-1,(y*10+i)%P,i?m/__gcd(m,i)*i:m,(v&(i==e)));
	if(!v)
		f[l][y][a[m]]=s;
	return s;
}
long long S(long long x)
{
	int l=0;
	while(x)
		d[++l]=x%10,x/=10;
	return D(l,0,1,true);
}
int main()
{
	memset(f,-1,sizeof(f));
	for(int i=1;i<=P;i++)
		if(P%i==0)
			a[i]=++t;
	cin>>t;
	while(t--&&cin>>l>>r)
		cout<<S(r)-S(l-1)<<'\n';
	return 0;
}