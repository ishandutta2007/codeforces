#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define IN inline int
struct P{
	int w,id;
	friend bool operator < (P x,P y){
		return x.w<y.w;
	}
}p[2020];
int n,m,v[2020],a[2020],sn;
IN ck(int x){
	sn=0;
	memset(v,0,sizeof(v));
	F(i,1,n-x){
		v[a[i]]++;
		if(v[a[i]]==2)sn++;
	}
	if(!sn)return 1;
	FOR(i,n-x,1){
		v[a[i]]--;
		if(v[a[i]]==1)sn--;
		v[a[i+x]]++;
		if(v[a[i+x]]==2)sn++;
		if(!sn)return 1;
	}
	return 0;
}
IN divided(int x,int y){
	if(x==y)return x;
	re mid=(x+y)>>1;
	if(ck(mid))y=mid;
	else x=mid+1;
	return divided(x,y);
}
int main(){
	cin>>n;
	F(i,1,n){
		cin>>a[i];
		p[i].w=a[i];p[i].id=i;
	}
	sort(p+1,p+1+n);
	m=1;
	F(i,1,n){
		a[p[i].id]=m;
		if(p[i].w!=p[i+1].w)m++;
	}
	cout<<divided(0,n-1);
    return 0;
}