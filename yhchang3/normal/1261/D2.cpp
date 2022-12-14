#include<bits/stdc++.h>
using namespace std;

//2^16+1,65537,3
//119*2^23+1,998244353,3
//1255*2^20+1,1315962881,3
//51*2^25+1,1711276003,29
//479*2^21+1,1004535809,3

const int maxn = 131072<<2;
const int P =  998244353;

struct MOD{
	int x;
	MOD (int x_=0):x(x_){
		if(x<0)	x+=P;if(x>=P)	x-=P;
	}
	MOD operator+(const MOD& rhs)const{
		return MOD(x+rhs.x);
	}
	MOD operator-(const MOD& rhs)const{
		return MOD(x-rhs.x);
	}
	MOD operator*(const MOD& rhs)const{
		return MOD(int(1LL*x*rhs.x%P));
	}
}w[maxn+1];

MOD mypow(MOD x,int b){
	MOD res=1;
	while(b){
		if(b&1)	res=res*x;
		x=x*x;
		b>>=1;
	}
	return res;
}

void pre_ntt(){
	MOD dw = mypow(3,(P-1)/maxn);
	w[0]=1;
	for(int i=1;i<=maxn;i++)
		w[i]=w[i-1]*dw;
}
void ntt(vector<MOD>& v,int n,bool inv){
	for(int i=0,j=0;i<n;i++){
		if(i>j)	swap(v[i],v[j]);
		for(int s=n>>1;(j^=s)<s;s>>=1);
	}
	for(int s=2;s<=n;s<<=1){
		int z=s>>1;
		for(int i=0;i<n;i+=s)
			for(int j=0;j<z;j++){
				MOD x=v[i+z+j]*w[maxn/s*j];
				v[i+z+j]=v[i+j]-x;
				v[i+j]=v[i+j]+x;
			}
	}
	if(inv){
		reverse(v.begin()+1,v.end());
		MOD invn = mypow(n,P-2);
		for(int i=0;i<n;i++)	v[i]=v[i]*invn;
	}
}
vector<int> conv(const vector<int>& a,const vector<int>& b){
	int sz=1;
	while(sz<a.size()+b.size()-1)	sz<<=1;
	vector<MOD> fa(sz),fb(sz);
	for(int i=0;i<a.size();i++)
		fa[i]=a[i];
	for(int i=0;i<b.size();i++)
		fb[i]=b[i];
	ntt(fa,sz,0);ntt(fb,sz,0);
	for(int i=0;i<sz;i++)
		fa[i]=fa[i]*fb[i];
	ntt(fa,sz,1);
	vector<int> res(sz);
	for(int i=0;i<sz;i++)
		res[i]=fa[i].x;
	while(!res.empty()&&res.back()==0)	res.pop_back();
	return res;
}

int h[200000];
 

vector<int> mypow(vector<int> x,int b){
	vector<MOD> fx(maxn);
	for(int i=0;i<x.size();i++)
		fx[i]=x[i];
	ntt(fx,maxn,0);
	for(int i=0;i<maxn;i++)
		fx[i]=mypow(fx[i],b);
	ntt(fx,maxn,1);
	vector<int> res(maxn);
	for(int i=0;i<maxn;i++)
		res[i]=fx[i].x;
	while(!res.empty()&&res.back()==0)	res.pop_back();
	return res;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre_ntt();
	int n,k;
	cin>>n>>k;
	int cnt1=0,cnt2=0;
	for(int i=0;i<n;i++)
		cin>>h[i];
	for(int i=0;i<n;i++)
		if(h[i]==h[(i+1)%n])
			cnt1++;
		else
			cnt2++;
	if(k==1){
		cout<<0<<endl;
		return 0;
	}
	vector<int> v1,v2;
	v1={0,k%P,0};
	v2={1,(k-2)%P,1};
	v1=mypow(v1,cnt1);
	v2=mypow(v2,cnt2);
	auto res=conv(v1,v2);
	long long int ans=0;
	for(int i=n+1;i<res.size();i++)
		ans=(ans+res[i])%P;
	cout<<ans<<endl;
}