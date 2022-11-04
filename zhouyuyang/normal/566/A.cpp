#include<bits/stdc++.h>
#define N 800005
using namespace std;
vector<int> vec[2][N];
int ch[N][26],dep[N];
bool vis0[N],vis1[N];
int n,size=1,ok[N];
long long ans;
char s[N];
void insert(int fl,int id){
	scanf("%s",s+1);
	int len=strlen(s+1);
	int x=1;
	for (int i=1;i<=len;i++){
		vec[fl][x].push_back(id);
		if (!ch[x][s[i]-'a']){
			ch[x][s[i]-'a']=++size;
			dep[size]=dep[x]+1;
		}
		x=ch[x][s[i]-'a'];
	}
	vec[fl][x].push_back(id);
}
void dfs(int x){
	for (int i=0;i<26;i++)
		if (ch[x][i])
			dfs(ch[x][i]);
	int sz1=vec[0][x].size();
	int sz2=vec[1][x].size();
	int tp1=0,tp2=0;
	for (;;){
		for (;tp1<sz1&&vis0[vec[0][x][tp1]];tp1++);
		for (;tp2<sz2&&vis1[vec[1][x][tp2]];tp2++);
		if (tp1==sz1||tp2==sz2) break;
		vis0[vec[0][x][tp1]]=1;
		vis1[vec[1][x][tp2]]=1;
		ok[vec[0][x][tp1]]=vec[1][x][tp2];
		ans+=dep[x];
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++)
		insert(i>n,(i-1)%n+1);
	dfs(1);
	printf("%I64d\n",ans);
	for (int i=1;i<=n;i++)
		printf("%d %d\n",i,ok[i]);
}