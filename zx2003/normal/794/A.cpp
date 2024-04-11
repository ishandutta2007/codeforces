#include<cstdio>
typedef long long ll;
typedef unsigned int ui;
int a,b,c,ans,n,i,x;
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&n);
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		if(x>b && x<c)++ans;
	}
	printf("%d\n",ans);
	return 0;
}