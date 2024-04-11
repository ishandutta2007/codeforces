#include<bits/stdc++.h>
using namespace std;
const int N=100005;
typedef unsigned long long ll;
const ll iv5=14757395258967641293ull;
int n,x[N],i,j;
struct atom{
	ll a[5];
	inline atom operator*(const atom&rhs)const{
		static atom ans;static ll b[10];
		memset(b,0,80);
		for(int i=0;i<5;++i)for(int j=0;j<5;++j)b[i+j]+=a[i]*rhs.a[j];
		for(int i=0;i<5;++i)ans.a[i]=b[i]-b[i+5];
		return ans;
	}
	inline void operator+=(const atom&rhs){for(int i=0;i<5;++i)a[i]+=rhs.a[i];}
}w[10],a[N],O;
inline atom poww(atom x,int y){
	atom ans=w[0];
	for(;y;y>>=1,x=x*x)if(y&1)ans=ans*x;
	return ans;
}
int key=1;
void DFT(int l,int R){
	if(l+1==R)return;
	int k=(R-l)/10,i,j,p,q,r;
	for(i=l;i<R;i+=k)DFT(i,i+k);
	for(i=0;i<k;++i){
		static atom b[10],c[10];
		for(j=l+i,p=0;j<R;j+=k)b[p++]=a[j];
		for(j=0;j<10;++j){
			c[j]=O;
			for(r=q=0;r<10;++r,q+=key==1?j:10-j,q>=10?q-=10:0)c[j]+=b[r]*w[q];
		}
		for(j=l+i,p=0;j<R;j+=k)a[j]=c[p++];
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)cin>>x[i],++a[x[i]].a[0];
	for(i=0;i<5;++i)w[i].a[i]=1;for(;i<10;++i)w[i].a[i-5]=-1;
	DFT(0,N-5);
	for(i=0;i<N-5;++i)a[i]=poww(a[i],n);
	key=-1;
	DFT(0,N-5);
	for(i=0;i<n;++i){
		ll x=a[i].a[0]-a[i].a[2];
		for(j=0;j<5;++j)x*=iv5;
		x>>=5;
		cout<<(x&((1ull<<58)-1))<<'\n';
	}
	return 0;
}