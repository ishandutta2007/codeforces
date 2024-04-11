#include <cstdio>
typedef long long LL;
const int N=2e5+10;
int T,n,k,a[N],lst[N],nxt[N];LL s[N],ml[N],mr[N];
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
void findlst(int x){
	LL ns=a[x];ml[x]=ns;
	int p=x-1;while(p&&ns<=0)cmin(ml[x],ns+=a[p--]);
	lst[x]=p;
}
void findnxt(int x){
	LL ns=a[x];mr[x]=ns;
	int p=x+1;while(p<=n&&ns<=0)cmin(mr[x],ns+=a[p++]);
	nxt[x]=p;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),s[i]=s[i-1]+a[i],lst[i]=nxt[i]=-1;s[n+1]=s[n];
		int p=k-1,q=k+1;LL ans=a[k];
		while(p>0&&q<=n){
			if(lst[p]==-1)findlst(p);
			if(nxt[q]==-1)findnxt(q);
			if(ans+ml[p]>=0){ans+=s[p]-s[lst[p]],p=lst[p];continue;}
			if(ans+mr[q]>=0){ans+=s[nxt[q]-1]-s[q-1],q=nxt[q];continue;}
			break;
		}
		puts(!p||q>n?"YES":"NO");
	}
	return 0;
}