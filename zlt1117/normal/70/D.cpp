//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const double eps=1e-8;
const int maxn=1e5+5;
inline int sign(db x){return x<eps?(x>-eps?0:-1):1;}
struct Point
{
	db x,y;
	Point(db xx=0,db yy=0){x=xx,y=yy;}
	inline bool operator < (const Point b)const{return sign(x-b.x)==0?y<b.y:x<b.x;}
	inline Point operator + (Point b){return Point(x+b.x,y+b.y);}
	inline Point operator - (Point b){return Point(x-b.x,y-b.y);}
	inline Point operator * (db b){return Point(x*b,y*b);}
	inline db operator * (Point b){return x*b.y-y*b.x;}
};
struct tubao
{
	#define iter set<Point>::iterator
	set<Point>up,down;
	inline bool check_up(Point x)///   
	{
		Point temp=x;temp.y=-1e9;///x 
		iter it=up.lower_bound(temp);
		if(it==up.end())return false;
		iter temp1=it;temp1++;
		if(sign((*it).x-x.x)==0)return x.y<=(*it).y;
		if(it==up.begin())return false;/// 
		iter jt=it;///it  
		--jt;/// 
		///
		Point i=*it,j=*jt;
		return sign((i-j)*(x-j))<=0;/// 
	}
	inline bool check_down(Point x)
	{
		Point temp=x;temp.y=-1e9;
		iter it=down.lower_bound(temp);
		if(it==down.end())return false;
		if(sign((*it).x-x.x)==0)return x.y>=(*it).y;
		if(it==down.begin())return false;
		iter jt=it;
		--jt;
		Point i=*it,j=*jt;
		return sign((i-j)*(x-j))>=0;
	}
	inline void insert_up(Point x)
	{
		if(check_up(x))return ;
		iter temp=up.lower_bound(Point(x.x,-1e9));///() 
		if(temp!=up.end()&&sign((*temp).x-x.x)==0)up.erase(temp);
		up.insert(x);
		iter it=up.find(x);
		iter jt=it;
		if(it!=up.begin())/// 
		{///jtit 
			--jt;
			while(remove_up(jt++))jt--;
		}
		if(++jt!=up.end())///
		{
			while(remove_up(jt--))jt++;	
		} 
	}
	inline void insert_down(Point x)
	{
		if(check_down(x))return ;
		iter temp=down.lower_bound(Point(x.x,-1e9));///() 
		if(temp!=down.end()&&sign((*temp).x-x.x)==0)down.erase(temp);
		down.insert(x);
		iter it=down.find(x);
		iter jt=it;
		if(it!=down.begin())
		{
			--jt;
			while(remove_down(jt++))jt--;
		}
		if(++jt!=down.end())
		{
			while(remove_down(jt--))jt++;
		}
	}
	inline bool remove_up(iter it)/// 
	{
		if(it==up.begin())return false;///
		iter jt=it,kt=it;
		--jt,++kt;///
		if(kt==up.end())return false;///
		Point i=*it,j=*jt,k=*kt;
		if((i-j)*(k-j)>=0)return up.erase(it),true;
		return false; 
	}
	inline bool remove_down(iter it)
	{
		if(it==down.begin())return false;
		iter jt=it,kt=it;
		jt--;kt++;
		if(kt==down.end())return false;
		Point i=*it,j=*jt,k=*kt;
		if((i-j)*(k-j)<=0)return down.erase(it),true;
		return false;
	}
	inline void insert(Point x)
	{
		insert_up(x);
		insert_down(x);
	}
	inline bool query(Point x)
	{
		return check_up(x)&&check_down(x); 
	}
	#undef iter
}tree;
inline void init()
{

}
inline void input()
{

}
inline void solve()
{
	int Q=gi();
	while(Q--)
	{
		int t=gi(),x=gi(),y=gi();
		if(t==1)tree.insert(Point(x,y));
		else printf(tree.query(Point(x,y))?"YES\n":"NO\n");
	}
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}
/*
4
1 3 8
1 0 0
1 0 7
2 0 7

*/