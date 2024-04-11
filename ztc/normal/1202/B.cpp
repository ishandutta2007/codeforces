#include<stdio.h>
#include<queue>
int a[2000002],n,c[10],ans,dis[10];
void bfs(int s1,int s2){
	for(int i=0;i<=9;i++)dis[i]=1000000007;
	std::queue<int>Q;dis[s1]=dis[s2]=0;
	Q.push(s1);if(s1!=s2)Q.push(s2);
	while(!Q.empty()){
		int t=Q.front();Q.pop();
		if(dis[(t+s1)%10]>dis[t]+1){Q.push((t+s1)%10);dis[(t+s1)%10]=dis[t]+1;}
		if(dis[(t+s2)%10]>dis[t]+1){Q.push((t+s2)%10);dis[(t+s2)%10]=dis[t]+1;}
	}for(int i=0;i<=9;i++)if(dis[i]>=1000000007)dis[i]=-1;
}
int main(){
	while((a[++n]=getchar()-'0')>=0);n--;
	for(int i=n;i>1;i--)c[(a[i]+10-a[i-1])%10]++;
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){bfs(i,j);ans=0;
			for(int k=0;k<=9;k++){
				if(c[k]&&dis[k]==-1){ans=-1;break;}
				ans+=c[k]*dis[k];
			}printf("%d ",ans);
		}putchar('\n');
	}
}