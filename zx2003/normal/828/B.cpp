#include<cstdio>
const int N=105;
char c[N][N];
int x1,y1,x2,y2,x3,y3,x4,y4,i,j,n,m,a,b,s;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%s",c[i]+1);
		for(j=1;j<=m;++j){
			if(c[i][j]=='B'){
				++s;
				if(!x1)x1=i,y1=j;
				if(!y2 || j<y2)x2=i,y2=j;
				x3=i;
				y3=j;
				if(!y4 || j>y4)x4=i,y4=j;
			}
		}
	}
	if(!x1)return puts("1"),0;
	a=x3-x1+1;
	b=y4-y2+1;
	if(a>b){
		if(a<=m)printf("%d\n",a*a-s);
			else puts("-1");
	}else{
		if(b<=n)printf("%d\n",b*b-s);
			else puts("-1");
	}
}