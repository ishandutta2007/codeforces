#include <bits/stdc++.h>
using namespace std;
const int N=105,M=N*N;
vector <int> e[N];
int n=26,m;
int q[N],head,tail,in[N];
char s[N][N];
int main(){
	for (int i=0;i<n;i++)
		e[i].clear();
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
		scanf("%s",s[i]);
	for (int i=1;i<m;i++){
		int k=0,a=strlen(s[i]),b=strlen(s[i+1]);
		while (k<min(a,b)&&s[i][k]==s[i+1][k])
			k++;
		if (k<min(a,b))
			e[s[i][k]-'a'].push_back(s[i+1][k]-'a'),in[s[i+1][k]-'a']++;
		else if (a>b){
			puts("Impossible");
			return 0;
		}
	}
	head=tail=0;
	for (int i=0;i<n;i++)
		if (in[i]==0)
			q[++tail]=i;
	while (head<tail){
		int x=q[++head],y;
		for (int i=0;i<e[x].size();i++){
			y=e[x][i];
			in[y]--;
			if (in[y]==0)
				q[++tail]=y;
		}
	}
	if (tail!=n)
		puts("Impossible");
	else
		for (int i=1;i<=tail;i++)
			printf("%c",'a'+q[i]);
	return 0;
}