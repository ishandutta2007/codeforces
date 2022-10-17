#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2020;
struct pv{
	LL x,y;
	pv (LL _=0,LL __=0){
		x=_;y=__;
	}
}a[M],t[M];
struct line{
	int x,y;
	pv v;
	line(pv _=0,int _0=0,int _1=0){
		v=_; x=_0; y=_1;
	}
}l[M*M];
pv operator -(pv A,pv B){
	return pv(A.x-B.x,A.y-B.y);
}
pv operator +(pv A,pv B){
	return pv(A.x+B.x,A.y+B.y);
}
pv operator *(pv A,double B){
	return pv(A.x*B,A.y*B);
}
LL cross(pv A,pv B){
	return A.x*B.y-A.y*B.x;
}
bool cmp(line A,line B){
	return cross(A.v,B.v)>0;
}
bool cp(pv A,pv B){
	return (A.x<B.x)|(A.x==B.x && A.y<B.y);
}
int n,rk[M],pos[M];
LL S;
int main(){
	n=read(); cin>>S; S<<=1;
	F(i,1,n){
		int x=read(),y=read();
		a[i]=pv(x,y);
	}
	sort(a+1,a+n+1,cp);
	F(i,1,n) rk[i]=pos[i]=i;
	int ct=0;
	F(i,1,n) F(j,i+1,n)
	l[++ct]=line(a[j]-a[i],i,j);
	sort(l+1,l+ct+1,cmp);
	F(i,1,ct){
//		cout<<l[i].v.x<<" "<<l[i].v.y<<"     gg\n";
		pv p=l[i].v;
		int u=l[i].x,v=l[i].y;
		if (rk[u]>rk[v]) swap(u,v);
		int l=1,r=rk[u]-1;
		while (l<=r){
			int mid=(l+r>>1);
			LL area=abs(cross(p,a[pos[mid]]-a[u]));
			if (area==S) {
				cout<<"Yes\n"<<a[u].x<<" "<<a[u].y<<"\n"<<a[v].x<<" "<<a[v].y<<"\n"<<a[pos[mid]].x<<" "<<a[pos[mid]].y<<"\n";
				return 0;
			}
			if (area<S){
				r=mid-1;
			}
			else l=mid+1;
		}
		swap(rk[u],rk[v]);
		swap(pos[rk[u]],pos[rk[v]]);
	}
	cout<<"No\n";
	return 0;
}