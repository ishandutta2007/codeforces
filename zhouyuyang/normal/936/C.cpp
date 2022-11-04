#include<bits/stdc++.h>
#define N 2005
using namespace std;
char a[N],b[N],c[N];
int ans[N*3],n,tot,R,cnt[150];
void flip(int x){
	if (!x) return;
	ans[++tot]=x;
	for (int i=1;i<=n-x;i++)
		c[i+x]=a[i];
	for (int i=n-x+1;i<=n;i++)
		c[i-(n-x)]=a[i];
	reverse(c+1,c+x+1);
	swap(a,c);
}
int main(){
	scanf("%d%s%s",&n,a+1,b+1);
	for (int i=1;i<=n;i++)
		cnt[a[i]]++,cnt[b[i]]--;
	for (int i=0;i<=128;i++)
		if (cnt[i]) return puts("-1"),0;
	int l=(n+1)/2,r=(n+1)/2;
	for (int i=1;i<=n;i++)
		if (a[i]==b[l]){
			flip(n-i);
			flip(n);
			break;
		}
	for (int i=2;i<=n;i++){
		int p1=(i&1?--l:++r);
		int p=i;
		for (;a[p]!=b[p1];p++);
		flip(n-p+1);
		flip(p-i);
		if (i!=n||n%2==0)flip(n);
	}
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) printf("%d ",ans[i]);
}
/*
cde....b...
...bcde....
.......bcde
edbc.....f.
f


*/