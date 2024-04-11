#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
int read(){
	int x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
const int N=2005;
int n,k,p;
int a[N],b[N];
int check(int d){
	int j=1;
	for (int i=1;i<=n;i++){
		while (j<=k&&abs(a[i]-b[j])+abs(b[j]-p)>d)
			j++;
		if (j>k)
			return 0;
		j++;
	}
	return 1;
}
int main(){
	n=read(),k=read(),p=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	for (int i=1;i<=k;i++)
		b[i]=read();
	sort(a+1,a+n+1);
	sort(b+1,b+k+1);
	int L=0,R=2e9,ans=R;
	while (L<=R){
		int mid=((LL)L+R)>>1;
		if (check(mid))
			R=mid-1,ans=mid;
		else
			L=mid+1;
	}
	cout << ans;
	return 0;
}