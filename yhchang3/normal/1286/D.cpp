#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

long long int ksm(long long int x,int b){
	long long int res=1;
	while(b){
		if(b&1)	res=res*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return res;
}

struct Collision{
	long long int num,den;
	int lid;
	bool dirl,dirr;
	Collision(long long int num_=0,long long int den_=0,int lid_=0,bool dirl_=false,bool dirr_=false):num(num_),den(den_),lid(lid_),dirl(dirl_),dirr(dirr_){}
	bool operator<(const Collision& rhs)const{
		return num*rhs.den<den*rhs.num;
	}
};


int x[100001],v[100001],prob[100001];

long long int p[400010][2][2];
bool ban[100001][2][2];
void add(long long int& x,const long long int& y){
	x=x+y;
	if(x>=mod)	x-=mod;
	if(x<0)	x+=mod;
}
void pull(int idx,int mid){
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			p[idx][i][j]=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				for(int l=0;l<2;l++)
					if(!ban[mid][j][k])
						add(p[idx][i][l],p[idx<<1][i][j]*p[idx<<1|1][k][l]%mod);
				
}
void build(int idx,int l,int r){
	if(l==r){
		p[idx][1][1]=prob[l];
		p[idx][0][0]=(1+mod-prob[l])%mod;
		return;
	}
	int mid=(l+r)>>1;
	build(idx<<1,l,mid);
	build(idx<<1|1,mid+1,r);
	pull(idx,mid);
}
void update(int idx,int l,int r,int pos){
	if(l==r)	return;
	int mid=(l+r)>>1;
	if(pos<=mid)
		update(idx<<1,l,mid,pos);
	else
		update(idx<<1|1,mid+1,r,pos);
	pull(idx,mid);

}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<Collision> E;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>v[i]>>prob[i];
	for(int i=1;i<=n;i++)
		prob[i]=(long long int) prob[i]*ksm(100,mod-2)%mod;
	build(1,1,n);
	for(int i=1;i<n;i++){
		if(v[i]<v[i+1]){
			E.emplace_back(Collision(x[i+1]-x[i],v[i+1]-v[i],i,0,0));
			E.emplace_back(Collision(x[i+1]-x[i],v[i+1]+v[i],i,1,0));
		}
		else if(v[i]>v[i+1]){
			E.emplace_back(Collision(x[i+1]-x[i],v[i]-v[i+1],i,1,1));
			E.emplace_back(Collision(x[i+1]-x[i],v[i+1]+v[i],i,1,0));
		}
		else{
			E.emplace_back(Collision(x[i+1]-x[i],v[i+1]+v[i],i,1,0));
		}
	}
	sort(E.begin(),E.end());
	long long int ans=0;
	for(auto &e:E){
		bool modify[2][2];
		memset(modify,false,sizeof modify);
		for(int l=0;l<2;l++)
			for(int r=0;r<2;r++){
				if(e.dirl==l&&e.dirr==r)	continue;
				if(!ban[e.lid][l][r]){
					ban[e.lid][l][r]=true;
					modify[l][r]=true;
				}
			}
		update(1,1,n,e.lid);
		long long int t=e.num*ksm(e.den,mod-2)%mod;
		for(int l=0;l<2;l++)
			for(int r=0;r<2;r++)
				add(ans,p[1][l][r]*t%mod);	
		ban[e.lid][e.dirl][e.dirr]=true;
		for(int l=0;l<2;l++)
			for(int r=0;r<2;r++){
				if(e.dirl==l&&e.dirr==r)	continue;
				if(modify[l][r]){
					ban[e.lid][l][r]=false;
				}
			}
		update(1,1,n,e.lid);
		
	}
	cout<<ans<<endl;
}