#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define IN inline int
int n,m,k,t,p,q,X,Y,sum,lim,a[202000];
inline bool bbb(int x,int y){
	return x>y;
}
struct Barr{
	int l,r,w;
	friend bool operator < (Barr x,Barr y){
		return x.l==y.l?x.r<y.r:x.l<y.l;
	}
}b[202000];
IN ck(int x){
	if(!x)return 1;
	sum=0;
	lim=a[x];
	p=1;
	while(p<=k&&b[p].w<=lim)p++;
	if(p>k)X=sum=0;
	else sum=X=b[p].l-1;
	while(p<=k){
		Y=b[p].r;
		q=p+1;
		while(q<=k&&(b[q].w<=lim||b[q].l<=Y)){
			if(b[q].w>lim)Y=max(Y,b[q].r);
			q++;
		}
		sum+=3*(Y-X);
		X=Y;
		if(q>k)break;
		sum+=(b[q].l-1-X);
		X=b[q].l-1;
		p=q;
	}
	sum+=(m-X);
	//cout<<x<<" "<<sum<<endl;
	if(sum<=t)return 1;
	return 0;
}
IN divided(int x,int y){
	if(x==y)return x;
	re mid=(x+y+1)>>1;
	if(ck(mid))x=mid;
	else y=mid-1;
	return divided(x,y);
}
int main(){
	cin>>n>>m>>k>>t;m++;
	F(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+1+n,bbb);
	F(i,1,k){
		cin>>b[i].l>>b[i].r>>b[i].w;
	}
	sort(b+1,b+1+k);
	b[k+1].l=0;
	if(m>t){
		cout<<"0";
		return 0;
	}
	cout<<divided(0,n);
    return 0;
}