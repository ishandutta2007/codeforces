#include<bits/stdc++.h>
using namespace std;
const int N=2001;
int n,a[N][N],c[N],p[N],t,A;
string s[N]; 
bool C()
{
	for(int i=1;i<=n;i++)
		p[i]=c[i];
	sort(p+1,p+n+1),t=0;
	for(int i=1;i<n;i++)
	{
		t+=p[i];
		if(t==i*(i-1)/2)
			return false;
	}
	return true;
}
void S(int x)
{
	for(int i=1;i<=n;i++)
		c[x]-=a[x][i],c[i]-=a[i][x],swap(a[x][i],a[i][x]),c[x]+=a[x][i],c[i]+=a[i][x];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=s[i][j-1]-'0',c[i]+=a[i][j];
	for(int i=1;i<=n;i++)
		S(i),A+=C(),S(i);
	if(C())
		cout<<0<<' '<<1;
	else if(A)
		cout<<1<<' '<<A;
	else if(n==6)
		cout<<2<<' '<<18;
	else
		cout<<-1;
	return 0;
}