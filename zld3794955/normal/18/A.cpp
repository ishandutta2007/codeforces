#include<iostream>
#include<cstdio>
using namespace std;
struct point
{	
	int x,y;
	point(): x(0),y(0) {}
	point(const int &x_,const int &y_): x(x_),y(y_) {}
	inline void read_in()
	{	
		scanf("%d%d",&x,&y);
	}
}a,b,c;
struct vec
{	
	int x,y;
	vec(): x(0),y(0) {}
	vec(point start,point end): x(end.x-start.x),y(end.y-start.y) {}
};
inline int operator*(vec v1,vec v2)
{	
	return v1.x*v2.x+v1.y*v2.y;
}
inline vec get_vec(point start,point end)
{	
	return vec(start,end);
}
inline bool operator==(point p1,point p2)
{	
	return p1.x==p2.x && p1.y==p2.y;
}
const int x[5]={0,0,1,0,-1},y[5]={0,1,0,-1,0};
inline bool right(point p1,point p2,point p3)
{	
	if(p1==p2 || p2==p3 || p3==p1)
		return false;
	if(get_vec(p1,p2)*get_vec(p1,p3)==0)
		return true;
	if(get_vec(p2,p1)*get_vec(p2,p3)==0)
		return true;
	if(get_vec(p3,p1)*get_vec(p3,p2)==0)
		return true;
	return false;
}
int main()
{	
	a.read_in();
	b.read_in();
	c.read_in();
	if(right(a,b,c))
		printf("RIGHT\n");
	else
	{	
		bool f=false;
		for(int i=1;i<=4;++i)
		{	
			if(right(point(a.x+x[i],a.y+y[i]),b,c))
			{	
				printf("ALMOST\n");
				f=true;
				break;
			}
			if(right(a,point(b.x+x[i],b.y+y[i]),c))
			{	
				printf("ALMOST\n");
				f=true;
				break;
			}
			if(right(a,b,point(c.x+x[i],c.y+y[i])))
			{	
				printf("ALMOST\n");
				f=true;
				break;
			}
		}
		if(!f)
		{	
			printf("NEITHER\n");
		}
	}
	return 0;
}