#include<bits/stdc++.h>
using namespace std;
const int WA_size=25000;
struct WA_Automaton{
	int ch[WA_size][10],sz;
	int fail[WA_size],q[WA_size];
	int ed[WA_size];
	WA_Automaton(){
		sz=1;
	}
	void insert(char *S,char *T){
		int x=1;
		for (;S!=T;S++){
			int tmp=(*S)-'0';
			if (!ch[x][tmp])
				ch[x][tmp]=++sz;
			x=ch[x][tmp];
		}
		ed[x]=1;
	}
	void build(){
		int h=0,t=q[1]=1;
		while (h!=t){
			int x=q[++h];
			for (int i=0;i<10;i++)
				if (!ch[x][i])
					ch[x][i]=(x==1?1:ch[fail[x]][i]);
				else{
					q[++t]=ch[x][i];
					fail[ch[x][i]]=(x==1?1:ch[fail[x]][i]);
				}
		}
	}
}ACM;
#define mo 1000000007
char a[55],b[55],s[1005];
int n,m,d,way[55],p[55];
int f[55][WA_size];
int dfs(int dep,int at,bool lim){
	if (ACM.ed[at])
		return lim?way[dep]:p[dep];
	if (dep>m) return 0;
	if (!lim&&f[dep][at]!=-1)
		return f[dep][at];
	long long ans=0;
	for (int i=0;i<=(lim?s[dep]:9);i++)
		ans+=dfs(dep+1,ACM.ch[at][i],lim&(i==s[dep]));
	ans%=mo;
	if (!lim) f[dep][at]=ans;
	return ans;
}
int calc(char *a){
	for (int i=1;i<=m;i++) s[i]=a[i]-'0';
	way[m+1]=p[m+1]=1;
	for (int i=m;i;i--){
		p[i]=1ll*p[i+1]*10%mo;
		way[i]=(1ll*s[i]*p[i+1]+way[i+1])%mo;
	}
	memset(f,-1,sizeof(f));
	return dfs(1,1,1);
}
int main(){
	scanf("%s%s%s",s+1,a+1,b+1);
	n=strlen(s+1),m=strlen(a+1),d=m/2;
	for (int i=1;i+d-1<=n;i++)
		ACM.insert(s+i,s+i+d);
	ACM.build(); a[m]--;
	for (int i=m;a[i]=='0'-1;i++)
		a[i]='9',a[i-1]--;
	printf("%d\n",(calc(b)+mo-calc(a))%mo);
}