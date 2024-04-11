#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5,mo=1e9+7;
inline int poww(int x,int y){int ans=1;for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;return ans;}
int T,n,i,j,p[N],a[N],c,ans1,ans2;
bool vi[N];
inline int calc(int v1,int v2){
	if(v1>v2)return v2+(v1-v2)/3*2;
		else return v1+(v2-v1)/3*3;
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);memset(a+1,0,n<<2);memset(vi+1,0,n<<2);ans2=0;
		for(i=1;i<=n;++i)scanf("%d",p+i);
		for(i=1;i<=n;++i)if(!vi[i]){for(j=i,c=0;++c,vi[j]=1,p[j]!=i;j=p[j]);++a[c];}
		if(n%3==1){
			ans1=4ll*poww(3,(n-4)/3)%mo;
			int v1=a[1],v2=a[2];
			for(i=3;i<=n;++i)ans2+=((i+2)/3-1)*a[i],i%3==1?v1+=a[i]:i%3==2?v2+=a[i]:0;
			int v3=1<<30;
			if(v1/2+v2>=2)c=min(v2,2),v3=min(v3,calc(v1-(2-c)*2,v2-c)+2-c);
			if(v1)v3=min(v3,calc(v1-1,v2)+1);
			for(i=4;i<=n;i+=3)if(a[i])break;if(i<=n)v3=min(v3,calc(v1-1,v2)-1);
			ans2+=v3;
		}else{
			ans1=poww(3,n/3)%mo;if(n%3==2)ans1=2ll*ans1%mo;
			int v1=a[1],v2=a[2];
			for(i=3;i<=n;++i)ans2+=((i+2)/3-1)*a[i],i%3==1?v1+=a[i]:i%3==2?v2+=a[i]:0;
			if(n%3==2)ans2+=v2?calc(v1,v2-1):calc(v1-2,v2)+1;
				else ans2+=calc(v1,v2);
		}
		printf("%d %d\n",ans1,ans2);
	}
}