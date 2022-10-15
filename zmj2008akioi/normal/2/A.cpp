#include <cstdio>
#include <cstdlib>
#include <cstring>
#define idx(c) ((c)-'a')
#define gg() {printf("%s",name[round]);exit(0);}
int n,u,rec,cnt,pos,least,round,pointer,det[1010],val[32010],tr[32010][26];
char name[1010][40];
bool vis[1010];
inline void select(char *s,int d){
	pos=pointer=0;
	do{
		if(!tr[pos][idx(s[pointer])])tr[pos][idx(s[pointer])]=++cnt;
		pos=tr[pos][idx(s[pointer])];
	}while(s[++pointer]);
	val[pos]+=d;
	if(u==1&&val[pos]>=rec&&vis[pos])gg();
}
void dfs(int pos){
	if(val[pos]>rec)rec=val[pos],memset(vis,0,sizeof(vis)),vis[pos]=true;
	else if(val[pos]==rec)vis[pos]=true;
	for(register int i=0;i<26;++i)if(tr[pos][i])dfs(tr[pos][i]);
}
int main(){
	scanf("%d",&n);
	for(round=0;round<n;++round){
		scanf("%s %d",name[round],&det[round]);
		select(name[round],det[round]);
	}
	dfs(0),u=1;
	memset(val,0,sizeof(val));
	for(round=0;round<n;++round)select(name[round],det[round]);
	return 0;
}