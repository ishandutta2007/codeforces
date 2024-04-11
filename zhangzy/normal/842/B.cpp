#include<bits/stdc++.h>
using namespace std;
int r,d,x,y,c,t1,t2,n,ans=0;

int main(){
	scanf("%d%d%d",&r,&d,&n);
	for (;n--;){
		scanf("%d%d%d",&x,&y,&c);
		if (d>=c*2){
			if ((r-d+c)*(r-d+c)<=x*x+y*y&&(r-c)*(r-c)>=x*x+y*y){
				ans++;
			}
		}
	}
	printf("%d",ans);
}