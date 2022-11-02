#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=2005,M=4000005;
int j,p,k,s1,s2,flag,n,m,a[N],b[N];
inline int read()
{
	int a=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	a=a*10+ch-'0';
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		a=a*10+ch-'0';
		ch=getchar();
	}
	return a;
}
inline bool check(int x){
    j=0;
	for(int i=1;i<=n;i++)for(j++;j<=k;j++)if(abs(a[i]-b[j])+abs(p-b[j])<=x){
		break;
	}
	if(j>k)return 0; else return 1;
}
int main(){
	n=read(); k=read(); p=read();
	for(int i=1;i<=n;i++)a[i]=read(); for(int i=1;i<=k;i++)b[i]=read();
	sort(&a[1],&a[n+1]); sort(&b[1],&b[k+1]);
	int l=0,r=2000000000; //cout<<check(7789)<<endl;
	while(l<r){
		int mid=((long long)l+r)>>1;
		if(check(mid))r=mid; else l=mid+1;
	}
	cout<<l<<endl;
}