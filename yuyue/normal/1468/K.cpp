#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);
}
map<pair<int,int>,bool>v;
char S[5010];
struct wzy{
	int dx,dy;
}co[5010];

int main(){
	int T;read(T);
	while(T--){
		scanf("%s",S+1);int n=strlen(S+1);
		int ansx=0;int ansy=0;
		rep(i,1,n){co[i].dx=-(S[i]=='L')+(S[i]=='R');co[i].dy=-(S[i]=='D')+(S[i]=='U');}
		
		v.clear();
		int sx=0;int sy=0;v[make_pair(sx,sy)]=1;
		rep(i,1,n){
			sx+=co[i].dx;sy+=co[i].dy;
			if(v.find(make_pair(sx,sy))!=v.end())continue;
			int rx=sx-co[i].dx;int ry=sy-co[i].dy;
			rep(j,i+1,n){
				if(rx+co[j].dx==sx&&ry+co[j].dy==sy)continue;
				rx+=co[j].dx;ry+=co[j].dy;
			}
			if(!rx&&!ry){ansx=sx;ansy=sy;break;}
			v[make_pair(sx,sy)]=1;
		}
		write(ansx);putchar(' ');write(ansy);putchar('\n');
	}
	return 0;
}
/*
4
L
RUUDL
LLUU
DDDUUUUU
-1 0
1 2
0 0
0 1
*/