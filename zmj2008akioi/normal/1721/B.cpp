#include <cstdio>
int T,n,m,x,y,d;
int rv(int x){return x>0?x:(-x);}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %d %d",&n,&m,&x,&y,&d);
		if(((x-d<=1||y+d>=m)&&(x+d>=n||y-d<=1))||rv(n-x)+rv(m-y)<=d)puts("-1");
		else printf("%d\n",n+m-2);
	}
	return 0;
}