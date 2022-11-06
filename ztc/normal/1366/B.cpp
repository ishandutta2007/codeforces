#include<stdio.h>
inline int Min(int p,int q){return p<q?p:q;}
inline int Max(int p,int q){return p>q?p:q;}
int n,m,t,l,r;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&l,&m);r=l;
		while(m--){
			int hdhd,akioi;scanf("%d%d",&hdhd,&akioi);
			if(!(hdhd>r||akioi<l))l=Min(l,hdhd),r=Max(r,akioi);
		}printf("%d\n",r-l+1);
	}
}