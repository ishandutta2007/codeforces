#include<bits/stdc++.h>
using namespace std;
const int N=120005;
int n,a[N],b[N],c[N],l[N],r[N],num[N];
bool check(int x){
	num[a[x]]--; num[b[x]]++; num[c[x]]++;
	if (num[b[x]]<=9&&num[c[x]]<=9) return 1;
	num[a[x]]++; num[b[x]]--; num[c[x]]--;
	return 0;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=4*n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		l[i]=i-1; r[i]=i+1;
	}
	l[1]=4*n; r[4*n]=1;
	for (int i=1;i<=n;i++) num[i]=4;
	puts("YES");
	for (int i=1,j=1;i<=4*n;i++){
		for (;!check(j);) j=r[j];
		r[l[j]]=r[j]; l[r[j]]=l[j];
		printf("%d ",j); j=r[j];
	}
}