#include<stdio.h>
#include<vector>
#include<memory.h>
std::vector<unsigned long long>V[16384][14];
int n,mp[102][102],mk[102];
char c[102];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",c);
		for(int j=0;j<n;j++)mp[i][j]=c[j]=='1';
	}for(int i=1;i<1<<n;i++){
		int cnt=0,t=0;
		for(int j=0;j<n;j++)mk[j]=i>>j&1,cnt+=mk[j],t=mk[j]?j:t;
		for(int j=0;j<n;j++)if(mk[j])V[i][j].resize(1<<cnt-1);
		if(cnt==1)V[i][t][0]=1;
		else{
			for(int p=0;p<n;p++)if(mk[p]){
				for(int q=0;q<n;q++)if(q!=p&&mk[q]){
					for(int j=0;j<1<<cnt-2;j++)V[i][p][j|mp[p][q]<<cnt-2]+=V[i^1<<p][q][j];
				}
			}
		}
	}for(int i=0;i<1<<n-1;i++){
		long long cnt=0;
		for(int j=0;j<n;j++)cnt+=V[(1<<n)-1][j][i];
		printf("%lld ",cnt);
	}
}