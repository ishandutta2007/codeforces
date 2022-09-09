#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
char c[N];
int n,i,j,k,B=500,a[N],m;
ll ans,ss[N];
int main(){
	scanf("%s",c+1);n=strlen(c+1);
	for(i=1;i<=n;++i)if(c[i]=='1')a[++m]=i;
	for(i=1;i<=m;i=j+1){
		for(j=i;j<m && a[j+1]==a[j]+1;++j);
		ans+=1ll*(j-i+2)*(j-i+1)>>1;
	}
	for(i=1;i<B;++i){
		ss[0]=0;
		for(j=1;j<=n;++j)ss[j]=ss[j-1]+(c[j]=='1'?i:-1);
		sort(ss,ss+n+1);
		for(j=0;j<=n;j=k){
			for(k=j;k<=n && ss[k]==ss[j];++k);
			ans+=1ll*(k-j)*(k-j-1)>>1;
		}
	}
//cerr<<clock()<<endl;
	a[m+1]=n+1;
	for(i=1;i<=n;++i)for(j=1;i+j-1<=n && j*(B+1)<=n;++j){
		int l1=a[i+j-1]-a[i]+1,l2=a[i+j]-a[i];
		for(k=0;k<a[i]-a[i-1];++k){
			int lo=max(B+1,(k+l1+j-1)/j),hi=(k+l2)/j;
			if(lo<=hi)ans+=hi-lo+1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}