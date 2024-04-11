#include<bits/stdc++.h>
#define il inline
#define re register
using namespace std;
typedef long long ll;
const int N=2000001;
int t[N],Q,m=1,L[N],R[N],s[N],p,c[N];
ll l[N],r[N],b[N];
il int d(int a,int b){
	if(a==0) return b;
	if(b<3) return b;
	return 3-a;
}
il void pushdown(int i){
	if(t[i]==0) return;
	if(t[i]==1){
		t[i+i]=t[i+i+1]=1;
		s[i+i]=R[i+i]-L[i+i]+1;
		s[i+i+1]=R[i+i+1]-L[i+i+1]+1;
		t[i]=0;
	}
	else if(t[i]==2){
		t[i+i]=t[i+i+1]=2;
		s[i+i]=s[i+i+1]=0;
		t[i]=0;
	}
	else if(t[i]==3){
		t[i+i]=d(t[i+i],t[i]);
		t[i+i+1]=d(t[i+i+1],t[i]);
		s[i+i]=R[i+i]-L[i+i]+1-s[i+i];
		s[i+i+1]=R[i+i+1]-L[i+i+1]+1-s[i+i+1];
		t[i]=0;
	}
}
il void work(int i,int p,int q,int v){
	if(q<L[i]||p>R[i]) return;
	if(i<m) pushdown(i);
	if(p<=L[i]&&R[i]<=q){
		if(v==1) s[i]=R[i]-L[i]+1;
		if(v==2) s[i]=0;
		if(v==3) s[i]=R[i]-L[i]+1-s[i];
		t[i]=d(t[i],v);
		return;
	}
	work(i+i,p,q,v);work(i+i+1,p,q,v);
	s[i]=s[i+i]+s[i+i+1];
}
il int query(int i){
	if(i<m) pushdown(i);
	if(s[i]==0) return L[i];
	if(s[i+i]<R[i+i]-L[i+i]+1) return query(i+i);
	else return query(i+i+1);
}
int main(){
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		scanf("%d%I64d%I64d",&c[i],&l[i],&r[i]);
		b[++p]=l[i];b[++p]=l[i]+1;
		b[++p]=r[i];b[++p]=r[i]+1;
	}
	b[++p]=1;	
	sort(b+1,b+p+1);
	p=unique(b+1,b+p+1)-b-1;
	for(int i=1;i<=Q;i++){
		l[i]=lower_bound(b+1,b+p+1,l[i])-b;
		r[i]=lower_bound(b+1,b+p+1,r[i])-b;
	}
	while(m<p) m<<=1;
	for(int i=m;i<m+m;i++)
		L[i]=R[i]=i-m+1;
	for(int i=m-1;i;i--)
		L[i]=L[i+i],R[i]=R[i+i+1];
	for(int i=1;i<=Q;i++){
		work(1,l[i],r[i],c[i]);
		printf("%I64d\n",b[query(1)]);
	}
	return 0;
}