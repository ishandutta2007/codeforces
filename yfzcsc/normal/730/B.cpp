#include<bits/stdc++.h>
using namespace std;
int mx,mn,n,t;
char res[3];
int getres(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%s",res);
	if(res[0]=='>')return 1;
	return res[0]=='='?2:3;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1){
			printf("! 1 1\n");
			fflush(stdout);
			continue;
		}
		int m=getres(1,n);
		if(m<=2)mx=1,mn=n;
		else if(m==3)mx=n,mn=1;
		for(int i=2,j=n-1;i<=j;i++,j--){
			if(i==j){
				int z=getres(i,mx);
				if(z<=2)mx=i;
				else if(getres(mn,i)<=2)mn=i;
			} else {
				int z=getres(i,j);
				int ni=i,nj=j;
				if(z==3)swap(ni,nj);
				if(getres(ni,mx)<=2)mx=ni;
				if(getres(nj,mn)==3)mn=nj;
			}
		}
		printf("! %d %d\n",mn,mx);
		fflush(stdout);
	}
	
}