#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
inline int getint()
{
	char ch;
	while(!isdigit(ch=getchar()))
		if(ch==EOF)
			return 0;
	int x=ch-'0';
	while(isdigit(ch=getchar())) x=x*10+ch-'0';
	return x;
}
const int N=110;
int n,a[N]={};
int main()
{	
	while(int tmp=getint())
		a[++n]=tmp;
	sort(a+1,a+n+1);
	cout<<a[1];
	for(int i=2;i<=n;++i)
		cout<<"+"<<a[i];
	cout<<endl;
	return 0;
}