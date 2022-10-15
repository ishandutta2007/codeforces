#include <cstdio>
#include <algorithm>
const int M=510;
int n,m,ans,a[M];
char s[M];
struct unset{
	int id,val;
	unset(){};
	unset(int id,int val):id(id),val(val){};
	inline bool operator<(const unset &nxt)const{return val>nxt.val;}
}urr[M];
int query(){
	int res;
	printf("? %s\n",s+1),fflush(stdout);
	scanf("%d",&res);return res;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i)s[i]='0';
	for(int i=1;i<=m;++i)s[i]='1',a[i]=query(),s[i]='0',urr[i]=unset(i,a[i]);
	for(int i=1;i<=m;++i)s[i]='1';
	int lst=query();std::sort(urr+1,urr+m+1);
	for(int x,nw,i=1;i<=m;++i){
		x=urr[i].id,s[x]='0',nw=i==m?0:query();
		if(lst-nw==a[x])ans+=a[x];lst=nw;
	}
	printf("! %d\n",ans),fflush(stdout);
	return 0;
}