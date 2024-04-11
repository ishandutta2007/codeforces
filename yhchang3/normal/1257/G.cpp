#include<bits/stdc++.h>
using namespace std;
//take care of negative 0 ...
typedef long long int ll;
typedef long double ld;
const int maxn = 131072<<1;

struct cplx{
	ld re,im;
	cplx(ld re_=0,ld im_=0):re(re_),im(im_){}
	cplx operator+(const cplx& rhs)const{
		return cplx(re+rhs.re,im+rhs.im);
	}
	cplx operator-(const cplx& rhs)const{
		return cplx(re-rhs.re,im-rhs.im);
	}
	cplx operator*(const cplx& rhs)const{
		return cplx(re*rhs.re-im*rhs.im,re*rhs.im+im*rhs.re);
	}
	cplx conj()const{
		return cplx(re,-im);
	}
}omega[maxn+1];
void pre_fft(){
	ld pi=-1;
	pi=acos(-1);
	for(int i=0;i<=maxn;i++)
		omega[i]=cplx(cos(2*pi*i/maxn),sin(2*pi*i/maxn));
}
void fft(vector<cplx>& v,int n){
	for(int i=0,j=0;i<n;i++){
		if(i>j)	swap(v[i],v[j]);
		for(int s=n>>1;(j^=s)<s;s>>=1);
	}
	for(int s=2;s<=n;s<<=1){
		int z=s>>1;
		for(int i=0;i<n;i+=s)
			for(int j=0;j<z;j++){
				cplx x=v[i+z+j]*omega[maxn/s*j];
				v[i+z+j]=v[i+j]-x;
				v[i+j]=v[i+j]+x;
			}
	}
}
void ifft(vector<cplx>& v,int n){
	fft(v,n);
	reverse(v.begin()+1,v.end());
	for(int i=0;i<n;i++)
		v[i]=v[i]*cplx(1.0L/n,0);
}
vector<int> conv(const vector<int>& a,const vector<int>& b,int p){
	int sz=1;
	while(sz<a.size()+b.size()-1)	sz<<=1;
	vector<cplx> fa(sz),fb(sz),ra(sz),rb(sz);
	for(int i=0;i<a.size();i++){
		int x=(a[i]%p+p)%p;
		fa[i]=cplx(x&((1<<15)-1),x>>15);
	}
	for(int i=0;i<b.size();i++){
		int x=(b[i]%p+p)%p;
		fb[i]=cplx(x&((1<<15)-1),x>>15);
	}
	fft(fa,sz);fft(fb,sz);
	for(int i=0;i<sz;i++){
		int j=(sz-1)&(sz-i);
		cplx tmpa=(fa[i]+fa[j].conj())*cplx(0.5,0);
		cplx tmpb=(fa[i]-fa[j].conj())*cplx(0,-0.5);
		cplx tmpc=(fb[i]+fb[j].conj())*cplx(0.5,0);
		cplx tmpd=(fb[i]-fb[j].conj())*cplx(0,-0.5);
		ra[j]=tmpa*tmpc+tmpa*tmpd*cplx(0,1);
		rb[j]=tmpb*tmpc+tmpb*tmpd*cplx(0,1);
	}
	fft(ra,sz);fft(rb,sz);
	vector<int> res(sz);
	for(int i=0;i<sz;i++){
		long long int tmpa=round(ra[i].re/sz);
		long long int tmpb=round(ra[i].im/sz);
		long long int tmpc=round(rb[i].re/sz);
		long long int tmpd=round(rb[i].im/sz);
		res[i]=(tmpa+(((tmpb+tmpc)%p)<<15)+((tmpd%p)<<30))%p;
	}
	while(!res.empty()&&res.back()==0)	res.pop_back();
	return res;
}


vector<int> v;

vector<int> solve(int l,int r){
	if(l==r){
		vector<int> res(v[l]+1,1);
		return res;
	}
	int mid=(l+r)/2;
	auto r1=solve(l,mid),r2=solve(mid+1,r);
	return conv(r1,r2,998244353);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre_fft();
	int n;
	cin>>n;
	map<int,int> m;
	for(int i=1,p;i<=n;i++){
		cin>>p;
		m[p]++;
	}
	for(auto it:m)
		v.emplace_back(it.second);
	auto res=solve(0,v.size()-1);
	cout<<res[n/2]<<endl;
}