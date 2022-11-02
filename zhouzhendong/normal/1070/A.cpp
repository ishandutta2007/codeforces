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
const int D=510,S=5505;
int d,s;
int dis[D][S],vis[D][S];
struct Node{
	int d,s;
	Node(){}
	Node(int _d,int _s){
		d=_d,s=_s;
	}
}q[D*S];
vector <int> rev[D][S];
string ans="";
int Ha(int x,int y){
	return x*100000+y;
}
int Q[D*S];
int main(){
	d=read(),s=read();
	int head=0,tail=0;
	memset(dis,63,sizeof dis);
	dis[0][0]=0,vis[0][0]=1;
	q[++tail]=Node(0,0);
	while (head<tail){
		Node now=q[++head];
		for (int i=(s==0);i<10;i++){
			int _d=(now.d*10+i)%d;
			int _s=now.s+i;
			if (_s>s)
				continue;
			if (vis[_d][_s]){
				if (dis[_d][_s]==dis[now.d][now.s]+1)
					rev[_d][_s].push_back(Ha(now.d,now.s));
				continue;
			}
			rev[_d][_s].push_back(Ha(now.d,now.s));
			vis[_d][_s]=1;
			dis[_d][_s]=dis[now.d][now.s]+1;
			q[++tail]=Node(_d,_s);
		}
	}
	if (!vis[0][s])
		return puts("-1"),0;
	#define tag vis
	memset(tag,0,sizeof tag);
	head=tail=0;
	Q[++tail]=Ha(0,s);
	tag[0][s]=1;
	while (head<tail){
		int now=Q[++head];
		int nowd=dis[now/100000][now%100000];
		for (auto y : rev[now/100000][now%100000]){
			if (tag[y/100000][y%100000]||dis[y/100000][y%100000]!=nowd-1)
				continue;
			tag[y/100000][y%100000]=1;
			Q[++tail]=y;
		}
	}
	Node now=Node(0,0);
	while (now.d!=0||now.s!=s){
		for (int i=(now.s==0);i<10;i++){
			int _d=(now.d*10+i)%d;
			int _s=now.s+i;
			if (_s>s)
				continue;
			if (tag[_d][_s]&&dis[_d][_s]==dis[now.d][now.s]+1){
				ans+='0'+i;
				now=Node(_d,_s);
				break;
			}
		}
	}
	cout << ans;
	return 0;
}