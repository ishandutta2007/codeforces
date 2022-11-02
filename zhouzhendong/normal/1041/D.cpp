#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x*f;
}
int n,h;
int L[N],R[N],tot[N];
int main(){
	n=read(),h=read();
	tot[0]=0;
	for (int i=1;i<=n;i++)
		L[i]=read(),R[i]=read(),tot[i]=tot[i-1]+R[i]-L[i];
	int res=0;
	for (int i=1;i<=n;i++){
		int l=i+1,r=n,mid,ans=i;
		while (l<=r){
			mid=(l+r)>>1;
			if (L[mid]-R[i]-(tot[mid-1]-tot[i])<h)
				l=mid+1,ans=mid;
			else
				r=mid-1;
		}
		res=max(res,R[ans]-L[i]+(h-(L[ans]-R[i]-(tot[ans-1]-tot[i]))));
	}
	printf("%d",res);
	return 0;
}