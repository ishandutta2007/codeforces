#include<bits/stdc++.h>
#define maxn 200100
using namespace std;
int lsh[maxn],tp,a,b,c,n,x[maxn],y[maxn];
int getid(int x){
	return lower_bound(lsh+1,lsh+tp+1,x)-lsh;
}
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&n);
	lsh[++tp]=a,lsh[++tp]=b,lsh[++tp]=c;
	for(int i=1;i<=n;++i)scanf("%d",&x[i]),lsh[++tp]=x[i];
	sort(lsh+1,lsh+tp+1);
	tp=unique(lsh+1,lsh+tp+1)-lsh-1;
	a=getid(a),b=getid(b),c=getid(c);
	for(int i=1;i<=n;++i)y[getid(x[i])]++;
	int ans=0;
	for(int i=a;i>b;--i)ans+=y[i];
	for(int i=a+1;i<c;++i)ans+=y[i];
	printf("%d",ans);
}