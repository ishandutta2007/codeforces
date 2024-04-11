#include<stdio.h>
int n,t,p,q,r;
inline int Abs(int p){return p<0?-p:p;}
inline int Max(int p,int q){return p>q?p:q;}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		p=2e9;q=-2e9;r=0;
		for(int i=1,j=-2,k;i<=n;i++,j=k){
			scanf("%d",&k);if(j!=-2)
			if(~j!=0^~k!=0){
				if(j>q)q=j;
				if(k>q)q=k;
				if(j<p&&~j)p=j;
				if(k<p&&~k)p=k;
			}if(j!=-2&&~j&&~k&&Abs(j-k)>r)r=Abs(j-k);
		}int v=p+q>>1;
		if(q<0)printf("%d %d\n",r,1);
		else printf("%d %d\n",Max(r,q-p+1>>1),v);
	}
}