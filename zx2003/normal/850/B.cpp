#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2000005;
typedef long long ll;
int ma,n,a[N],i,b[N],j;
ll x,y,ans,s,z,u,c[N];
inline int getint(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x;
}
int main(){
	cin>>n>>x>>y;
	for(i=1;i<=n;++i)a[i]=getint(),++b[a[i]],ma=max(ma,a[i]);
	if(ma==1)return cout<<min(x,y)*n<<endl,0;
	if(n==1){
		if(a[1]>1)return puts("0"),0;
			else return cout<<min(x,y)<<endl,0;
	}
	for(i=1;i<N;++i)c[i]=c[i-1]+1ll*i*b[i],b[i]+=b[i-1];
	z=x/y;
	ans=1ll<<62;
	for(i=2;i<=ma;++i){
		for(j=i,s=0;ma>j-i;j+=i){
			if(i-1<=z)s+=y*(1ll*(b[j]-b[j-i])*j-(c[j]-c[j-i]));
				else s+=y*(1ll*(b[j]-b[j-z-1])*j-(c[j]-c[j-z-1]))+x*(b[j-z-1]-b[j-i]);
		}
		if(s<ans)ans=s;
	}
	cout<<ans;
	return 0;
}