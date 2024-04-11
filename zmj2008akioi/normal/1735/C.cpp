#include <cstdio>
const int G=26,N=1e5+10;
int T,n,f[N];char s[N],t[N];bool us[N];
int idx(char c){return c-'a';}
int find(int x){return f[x]==x?f[x]:f[x]=find(f[x]);}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %s",&n,s+1);int c=0;
		for(int i=0;i<G;++i)t[i]=0,f[i]=i,us[i]=false;
		for(int u,i=1;i<=n;++i){
			if(t[u=idx(s[i])])continue;
			for(int j=0;j<G;++j){
				if(us[j]||(c!=G-1&&find(j)==find(u)))continue;
				++c,t[u]=j+'a',us[j]=true,f[find(j)]=find(u);break;
			}
		}
		for(int i=1;i<=n;++i)putchar(t[idx(s[i])]);
		putchar('\n');
	}
	return 0;
}