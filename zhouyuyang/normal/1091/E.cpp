#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=1000005;
int n,sum,a[N],b[N];
ll S[N];
pii calc(int x){
	int pos=0,tmp=0;
	for (;a[pos+1]>x;b[++tmp]=a[++pos]);
	b[++tmp]=x;
	for (;pos<n;) b[++tmp]=a[++pos];
	For(i,1,n+1) S[i]=S[i-1]+b[i];
	pos=n+2;
	ll sum=0;
	For(i,1,n+1){
		sum+=b[i]-2*i+2;
		for (;b[pos-1]<=i&&pos>i+1;pos--);
		pos=max(pos,i+1);
		ll sum2=S[n+1]-S[pos-1]+1ll*(pos-i-1)*i;
		if (sum2<sum)
			return pii(b[i]<=x?-1:1,0);
	}
	return pii(0,0);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum^=a[i];
	sort(a+1,a+n+1,greater<int>());
	int l=0,r=n,ans=-1;
	if ((l+sum)&1) l++;
	if ((r+sum)&1) r--;
	while (l<=r){
		int mid=(l+r)/2;
		if ((mid+sum)&1) mid++;
		if (mid>r||mid<l) break;
		pii tmp=calc(mid);
		if (tmp.fi==0){
			ans=mid;
			break;
		}
		if (tmp.fi<0)
			r=mid-1;
		else
			l=mid+1;
	}
	if (ans==-1)
		return puts("-1"),0;
	l=0; r=ans-1;
	int lans=ans;
	while (l<=r){
		int mid=(l+r)/2;
		if ((mid+sum)&1) mid++;
		if (mid>r||mid<l) break;
		pii tmp=calc(mid);
		if (tmp.fi==0)
			lans=mid,r=mid-1;
		else l=mid+1;
	}
	l=ans+1; r=n;
	int rans=ans;
	while (l<=r){
		int mid=(l+r)/2;
		if ((mid+sum)&1) mid++;
		if (mid>r||mid<l) break;
		pii tmp=calc(mid);
		if (tmp.fi==0)
			rans=mid,l=mid+1;
		else r=mid-1;
	}
	for (;lans<=rans;lans+=2)
		printf("%d ",lans);
}
/*
if val<=GG(val)
*/