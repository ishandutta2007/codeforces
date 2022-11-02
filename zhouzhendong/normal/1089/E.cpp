#include <bits/stdc++.h>
#define y1 __zzd001
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=0,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?x:-x;
}
const int N=100;
int n;
int vis[N][N];
int px[N],py[N],_n,t;
void put(int x,int y){
	putchar(' ');
	putchar('a'+x-1);
	putchar('1'+y-1);
	t++;
	px[t]=x,py[t]=y;
}
int check(){
	memset(vis,0,sizeof vis);
	if (t!=_n)
		return 1;
	vis[1][1]=1;
	int x=1,y=1;
	for (int i=1;i<=t;i++){
		if (vis[px[i]][py[i]])
			return 2;
		vis[px[i]][py[i]]=1;
		if (x!=px[i]&&y!=py[i])
			return 3;
		x=px[i],y=py[i];
	}
	return 0;
}
int main(){
	_n=n=read();
	memset(vis,0,sizeof vis);
	for (int i=1;i<=8;i++)
		vis[0][i]=vis[0][i]=vis[i][0]=vis[i][9]=1;
	vis[1][1]=1;
	cout << "a1";
	int x=1,y=1;
	while (n>2&&x<=6){
		if (!vis[x][y+1])
			y++;
		else if (!vis[x][y-1])
			y--;
		else
			x++;
		vis[x][y]=1;
		put(x,y);
		n--;
	}
	if (n==2){
		if (y==8)
			x++;
		else
			x=8;
		put(x,y);
		if (y!=8)
			y=8;
		else
			x=8;
		put(x,y);
	}
	else {
		if (n<=8){
			x++,n--,put(x,y);
			while (n>1)
				y++,put(x,y),n--;
			y=8;
			put(x,y);
		}
		else {
			y=8,n--,put(x,y);
			for (int i=1;i<=6;i++)
				y--,n--,put(x,y);
			x++,n--,put(x,y);
			if (n==1)
				y=8,put(x,y);
			else {
				y=1,put(x,y),n--;
				for (int i=8-n+1;i<=8;i++)
					y=i,put(x,y);
			}
		}
	}
//	cout << "\nres = " << check();
	return 0;
}