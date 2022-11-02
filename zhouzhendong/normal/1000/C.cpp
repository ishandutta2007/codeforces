#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1000006;
int n,hs=0,t[N];
LL Ha[N],L[N],R[N],cnt[N];
LL read(){
	LL x=0;
	char ch=getchar();
	while (!('0'<=ch&&ch<='9'))
		ch=getchar();
	while ('0'<=ch&&ch<='9')
		x=x*10+ch-48,ch=getchar();
	return x;
}
void LSH(){
	sort(Ha+1,Ha+hs+1);
	int _hs=1;
	for (int i=2;i<=hs;i++)
		if (Ha[i]!=Ha[i-1])
			Ha[++_hs]=Ha[i];
	hs=_hs;
}
int find(LL x){
	int L=1,R=hs,mid;
	while (L<=R){
		mid=(L+R)>>1;
		if (Ha[mid]==x)
			return mid;
		if (x<Ha[mid])
			R=mid-1;
		else
			L=mid+1;
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		L[i]=read(),R[i]=read();
		Ha[++hs]=L[i],Ha[++hs]=R[i]+1;
	}
	LSH();
	memset(t,0,sizeof t);
	memset(cnt,0,sizeof cnt);
	for (int i=1;i<=n;i++){
		t[find(L[i])]++;
		t[find(R[i]+1)]--;
	}
	for (int i=1;i<=hs;i++){
		t[i]+=t[i-1];
		cnt[t[i]]+=Ha[i+1]-Ha[i];
	}
	for (int i=1;i<=n;i++)
		printf("%I64d ",cnt[i]);
	return 0;
}