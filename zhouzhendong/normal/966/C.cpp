#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005,D=65;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!('0'<=ch&&ch<='9'))
		ch=getchar();
	while ('0'<=ch&&ch<='9')
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n,L[D],R[D];
LL a[N],ans[N];
int cntd(LL x){
	int ans=0;
	while (x)
		ans++,x>>=1;
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	for (int i=1;i<=60;i++){
		L[i]=n+1;
		R[i]=0;
	}
	for (int i=1;i<=n;i++){
		int d=cntd(a[i]);
		L[d]=min(L[d],i);
		R[d]=max(R[d],i);
	}
	bool flag=1;
	LL v=0;
	for (int i=1;i<=n&&flag;i++){
		bool f2=0;
		for (int j=1;j<=60;j++)
			if ((v&(1LL<<(j-1)))==0&&L[j]<=R[j]){
				v^=a[L[j]];
				ans[i]=a[L[j]++];
				f2=1;
				break;
			}
		if (!f2){
			flag=0;
			break;
		}
	}
	if (!flag)
		puts("No");
	else {
		puts("Yes");
		for (int i=1;i<=n;i++)
			printf("%I64d ",ans[i]);
	}
	return 0;
}