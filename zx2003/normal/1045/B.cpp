//cwystc <-->   --by cwy
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const double PI=acos(-1);
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define Rep(i,a,b) for (int i=(a);i<(b);i++)
#define Per(i,a,b) for (int i=(a);i>(b);i--)
#define travel_set(it,a) for (set<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define travel_map(it,a) for (map<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define travel_vec(it,a) for (vector<int>::iterator (it)=(a).begin();(it)!=(a).end();(it)++)
#define p(x) cout << x << endl;
#define def cout << "find" << endl;
#define what_is(x) cout << #x << " is " << x << endl;
template <class T>T sqr(T x){return x*x;}
template <class T>T alex(T x){return (x>0)?x:-x;}
template <class T>void read(T&x){
	x=0;T f=1;char ch=getchar();
	while ((ch<48||ch>57)&&ch!=45)ch=getchar();
	if (ch==45)f=-1,ch=getchar();
	while (ch>=48&&ch<=57)x=x*10+ch-48,ch=getchar();
	x*=f;
}

//-------------------------------------------------head-------------------------------------------------

#define maxn 200005
#define mul 1000000007
#define mod1 1000000009
#define mod2 1000000021
int n,m;
int a[maxn],b[maxn];
int sum1[maxn],sum2[maxn];
int rsum1[maxn],rsum2[maxn];
int fac1[maxn],fac2[maxn];
void init(){
	rep(i,1,n-1){
		sum1[i]=(1ll*mul*sum1[i-1]+b[i])%mod1;
		sum2[i]=(1ll*mul*sum2[i-1]+b[i])%mod2;
	}
	per(i,n-1,1){
		rsum1[i]=(1ll*mul*rsum1[i+1]+b[i])%mod1;
		rsum2[i]=(1ll*mul*rsum2[i+1]+b[i])%mod2;
	}
	fac1[0]=fac2[0]=1;
	rep(i,1,n){
		fac1[i]=1ll*fac1[i-1]*mul%mod1;
		fac2[i]=1ll*fac2[i-1]*mul%mod2;
	}
}
int get1(int l,int r){
	int len=r-l+1;
	return (sum1[r]-1ll*sum1[l-1]*fac1[len]%mod1+mod1)%mod1;
}
int get2(int l,int r){
	int len=r-l+1;
	return (sum2[r]-1ll*sum2[l-1]*fac2[len]%mod2+mod2)%mod2;
}
int rget1(int l,int r){
	int len=r-l+1;
	return (rsum1[l]-1ll*rsum1[r+1]*fac1[len]%mod1+mod1)%mod1;
}
int rget2(int l,int r){
	int len=r-l+1;
	return (rsum2[l]-1ll*rsum2[r+1]*fac2[len]%mod2+mod2)%mod2;
}
bool check(int l,int r){
	if (l>=r)return true;
	int mid=(l+r)>>1;
	if ((l+r)&1){
		return get1(l,mid)==rget1(mid+1,r)&&get2(l,mid)==rget2(mid+1,r);
	}
	else {
		// printf("%d %d %d %d\n",get1(l,mid),rget1(mid,r),get2(l,mid),rget2(mid,r));
		return get1(l,mid)==rget1(mid,r)&&get2(l,mid)==rget2(mid,r);
	}
}
vector<int>res;
int main(){
	read(n);read(m);
	rep(i,1,n)read(a[i]);
	Rep(i,1,n)b[i]=a[i+1]-a[i];
	// Rep(i,1,n)printf("%d ",b[i]);puts("");
	init();
	Rep(i,1,n){
		if (a[1]+a[i]+m==a[i+1]+a[n]&&check(1,i-1)&&check(i+1,n-1)){
			// cerr<<a[1]<<" "<<a[i]<<endl;
			res.pb((a[1]+a[i])%m);
		}
	}
	if (check(1,n-1))res.pb((a[1]+a[n])%m);
	sort(res.begin(),res.end());
	res.resize(unique(res.begin(),res.end())-res.begin());
	printf("%d\n",res.size());
	if (res.size()){Rep(i,0,res.size())printf("%d ",res[i]);puts("");}return 0;
}