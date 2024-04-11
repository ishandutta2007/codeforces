#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
		return positive ? x : -x;
}
const int N=10005;
int nedge,n,m,nextt[N],son[N],ed[N],vis[N],que[N],ans;
int mm[N][4],an[4],dist[3005][3005],mx[N][4];
inline int bfs(int p){
	int l=0,r;
    que[r=1]=p; int zs=0; for(int i=1;i<=n;i++)vis[i]=0; vis[p]=1;
    while(l++<r){
    	int k=que[l];
    	for(int i=1;i<=3;i++)if(!mx[p][i]||dist[p][k]>dist[p][mx[p][i]]){
    		mx[p][i-1]=mx[p][i]; mx[p][i]=k;
		}
    	for(int i=son[k];i;i=nextt[i])if(!vis[ed[i]]){
    		que[++r]=ed[i]; dist[p][ed[i]]=dist[p][k]+1; vis[ed[i]]=1;
		}
	}
	return zs;
}
inline void aedge(int a,int b){
	nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b; 
}
set<int> s;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int s1=read(),s2=read(); 
		aedge(s1,s2); 
	}
	for(int i=1;i<=n;i++)bfs(i);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++)if(!mm[j][k]||dist[i][j]>dist[mm[j][k]][j]){
				mm[j][k-1]=mm[j][k]; mm[j][k]=i;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++)if(i!=j&&j!=mm[i][k]){
				for(int l=1;l<=3;l++){
					if(i!=mx[j][l]&&mm[i][k]!=mx[j][l]){
						if(dist[i][j]&&dist[mm[i][k]][i]&&dist[j][mx[j][l]]&&dist[i][j]+dist[mm[i][k]][i]+dist[j][mx[j][l]]>ans){
							ans=dist[i][j]+dist[mm[i][k]][i]+dist[j][mx[j][l]];
							an[1]=i; an[2]=j; an[0]=mm[i][k]; an[3]=mx[j][l];
						}
					}
				}
			}
		}
	}
	//cout<<dist[3][1]<<" "<<dist[4][1]<<" "<<dist[2][1]<<endl;
	//cout<<mm[1][1]<<" "<<mm[1][2]<<" "<<mm[1][3]<<endl;
	//cout<<dist[2][1]<<" "<<dist[1][8]<<" "<<dist[8][7]<<endl;
	//cout<<dist[an[0]][an[1]]<<" "<<dist[an[1]][an[2]]<<" "<<dist[an[2]][an[3]]<<endl;
	for(int i=0;i<4;i++)cout<<an[i]<<" ";
}