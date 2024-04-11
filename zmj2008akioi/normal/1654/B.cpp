#include <cstdio>
#include <cstring>
int T,n,p,bkt[1000];
char s[200010];
int main(){
	scanf("%d",&T);
	while(T--){
		memset(bkt,0,sizeof(bkt));
		scanf("%s",s+1),n=strlen(s+1);
		for(int i=1;i<=n;++i)++bkt[(int)s[i]];
		for(int i=1;i<=n;++i){
			--bkt[(int)s[i]];
			if(!bkt[(int)s[i]]){p=i;break;}
		}
		for(int i=p;i<=n;++i)putchar(s[i]);
		putchar('\n');
	}
	return  0;
}