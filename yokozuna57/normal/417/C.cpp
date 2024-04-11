#include<iostream>
using namespace std;

int main(){
	int n,k;
	static int used[1002][1002]={0},t=true;;
	for(int i=1;i<=1000;i++)used[i][i]=-2;

	int ret=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(used[i][j]==0){
				cnt++;
				used[i][j]=1;
				used[j][i]=-1;
				if(cnt==k)break;
			}
		}
		if(cnt<k)t=false;
		ret+=cnt;
	}

	if(t){
		printf("%d\n",ret);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(used[i][j]==1){
					printf("%d %d\n",i,j);
				}
			}
		}
	}
	else printf("-1\n");
}