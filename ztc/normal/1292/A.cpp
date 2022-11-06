#include<stdio.h>
int a[1000002][2],n,m,cnt=0;
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int r,c;scanf("%d%d",&c,&r);c--;
		if(a[r][c]==0){
			if(a[r-1][c^1]==1)cnt++;
			if(a[r][c^1]==1)cnt++;
			if(a[r+1][c^1]==1)cnt++;
		}else{
			if(a[r-1][c^1]==1)cnt--;
			if(a[r][c^1]==1)cnt--;
			if(a[r+1][c^1]==1)cnt--;
		}puts(cnt==0&&a[n][1]==0?"Yes":"No");a[r][c]^=1;
	}
}