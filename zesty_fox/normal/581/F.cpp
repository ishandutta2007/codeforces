#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,head[5005],tot,f[5005][5005][2];
int leaf,rt,siz[5005],l[5005],g[5005][2];
const int INF=0x3f3f3f3f;
struct Edge{
	int to,nxt;
}e[100005];
void addedge(int x,int y){
	e[++tot].to=y;
	e[tot].nxt=head[x];
	head[x]=tot;
}

void dfs1(int x,int fa){
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        dfs1(y,x);
        l[x]=1;
    }
    if(!l[x]) leaf++;
}

void dfs(int x,int fa){
	if(!l[x]) f[x][0][0]=f[x][1][1]=0,siz[x]=1;
	else{
        bool flg=0;
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(y==fa) continue;
            dfs(y,x);
            if(!flg){
                for(int j=0;j<=siz[y];j++){
                    f[x][j][0]=min(f[y][j][0],f[y][j][1]+1);
                    f[x][j][1]=min(f[y][j][0]+1,f[y][j][1]);
                }
                flg=1;
            }
            else{
                for(int j=0;j<=min(siz[x],leaf/2);j++)
				    for(int k=0;k<2;k++) g[j][k]=f[x][j][k],f[x][j][k]=INF;
                for(int j=0;j<=min(siz[x],leaf/2);j++){
                    for(int k=0;k<=min(siz[y],leaf/2-j);k++){
                        f[x][j+k][0]=min(f[x][j+k][0],\
                                     g[j][0]+min(\
                                     f[y][k][0],f[y][k][1]+1));
                        f[x][j+k][1]=min(f[x][j+k][1],\
                                     g[j][1]+min(\
                                     f[y][k][1],f[y][k][0]+1));
                    }
                }
            }
            siz[x]+=siz[y];
        }
    }
}

int main(){
    memset(f,0x3f,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=head[i];j;j=e[j].nxt) cnt++;
		if(cnt>1) {rt=i;break;}
	}
    dfs1(rt,0);dfs(rt,0);
	cout<<min(f[rt][leaf/2][0],f[rt][leaf/2][1])<<endl;
	return 0;
}