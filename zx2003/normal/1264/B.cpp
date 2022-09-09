#include<bits/stdc++.h>
using namespace std;
int a[4],tot,i,ans[100005],b[4];
void tryy(int x){
	memcpy(b,a,16);ans[1]=x;--b[x];
	for(int i=2;i<=tot;++i){
		if(ans[i-1]>0 && b[ans[i-1]-1])--b[ans[i]=ans[i-1]-1];
			else if(ans[i-1]<3 && b[ans[i-1]+1])--b[ans[i]=ans[i-1]+1];
					else return;
	}
	puts("YES");
	for(i=1;i<=tot;++i)printf("%d ",ans[i]);puts("");
	exit(0);
}
int main(){
	for(i=0;i<4;++i)scanf("%d",a+i),tot+=a[i];
	for(i=0;i<4;++i)if(a[i])tryy(i);
	puts("NO");
	return 0;
}