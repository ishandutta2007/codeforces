#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
char c1[N],c2[N*2],ans[N],c0[N],c3[N],c4[N],c5[N];
int n,K,i,j,k,l,d,be[N],le[N],cnt[N],xb,m,ml[N*2],L,m3,m5,x,y;
inline void duval(){
	for(i=d=1,l=0,j=2;j<=n+1;++j,l==d-1?l=0:++l)
		if(c2[j]>c2[i+l])d=j-i+1,l=-1;
			else if(c2[j]<c2[i+l]){be[++xb]=i;le[xb]=d;cnt[xb]=(j-i)/d;j=i+=cnt[xb]*d;d=1;l=-1;}
}
inline void exkmp(){
	int id=0,mr=0;
	for(i=2;i<=L*2;++i){
		if(i<=mr)ml[i]=min(mr-i+1,ml[i-id+1]);
		for(;i+ml[i]<=L*2 && c2[ml[i]+1]==c2[i+ml[i]];++ml[i]);
		if(i+ml[i]-1>mr)mr=i+ml[i]-1,id=i;
	}
}
inline bool cmp(int x,int y){//x<y
	l=ml[L+x];
	return l>=y-x?l=ml[y-x+1],c2[y-x+l+1]<c2[l+1]:c0[L-l]<c0[x+l];
}
inline bool cmp2(int x,int y){
	l=ml[L-(y-x)+1];
	return l>=y-x?l=ml[y-x+1],c2[y-x+l+1]<c2[l+1]:c2[1+l]<c2[L-(y-x)+1+l];
}
inline int scmp(char*s,char*t,int l){int i=0;for(;i<l && s[i]==t[i];++i);return i==l?0:(s[i]<t[i]?1:-1);}
inline void upd(char*a,char*b){if(scmp(b+1,a+1,L)==1)memcpy(a+1,b+1,L);}
inline bool isP(int l,int r){return !scmp(c2+l,c1+n-r+1,r-l+1);}
int main(){
	scanf("%s%d",c1+1,&K);n=strlen(c1+1);
	memcpy(c2+1,c1+1,n);reverse(c2+1,c2+n+1);
	if(K==1)return L=n,upd(c1,c2),fwrite(c1+1,1,n,stdout),0;
	duval();
	for(m=1;xb && K>2;--K){
		x=cnt[xb]*le[xb];
		if(isP(be[xb],be[xb]+x-1)){
			for(;x=cnt[xb]*le[xb],xb && isP(be[xb],be[xb]+x-1);--xb)
				memcpy(ans+m,c2+n-m+1-x+1,x),m+=x;
		}else memcpy(ans+m,c2+n-m+1-x+1,x),m+=x,--xb;
	}
	if(xb){
		L=n-m+1;memcpy(c2+L+1,c1+m,L);exkmp();
		memcpy(c0+1,c1+m,L);
		x=0;
		for(i=xb;i>1;--i){
			x+=le[i]*cnt[i],y=le[i-1];
			if(y>x && !scmp(c0+1,c0+y+1,x) && scmp(c2+L-y+1,c0+x+1,y-x)>=0);else break;
		}
		if(i<xb){
			m3=x=0;
			for(j=xb;j>=i;--j)
				for(k=1;k<=cnt[j];++k)
					if(x+=le[j],!m3 || !cmp2(m3+1,x+1))m3=x;
			memcpy(c3+1,c2+L-m3+1,m3);memcpy(c3+m3+1,c2+1,L-m3);
			memcpy(c4+1,c2+L-x+1,x);memcpy(c4+x+1,c0+x+1,L-x);
		}else{
			memcpy(c3+1,c2+L-x+1,x),memcpy(c3+x+1,c0+x+1,L-x);
			memcpy(c4+1,c2+L-x+1,x),memcpy(c4+x+1,c2+1,L-x);
		}
		upd(c3,c4);
		m5=L;for(i=L-1;i;--i)if(cmp(i,m5))m5=i;
		memcpy(c5+1,c0+1,m5-1);memcpy(c5+m5,c2+1,L-m5+1);
		upd(c0,c3);upd(c0,c5);
		memcpy(ans+n-L+1,c0+1,L);
	}
	fwrite(ans+1,1,n,stdout);
	return 0;
}