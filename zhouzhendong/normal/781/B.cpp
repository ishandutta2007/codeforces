#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=2005;
int n;
vector <int> e[N];
int Ha[N],hs=0;
char s1[N][25],s2[N][25];
int get1(int i){
	return ((int)s1[i][0]<<16)|((int)s1[i][1]<<8)|((int)s1[i][2]);
}
int get2(int i){
	return ((int)s1[i][0]<<16)|((int)s1[i][1]<<8)|((int)s2[i][0]);
}
int vis[N],Match[N],res[N];
int cnt[3][N];
bool dfs(int x){
	for (auto y : e[x])
		if (!vis[y]){
			vis[y]=1;
			if (!Match[y]||dfs(Match[y])){
				Match[y]=x;
				return 1;
			}
		}
	return 0;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		scanf("%s%s",s1[i],s2[i]);
		Ha[++hs]=get1(i);
		Ha[++hs]=get2(i);
	}
	sort(Ha+1,Ha+hs+1);
	hs=unique(Ha+1,Ha+hs+1)-Ha-1;
	for (int i=1;i<=n;i++){
		cnt[1][lower_bound(Ha+1,Ha+hs+1,get1(i))-Ha]++;
		cnt[2][lower_bound(Ha+1,Ha+hs+1,get2(i))-Ha]++;
	}
	for (int i=1;i<=n;i++){
		int v1=lower_bound(Ha+1,Ha+hs+1,get1(i))-Ha;
		int v2=lower_bound(Ha+1,Ha+hs+1,get2(i))-Ha;
		if (cnt[1][v1]==1)
			e[i].push_back(v1);
		if (cnt[2][v2]==1)
			e[i].push_back(v2);
	}
	for (int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		if (!dfs(i))
			return puts("NO"),0;
	}
	puts("YES");
	for (int i=1;i<=hs;i++)
		res[Match[i]]=Ha[i];
	for (int i=1;i<=n;i++)
		printf("%c%c%c\n",(char)(res[i]>>16&255),(char)(res[i]>>8&255),(char)(res[i]&255));
	return 0;
}