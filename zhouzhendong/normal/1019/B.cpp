#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n;
int main(){
	scanf("%d",&n);
	if (n%4!=0){
		puts("! -1");
		fflush(stdout);
		return 0;
	}
	n/=2;
	int L=1,R=n-1,a1,a2;
	printf("? %d\n",n);
	fflush(stdout);
	scanf("%d",&a1);
	printf("? %d\n",n+n);
	fflush(stdout);
	scanf("%d",&a2);
	if (a1==a2){
		printf("! %d\n",n);
		fflush(stdout);
		return 0;
	}
	while (L<=R){
		int mid=(L+R)>>1,ans1,ans2;
		printf("? %d\n",mid);
		fflush(stdout);
		scanf("%d",&ans1);
		printf("? %d\n",mid+n);
		fflush(stdout);
		scanf("%d",&ans2);
		if (ans1==ans2){
			printf("! %d\n",mid);
			fflush(stdout);
			return 0;
		}
		if ((ans1<ans2)^(a1<a2))
			L=mid+1;
		else
			R=mid-1;
	}
	printf("! -1\n");
	fflush(stdout);
	return 0;
}