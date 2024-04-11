#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int INF=1e9;
struct Point{
	int x,y;
	Point(){}
	Point(int _x,int _y){
		x=_x,y=_y;
	}
	Point rot(){
		return Point(-y,x);
	}
	void rots(int x){
		while (x--)
			(*this)=(*this).rot();
	}
}p[4];
int id[4];
typedef pair <int,vector <Point> > pv;
pv ans;
pv solve(int base,Point d,int flag){
//		For(i,0,3) printf("(%d,%d,%d) ",id[i],p[id[i]].x,p[id[i]].y);puts("");
//		printf("Solve(%d,(%d,%d),%d)\n",base,d.x,d.y,flag);
	pv res;
	res.fi=INF;
	int a=-1;
	if (flag==0)
		a=p[id[(base+2)%4]].x-d.x;
	else
		a=p[id[(base+2)%4]].y-d.y;
	if (a<=0)
		return res;
	res.se.resize(4);
	int mx=0;
	For(i,0,3){
		Point t=d;
		if (i&2)
			t.x+=a;
		if ((i>>1)^(i&1))
			t.y+=a;
		int ID=id[(base+i)%4];
		if (p[ID].x!=t.x&&p[ID].y!=t.y)
			return res;
		mx=max(mx,abs(t.x-p[ID].x)+abs(t.y-p[ID].y));
		res.se[ID]=t;
	}
	res.fi=mx;
//		cout<<res.fi<<endl;
//		if (res.fi!=-1)
//			for (auto i : res.se)
//				cout<<i.x<<" "<<i.y<<endl;
	return res;
}
pv solve2(int base){
	pv res;
	res.fi=INF;
	if (p[id[(base+0)%4]].x!=p[id[(base+1)%4]].x)
		return res;
	if (p[id[(base+2)%4]].x!=p[id[(base+3)%4]].x)
		return res;
	int a=p[id[(base+2)%4]].x-p[id[(base+0)%4]].x;
	if (a<=0)
		return res;
	int L=0,R=2e8,mid,ans=R;
	int py[4];
	For(i,0,3)
		py[i]=p[id[(base+i)%4]].y;
	while (L<=R){
		mid=(L+R)>>1;
		int flag=1;
		if (py[1]-py[0]-mid*2>a||py[2]-py[3]-mid*2>a)
			flag=0;
		else {
			int a0=max(py[0]-mid,py[1]-mid-a),a1=min(py[0]+mid,py[1]+mid-a);
			int b0=max(py[3]-mid,py[2]-mid-a),b1=min(py[3]+mid,py[2]+mid-a);
			if (max(a0,b0)>min(a1,b1))
				flag=0;
		}
		if (flag)
			R=mid-1,ans=mid;
		else
			L=mid+1;
	}
	mid=ans;
	int a0=max(py[0]-mid,py[1]-mid-a),a1=min(py[0]+mid,py[1]+mid-a);
	int b0=max(py[3]-mid,py[2]-mid-a),b1=min(py[3]+mid,py[2]+mid-a);
	res.fi=ans;
	res.se.resize(4);
	int y=max(a0,b0);
	For(i,0,3){
		int ID=id[(base+i)%4];
		Point now=Point(p[ID].x,y);
		if ((i>>1)^(i&1))
			now.y+=a;
		res.se[ID]=now;
	}
	return res;
}
void Solve(){
	For(i,0,3)
		p[i].x=read(),p[i].y=read(),id[i]=i;
	ans.fi=INF,ans.se.clear();
	do {
		For(i,0,3){
			For(f,0,1){
				{
					pv tmp=solve(i,Point(p[id[(i+1)%4]].x,p[id[i]].y),f);
					for (auto &j : tmp.se)
						j.rots(4-i);
					if (tmp.fi<ans.fi)
						ans=tmp;
				}
				{
					pv tmp=solve(i,Point(p[id[i]].x,p[id[(i+3)%4]].y),f);
					for (auto &j : tmp.se)
						j.rots(4-i);
					if (tmp.fi<ans.fi)
						ans=tmp;
				}
			}
			{
				pv tmp=solve2(i);
				for (auto &j : tmp.se)
					j.rots(4-i);
				if (tmp.fi<ans.fi)
					ans=tmp;
			}
			For(j,0,3)
				p[j].rots(1);
		}
	} while (next_permutation(id,id+4));
	if (ans.fi==INF)
		ans.fi=-1;
	cout<<ans.fi<<endl;
	if (ans.fi!=-1)
		for (auto i : ans.se)
			cout<<i.x<<" "<<i.y<<endl;
}
int main(){
	int T=read();
	while (T--)
		Solve();
	return 0;
}