#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[16][65536][16],lenL,lenR;
char L[17],R[17],vis[16][65536][16];
ll dfs(int mx,int p,int len){
//	printf("dfs:[%d,%d,%d]\n",mx,p,len);
	if(len==0)return !!(p&(1<<mx));
	if(vis[mx][p][len])return dp[mx][p][len];
	vis[mx][p][len]=1;
	ll & ans=dp[mx][p][len]; ans=0;
	for(int i=0;i<=15;++i) ans+=dfs(max(mx,i),(p<<4|i)&65535,len-1);
	return ans;
}
int cal(char* L){
	int ans=0;
	for(int i=0;i<16;++i)ans=max(ans,(int)L[i]);
	return ans;
}
int cmp(char* L,char* R){
	for(int i=16;i>=0;--i)if(L[i]!=R[i])return L[i]<R[i];
	return true;
}
void add(char* L,int x){
	for(int i=x;i<=16;++i){
		if((++L[i])<=15)break;
		else L[i]=0;
	}
//	printf("[%d]",L[x]);
}
bool nxt(int i){
	static char a[17];
	memcpy(a,L,sizeof(a));
	return add(a,i),cmp(a,R);
}
void print(char* L){
	int i=15;
	for(;i&&!L[i];--i);
	for(;i>=0;i--)putchar(L[i]>=10?L[i]-10+'a':L[i]+'0');
	putchar(10);
}
int cal2(char* L,int x){
	int ans=0;
	for(int i=15;i>=x;--i)ans=ans<<4|L[i],ans&=65535;
	return ans;
}
ll cal3(char* L){
	ll ans=0;
	for(int i=15;i>=0;--i)ans=ans<<4|L[i];
	return ans;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		ll ans=0,l=0,r=0;
		scanf("%s%s",L,R);
		lenL=strlen(L),lenR=strlen(R);
		reverse(L,L+lenL),reverse(R,R+lenR);
		for(int i=0;i<lenL;i++)L[i]=(L[i]<'a'?L[i]-'0':L[i]-'a'+10);
		for(int i=0;i<lenR;i++)R[i]=(R[i]<'a'?R[i]-'0':R[i]-'a'+10);add(R,0);l=cal3(L),r=cal3(R);
		for(int i=0;l+(1ll<<(i<<2))<=r&&i<=15;i++)while(L[i]&&l+(1ll<<(i<<2))<=r)ans+=dfs(cal(L),cal2(L,i),i)/*,printf("[cal=%d,cal2=%d,i=%d]",cal(L),cal2(L,i),i),print(L)*/,add(L,i),l+=(1ll<<(i<<2));
		for(int i=15;i>=0;i--)while(l+(1ll<<(i<<2))<=r)ans+=dfs(cal(L),cal2(L,i),i)/*,print(L)*/,add(L,i),l+=(1ll<<(i<<2));
		printf("%lld\n",ans);
	}
}