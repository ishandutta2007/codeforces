#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int x,d,n;
LL a[N];
int main(){
	scanf("%d%d",&x,&d);
	int cnt=0;
	n=0;
	LL v=1,v2=99999999999999999LL;
	while (x){
		if (x&1){
			for (int i=1;i<=cnt;i++)
				a[++n]=v;
			a[++n]=v2;
			v+=d;
			v2-=d;
		}
		x>>=1,cnt++;
	}
	printf("%d\n",n);
	for (int i=1;i<=n;i++)
		printf("%I64d ",a[i]);
	return 0;
}