#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2005;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x*f;
}
int n,m,r,c,x,y;
char g[N][N];
int vis[N][N],d[N][N];
int a[N*N],b[N*N],head,tail;
void push(int x,int y){
	vis[x][y]=1;
	tail++;
	a[tail]=x;
	b[tail]=y;
}
void ins(int x,int y){
	push(x,y);
	for (int i=x-1;i>0&&g[i][y]!='*';i--){
		d[i][y]=d[x][y];
		push(i,y);
	}
	for (int i=x+1;i<=n&&g[i][y]!='*';i++){
		d[i][y]=d[x][y];
		push(i,y);
	}
}
void pop(){
	head++;
}
int main(){
	n=read(),m=read();
	r=read(),c=read();
	x=read(),y=read();
	for (int i=1;i<=n;i++)
		scanf("%s",g[i]+1);
	head=tail=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			d[i][j]=1<<30;
	d[r][c]=0;
	ins(r,c);
	while (head<tail){
		pop();
		int sx=a[head],sy=b[head];
		if (sy>1&&g[sx][sy-1]!='*'&&!vis[sx][sy-1]){
			d[sx][sy-1]=d[sx][sy]+1;
			ins(sx,sy-1);
		}
		if (sy<m&&g[sx][sy+1]!='*'&&!vis[sx][sy+1]){
			d[sx][sy+1]=d[sx][sy]+1;
			ins(sx,sy+1);
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (d[i][j]>(1<<29))
				continue;
			int ax=(d[i][j]+c-j)/2;
			int ay=(d[i][j]-c+j)/2;
			if (ax<=x&&ay<=y)
				ans++;
		}
	cout << ans;
	return 0;
}