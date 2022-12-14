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
	MOD operator-()const{
		return MOD(-x);
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

#define poly vector<MOD>
poly conv(const poly& a,const poly& b){
	int sz=1;
	while(sz<a.size()+b.size()-1)	sz<<=1;
	poly fa(sz),fb(sz);
	for(int i=0;i<a.size();i++)
		fa[i]=a[i];
	for(int i=0;i<b.size();i++)
		fb[i]=b[i];
	ntt(fa,sz,0);ntt(fb,sz,0);
	for(int i=0;i<sz;i++)
		fa[i]=fa[i]*fb[i];
	ntt(fa,sz,1);
	return fa;
	
}
poly deriv(const poly& a){
	if(a.empty())	return {};
	poly b(a.size()-1);
	for(int i=1;i<a.size();i++)
		b[i-1]=a[i]*i;
	return b;
}

poly integ(const poly& a){
	poly b(a.size()+1);
	b[1]=1;
	for(int i=2;i<b.size();i++)
		b[i]=b[P%i]*(-P/i);
	for(int i=1;i<b.size();i++)
		b[i]=b[i]*a[i-1];
	return b;
}
poly inverse(const poly& a){
	if(a.empty())	return {};
	poly b({mypow(a[0],P-2)}),fa;
	b.reserve(a.size()*2);
	while(b.size()<a.size()){
		int n=2*b.size();
		b.resize(2*n,0);
		fa.resize(2*n);
		copy(a.begin(),a.begin()+min(n,(int)a.size()),fa.begin());
		fill(fa.begin()+min(n,(int)a.size()),fa.end(),0);
		ntt(b,2*n,0);ntt(fa,2*n,0);
		for(int i=0;i<2*n;i++)
			b[i]=b[i]*(-fa[i]*b[i]+2);
		ntt(b,2*n,1);
		b.resize(n);
	}
	b.resize(a.size());
	return b;
}
poly log(const poly& a){//a[0]=1
	poly b=integ(conv(deriv(a),inverse(a)));
	b.resize(a.size());
	return b;
}

poly exp(const poly& a){//a[0]=0
	poly b({MOD(1)});
	if(a.empty())	return b;
	while(b.size()<a.size()){
		int n=min(b.size()*2,a.size());
		b.resize(n);
		poly v=log(b);
		for(int i=0;i<n;i++)
			v[i]=a[i]-v[i];
		v[0]=v[0]+1;
		b=conv(b,v);
		b.resize(n);
	}
	return b;
}

poly pow(const poly& a,int m){
	poly b(a.size());
	if(!m){b[0]=1;return b;}
	int p=0;
	while(p<a.size()&&a[p].x==0)	p++;
	if(1LL*m*p>=a.size())	return b;
	MOD mu=mypow(a[p],m),di=mypow(a[p],P-2);
	poly c(a.size()-m*p);
	for(int i=0;i<c.size();i++)
		c[i]=a[i+p]*di;
	c=log(c);
	for(auto& it:c)
		it=it*m;
	c=exp(c);
	for(int i=0;i<c.size();i++)
		b[i+m*p]=c[i]*mu;
	return b;
}
poly sqrt(const poly& a){//a[0]=1	
	poly b({MOD(1)});
	if(a.empty())	return {};
	while(b.size()<a.size()){
		int n=min(b.size()*2,a.size());
		poly v=conv(b,b);
		v.resize(n);
		b.resize(n);
		for(int i=0;i<b.size();i++)
			v[i]=(v[i]+a[i])*((P+1)>>1);
		b=conv(v,inverse(b));
		b.resize(n);
	}
	return b;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre_ntt();
	int n,m;
	cin>>n>>m;
	int mm=1e9;
	vector<int> tmp(n);
	for(int i=0;i<n;i++){
		cin>>tmp[i];
		mm=min(mm,tmp[i]);
	}
	poly T(100001+mm),TT(100001+mm);
	for(int i=0;i<n;i++){
		TT[tmp[i]]=-4;
		T[tmp[i]-mm]=2;
	}
	TT[0]=1;
	TT=sqrt(TT);
	for(int i=0;i<TT.size();i++)
		TT[i]=-TT[i];
	TT[0]=TT[0]+1;
	for(int i=0;i+mm<TT.size();i++)
		TT[i]=TT[i+mm];
	T=inverse(T);
	TT=conv(TT,T);
	for(int i=1;i<=m;i++)
		cout<<TT[i].x<<'\n';	
}