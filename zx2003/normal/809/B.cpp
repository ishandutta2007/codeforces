#include<cstdio>
int n,k,l,r,m,x,y;
char c[10];
inline bool ask(int x,int y){
	printf("1 %d %d\n",x,y);
	fflush(stdout);
	scanf("%s",c);
	return *c=='T';
}
inline int solve(int l,int r){	
	for(;l<r;){
		m=(l+r)>>1;
		if(ask(m,m+1))r=m;else l=m+1;
	}
	return l;
}
int main(){
	scanf("%d%d",&n,&k);
	x=solve(1,n);
	if(x==1)y=solve(2,n);
		else{
			y=solve(1,x-1);
			if(!ask(y,x))y=solve(x+1,n);
		}
	printf("2 %d %d\n",x,y);
	fflush(stdout);
	return 0;
}