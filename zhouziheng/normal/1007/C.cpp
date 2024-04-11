#include<cstdio>
#include<algorithm>
#include<deque>

using namespace std;

long long n=0;
int calc(long long x,long long y)
{
	printf("%lld %lld\n",n-x+1,n-y+1);fflush(stdout);
	int a=0;scanf("%d",&a);return a;
}

__int128 dv(__int128 a,__int128 b)
{
	if(a%b==0)return a/b;return a/b+1;
}

struct pnt
{
	__int128 x,y;pnt(__int128 _x=0,__int128 _y=0):x(_x),y(_y){}
};
bool operator==(pnt A,pnt B){return A.x==B.x&&A.y==B.y;}
bool operator!=(pnt A,pnt B){return A.x!=B.x||A.y!=B.y;}
deque<pnt> P;

int main()
{
	scanf("%lld",&n);
	__int128 S=(__int128)n*n;
	P.push_back(pnt(1,n));P.push_back(pnt(n,1));
	while(1)
	{
		S=P.back().x-P[0].x+1;for(int i=0;i<P.size()-1;i++)S+=(P.back().x-P[i].x+1)*(P[i].y-P[i+1].y);
		__int128 T=S%3==0?S/3:S/3+1;
		__int128 x=0,y=0;
		//for(int i=0;i<P.size();i++)printf("%lld %lld\n",P[i].x,P[i].y);
		if(P[0].y-P.back().y+1>=T)x=P.back().x;
		else
		{
			__int128 X=P[0].y-P.back().y+1;
			for(int i=P.size()-2;i>=0;i--)
			{
				if(X+(P[0].y-P[i+1].y+1)*(P[i+1].x-P[i].x)>=T)
				{
					x=P[i+1].x-dv(T-X,(P[0].y-P[i+1].y+1));break;
				}
				X+=(P[0].y-P[i+1].y+1)*(P[i+1].x-P[i].x);
			}
		}
		if(P.back().x-P[0].x+1>=T)y=P[0].y;
		else
		{
			__int128 X=P.back().x-P[0].x+1;
			for(int i=1;i<P.size();i++)
			{
				if(X+(P.back().x-P[i-1].x+1)*(P[i-1].y-P[i].y)>=T)
				{
					y=P[i-1].y-dv(T-X,P.back().x-P[i-1].x+1);break;
				}
				X+=(P.back().x-P[i-1].x+1)*(P[i-1].y-P[i].y);
			}
		}
		int c=calc(x,y);if(c==0)break;
		if(c==1)
		{
			long long fy=0;while(P.back().x>=x){fy=P.back().y;P.pop_back();}
			if(P.back()!=pnt(x-1,fy))P.push_back(pnt(x-1,fy));
		}
		else if(c==2)
		{
			long long fx=0;while(P[0].y>=y){fx=P[0].x;P.pop_front();}
			if(P[0]!=pnt(fx,y-1))P.push_front(pnt(fx,y-1));
		}
		else
		{
			__int128 a=P[0].y,b=P.back().x;
			int l=0;while(l<P.size()&&P[l].y>y)l++;
			int r=P.size()-1;while(r>=0&&P[r].x>x)r--;
			//printf("%d %d\n",l,r);
			int len=r-l+1;if(len>0){for(int i=r+1;i<P.size();i++)P[i-len]=P[i];for(int i=1;i<=len;i++)P.pop_back();}
			//puts("OK");
			P.push_back(pnt(0,0));for(int i=P.size()-2;i>=l;i--)P[i+1]=P[i];//puts("OK");
			//printf("%d %d\n",l,P.size());
			if(l==P.size()-1)P[l]=pnt(x,y+1);else if(l==0)P[l]=pnt(x+1,y);else P[l]=pnt(x+1,y+1);
			while(P.size()>=2&&P[0]==P[1])P.pop_front();
			while(P.size()>=2&&P[P.size()-1]==P[P.size()-2])P.pop_back();
		}
	}
}