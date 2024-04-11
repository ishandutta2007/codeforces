#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <stack>
#include <cmath>

using namespace std;
typedef long long int ll;
typedef pair <double,double> P;

double dist(P p,P q)
{
	return sqrt((double) (p.first-q.first)*(double) (p.first-q.first)+(double) (p.second-q.second)*(double) (p.second-q.second));
}
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int x1,y1;
	scanf("%d %d",&x1,&y1);
	int x2,y2;
	scanf("%d %d",&x2,&y2);
	if(x1==x2)
	{
		printf("%d\n",abs(y1-y2));
	}
	else if(y1==y2)
	{
		printf("%d\n",abs(x1-x2));
	}
	else
	{
		double d=(double) abs(x1-x2)+(double) abs(y1-y2);
		if(a!=0&&b!=0)
		{
			double s=-((double) a*(double) x1+c)/(double) b;
			double t=-((double) b*(double) y2+c)/(double) a;
			double sum=dist(P(x1,y1),P(x1,s))+dist(P(x1,s),P(t,y2))+dist(P(t,y2),P(x2,y2));
			d=min(d,sum);
			s=-((double) a*(double) x2+c)/(double) b;
			t=-((double) b*(double) y1+c)/(double) a;
			sum=dist(P(x2,y2),P(x2,s))+dist(P(x2,s),P(t,y1))+dist(P(t,y1),P(x1,y1));
			d=min(d,sum);
			s=-((double) a*(double) x1+c)/(double) b;
			t=-((double) a*(double) x2+c)/(double) b;
			sum=dist(P(x1,y1),P(x1,s))+dist(P(x1,s),P(x2,t))+dist(P(x2,t),P(x2,y2));
			d=min(d,sum);
			s=-((double) b*(double) y1+c)/(double) a;
			t=-((double) b*(double) y2+c)/(double) a;
			sum=dist(P(x1,y1),P(s,y1))+dist(P(s,y1),P(t,y2))+dist(P(t,y2),P(x2,y2));
			d=min(d,sum);
		}
		printf("%.10f\n",d);
	}
	return 0;
}