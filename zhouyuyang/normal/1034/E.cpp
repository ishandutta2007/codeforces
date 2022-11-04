#include<bits/stdc++.h>
#define ll long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
using namespace std;
const int N=(1<<21)+5;
ll lo,hi,all;
int n,L,cnt[N];
char s[N];
ll A[N],B[N];
ll add(ll a,ll b){
	return a^b^((a&b&lo)<<1);
}
ll sub(ll a,ll b){
	return add(lo,add(a,all^b));
}
ll v[5];
ll mul(ll a,ll b){
	ll c=v[0]=0; v[1]=a;
	For(i,2,3) v[i]=add(v[i-1],a);
	For(i,0,n) c=add(c,v[(b>>(2*i))&3]<<(2*i));
	return c;
}
void get(ll *a){
	gets(s);
	For(i,0,L-1) a[i]=(ll)(s[i]-'0')<<(cnt[i]*2);
	for (int i=1;i<L;i*=2)
		for (int j=0;j<L;j+=(i<<1))
			For(k,j,j+i-1) a[k^i]=add(a[k^i],a[k]);
}
int main(){
	scanf("%d\n",&n); L=1<<n;
	For(i,0,n) lo+=1ll<<(2*i);
	For(i,1,L-1) cnt[i]=cnt[i>>1]+(i&1);
	hi=lo*2; all=(1ll<<(2*n+2))-1;
	get(A); get(B);
	For(i,0,L-1) A[i]=mul(A[i],B[i]);
	for (int i=1;i<L;i*=2)
		for (int j=0;j<L;j+=(i<<1))
			For(k,j,j+i-1) A[k^i]=sub(A[k^i],A[k]);
	For(i,0,L-1) printf("%d",(A[i]>>(cnt[i]*2))&3);
}