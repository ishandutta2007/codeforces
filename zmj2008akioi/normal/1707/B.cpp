#include <cstdio>
#include <algorithm>
const int N=1e5+10;
int T,n,pnt,qnt,a[N];
struct pr{
	int v,c;
	pr(){};
	pr(int v,int c):v(v),c(c){};
	inline bool operator<(const pr &nxt)const{return v<nxt.v;}
}prr[N],qrr[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		pnt=0;
		for(int i=1;i<n;++i)prr[++pnt]=pr(a[i+1]-a[i],1);
		while((--n)>1){
			std::sort(prr+1,prr+pnt+1),qrr[qnt=1]=prr[1];
			for(int i=2;i<=pnt;++i){
				if(prr[i].v==qrr[qnt].v)qrr[qnt].c+=prr[i].c;
				else qrr[++qnt]=prr[i];
			}
			pnt=0;
			for(int i=1;i<=qnt;++i){
				if(qrr[i].c!=1)prr[++pnt]=pr(0,qrr[i].c-1);
				if(i!=qnt)prr[++pnt]=pr(qrr[i+1].v-qrr[i].v,1);
			}
		}
		printf("%d\n",prr[1].v);
	}
	return 0;
}