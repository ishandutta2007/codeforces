#include <cstdio>
#include <cstring>
#include <cctype>
const int maxn=600010;
typedef long long ll;
int getint(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x;
}
int n,x,a[maxn],i,mi[maxn],ma[maxn],s[maxn<<1];
inline void ua(int&x,int y){
	if(x<y)x=y;
}
inline void ui(int&x,int y){
	if(x>y)x=y;
}
inline int max(int x,int y){
	return x>y?x:y;
}
inline int min(int x,int y){
	return x<y?x:y;
}
ll solve(int l,int r){
	if(l==r)return 1;
	int m=(l+r)>>1,i,x,y;
	ll ans=solve(l,m)+solve(m+1,r);
	mi[m+1]=ma[m+1]=a[m+1];
	for(i=m+2;i<=r;++i){
		ma[i]=max(ma[i-1],a[i]);
		mi[i]=min(mi[i-1],a[i]);
	}
	mi[m]=ma[m]=a[m];
	for(i=m-1;i>=l;--i){
		ma[i]=max(ma[i+1],a[i]);
		mi[i]=min(mi[i+1],a[i]);
	}
	for(i=m+1;i<=r;++i){
		x=i-(ma[i]-mi[i]);
		if(x<=m && x>=l && mi[x]>=mi[i] && ma[x]<=ma[i])++ans;
	}
	for(i=m;i>=l;--i){
		x=i+(ma[i]-mi[i]);
		if(x>m && x<=r && mi[x]>=mi[i] && ma[x]<=ma[i])++ans;
	}
	for(i=l;i<=m;++i)s[ma[i]+i]=0;
	for(i=m+1;i<=r;++i)s[mi[i]+i]=0;
	x=y=m;
	s[ma[m]+m]=1;
	for(i=m+1;i<=r;++i){
		while(x>=l && mi[x]>mi[i]){
			--x;
			++s[ma[x]+x];
		}
		--s[ma[x]+x];
		++x;
		while(y>=l && ma[y]<ma[i]){
			--s[ma[y]+y];
			--y;
		}
		if(y>=x)ans+=s[mi[i]+i];
	}
	for(i=l;i<=m;++i)s[mi[i]-i+n]=0;
	for(i=m+1;i<=r;++i)s[ma[i]-i+n]=0;
	x=y=m;
	s[mi[m]-m+n]=1;
	for(i=m+1;i<=r;++i){
		while(x>=l && ma[x]<ma[i]){
			--x;
			++s[mi[x]-x+n];
		}
		--s[mi[x]-x+n];
		++x;
		while(y>=l && mi[y]>mi[i]){
			--s[mi[y]-y+n];
			--y;
		}
		if(y>=x)ans+=s[ma[i]-i+n];
	}
	return ans;	
}
int main(){
	n=getint();
	for(i=1;i<=n;++i){
		x=getint();
		a[x]=getint();
	}
	printf("%lld\n",solve(1,n));
	return 0;
}