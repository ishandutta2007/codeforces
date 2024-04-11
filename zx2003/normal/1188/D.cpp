#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,i,j,k,f[65][N];
ll a[N],S,b[N];
inline bool cmp(const ll&a,const ll&b){return (a&S)<(b&S);}
inline void upi(int&a,const int&b){a>b?a=b:0;}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%lld",a+i);
	S=1;sort(a+1,a+n+1,cmp);
	for(i=0;i<65;++i)for(j=0;j<N;++j)f[i][j]=1ll<<30;
	for(i=1;i<=n && (a[i]&1)==0;++i);
	if(i<=n)f[0][i-1]=n-i+1;f[0][n]=a[n]&1?i-1:0;
	for(i=1;i<60;++i){
		memcpy(b+1,a+1,n<<3);S=(1ll<<i+1)-1;sort(b+1,b+n+1,cmp);
		for(j=0;j<=n;++j){
			int x,y;
			x=upper_bound(b+1,b+n+1,a[j]&(S>>1),cmp)-b-1;
			y=upper_bound(b+1,b+n+1,a[j]&(S>>1)|(1ll<<i),cmp)-b-1;
			upi(f[i][x],f[i-1][j]+y-x);
			upi(f[i][y],f[i-1][j]+n-(y-x));
		}
		memcpy(a+1,b+1,n<<3);
	}
	printf("%d\n",f[i-1][n]);
	return 0;
}