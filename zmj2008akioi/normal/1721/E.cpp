#include <cstdio>
#include <cstring>
const int G=26,N=2e6+10;
int n,q,p[N],rec[N][G];char s[N];
int idx(char c){return c-'a';}
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	scanf("%d",&q);int w=0;rec[1][idx(s[2])]=1;
	for(int i=2;i<=n;++i){
		while(w&&s[i]!=s[w+1])w=p[w];
		if(s[i]==s[w+1])++w;p[i]=w;
		for(int j=0;j<G;++j)rec[i][j]=rec[p[i]][j];
		rec[i][idx(s[i+1])]=i;
	}
	while(q--){
		scanf("%s",s+n+1);
		for(int i=n+1,j=w;s[i]!='\0';++i){
			while(j>=n&&s[i]!=s[j+1])j=p[j];
			if(j<n)j=rec[j][idx(s[i])];
			if(s[i]==s[j+1])++j;p[i]=j,printf("%d ",j);
		}
		putchar('\n');
	}
	return 0;
}