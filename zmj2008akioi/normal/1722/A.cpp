#include <cstdio>
const int N=1e3;
const char buf[10]="Timur";
int T,n;char s[N];bool vis[N];
bool chk(char *s){
	for(int i=0;i<5;++i)vis[buf[i]]=true;
	for(int i=0;i<5;++i){
		if(!vis[s[i]])return false;
		vis[s[i]]=false;
	}
	return true;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %s",&n,s);
		if(n!=5||!chk(s))puts("No");
		else puts("Yes");
	}
	return 0;
}