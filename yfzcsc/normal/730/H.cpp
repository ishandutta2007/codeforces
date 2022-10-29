#include<bits/stdc++.h>
#define maxn 210
using namespace std;
char cre[maxn],str[maxn][210];
int n,m,a[maxn],vis[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s",str[i]+1);
	for(int i=1;i<=m;++i)
		scanf("%d",&a[i]),vis[a[i]]=1;
	int stdlen=strlen(str[a[1]]+1);
	for(int i=2;i<=m;++i)
		if(strlen(str[a[i]]+1)!=stdlen){
			printf("No");
			return 0;
		}
	for(int i=1;i<=stdlen;++i){
		char x=str[a[1]][i];
		for(int j=2;j<=m;++j)
			if(str[a[j]][i]!=x){
				cre[i]='?';
				goto _end;
			}
		cre[i]=x;
		_end:;	
	}
	
	for(int i=1;i<=n;++i)if(!vis[i]){
		if(strlen(str[i]+1)!=stdlen)continue;
		for(int j=1;j<=stdlen;++j){
			//if(i==2)printf("[%c]",str[i][j]);
			if(cre[j]!='?'&&str[i][j]!=cre[j]){
				goto end;
			}
		}
		printf("No");
		return 0;
		end:;
	}
	
	printf("Yes\n");
	printf("%s",cre+1);
		
}