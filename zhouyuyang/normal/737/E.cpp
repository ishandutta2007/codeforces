#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;
const int N=500;
int n,m,B,ans;
int co[N],sx[N],sy[N];
int mp[N][N],id[N],fl[N];
bool cmp(int x,int y){
	return sy[x]<sy[y];
}
int mat[N],to[N];
bool Mat[N],vis[N];
bool dfs(int x){
	For(i,1,n+m)
		if (mp[x][i]&&!vis[i]){
			vis[i]=1;
			if (!mat[i]||dfs(mat[i])){
				mat[i]=x; to[x]=i;
				return 1;
			}
		}
	return 0;
} 
struct node{
	int i,j,beg,cnt;
}Ans[5000005];
int ans_top;
const int OUT_SIZE=100000000;
char out[OUT_SIZE];
int out_top;
void write(int x){
	if (!x){
		out[out_top++]='0';
		return;
	}
	static int a[15],top;
	for (top=0;x;a[++top]=x%10,x/=10);
	for (;top;out[out_top++]=a[top--]+'0');
}
void writespace(int x){
	write(x);
	out[out_top++]=' ';
}
void writeln(int x){
	write(x);
	out[out_top++]='\n';
}
int main(){
	scanf("%d%d%d",&n,&m,&B);
	For(i,1,m) scanf("%d",&co[i]),id[i]=i; 
	For(i,1,n){
	    int cnt; scanf("%d",&cnt);
	    while (cnt--){
	        int x,y;
	        scanf("%d%d",&x,&y);
	        mp[i][x]=y; sx[i]+=y; sy[x]+=y;
	    }
	}
	For(i,1,n) ans=max(ans,sx[i]);
	sort(id+1,id+m+1,cmp);
	int p=m; 
	for (;p&&B>=co[id[p]];B-=co[id[p--]]);
	For(i,1,p) ans=max(ans,sy[id[i]]);
	For(i,p+1,m){
		ans=max(ans,(sy[id[i]]+1)/2);
		fl[id[i]]=1; sy[id[i]]=0;
		For(j,1,n){
			int x=id[i],y=x+m,v=mp[j][x];
			mp[j][x]=mp[j][y]=v/2;
			if (v&1)
				if (sy[x]<sy[y]) mp[j][x]++;
				else mp[j][y]++;
			sy[x]+=mp[j][x],sy[y]+=mp[j][y];
		}
	}
	writeln(ans);
	For(i,1,m) write(fl[i]);
	out[out_top++]='\n';
	m*=2;
	For(i,1,n) For(j,1,n){
		mp[i][j+m]=ans-max(sx[i],sy[j+m]);
		sx[i]+=mp[i][j+m];
		sy[j+m]+=mp[i][j+m];
	}
	For(i,1,m) For(j,1,m){
		mp[i+n][j]=ans-max(sx[i+n],sy[j]);
		sx[i+n]+=mp[i+n][j];
		sy[j]+=mp[i+n][j];
	}
	For(i,1,m) For(j,1,n){
		mp[i+n][j+m]=ans-max(sx[i+n],sy[j+m]);
		sx[i+n]+=mp[i+n][j+m];
		sy[j+m]+=mp[i+n][j+m];
	}
	For(i,1,n+m) Mat[i]=1;
	for (int T=0;T<ans;){
		For(i,1,n+m) if (Mat[i]){
			memset(vis,0,sizeof(vis));
			Mat[i]=0,dfs(i);
		}
		int mn=1e9;
		For(i,1,n+m) if (to[i])
			mn=min(mn,mp[i][to[i]]);
		For(i,1,n+m) if (to[i]){
			if (i<=n&&to[i]<=m) Ans[++ans_top]=(node){i,to[i],T,mn};
			if (!(mp[i][to[i]]-=mn)) Mat[i]=1,mat[to[i]]=0,to[i]=0;
		}
		T+=mn;
	}
	writeln(ans_top);
	For(i,1,ans_top){
		writespace(Ans[i].i);
		writespace(Ans[i].j-(Ans[i].j<=m/2?0:m/2));
		writespace(Ans[i].beg);
		writeln(Ans[i].cnt);
	}
	fwrite(out,1,out_top,stdout);
}