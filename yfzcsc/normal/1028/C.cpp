#include<bits/stdc++.h>
#define maxn 200100
using namespace std;
typedef pair<int,int> pii;
const int inf=2e9;
struct Data{
	pii x,y;
	void scan(){
		scanf("%d%d",&x.first,&y.first);
		scanf("%d%d",&x.second,&y.second);
	}
	Data(){}
	Data(pii x,pii y):x(x),y(y){}
	Data operator+(const Data& d)const{
		return Data(pii(max(x.first,d.x.first),min(x.second,d.x.second)),
			pii(max(y.first,d.y.first),min(y.second,d.y.second))
			);
	}
}pre[maxn],suf[maxn],a[maxn];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)a[i].scan();
	pre[0]=suf[n+1]=Data(pii(-inf,inf),pii(-inf,inf));
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
	for(int i=n;i>=1;--i)suf[i]=suf[i+1]+a[i];
	for(int i=1;i<=n;++i){
		Data d=pre[i-1]+suf[i+1];
//		printf("{%d[%d,%d]}",i,(a[i+2]+a[i+1]).y.first,(a[i+2]+a[i+1]).y.second);
		if(d.x.first<=d.x.second&&d.y.first<=d.y.second)
			return printf("%d %d",d.x.first,d.y.first),0;
	}
}