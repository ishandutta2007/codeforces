#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define SIZE 100005
#define DINF 1e17
#define EPS 1e-10

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair <int,int> P;

P pos[SIZE];
P A,B,S;

ld dist(P p,P q)
{
	return sqrt((ll) (p.first-q.first)*(ll) (p.first-q.first)+(ll) (p.second-q.second)*(ll) (p.second-q.second));
}
ld ABS(ld d)
{
	return max(d,-d);
}
P get_input()
{
	int a,b;
	scanf("%d %d",&a,&b);
	return P(a,b);
}
int main()
{
	A=get_input();
	B=get_input();
	S=get_input();
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) pos[i]=get_input();
	ld sum=0.0;
	ld a1=DINF,a2=DINF;
	ld b1=DINF,b2=DINF;
	for(int i=0;i<n;i++) sum+=dist(pos[i],S);
	sum*=2.0;
	ld ans=DINF;
	for(int i=0;i<n;i++)
	{
		ld pa=dist(pos[i],A)-dist(pos[i],S);
		ld pb=dist(pos[i],B)-dist(pos[i],S);
		ans=min(ans,sum+pa);
		ans=min(ans,sum+pb);
		if(a1>pa+EPS) swap(a1,pa);
		if(a2>pa+EPS) swap(a2,pa);
		if(b1>pb+EPS) swap(b1,pb);
		if(b2>pb+EPS) swap(b2,pb);
	}
	//printf("%f %f : %f %f\n",a1,a2,b1,b2);
	for(int i=0;i<n;i++)
	{
		ld pa=dist(pos[i],A)-dist(pos[i],S);
		ld pb=dist(pos[i],B)-dist(pos[i],S);
		//printf("%f : %f %f\n",sum,pa,pb);
		if(ABS(pa-a1)<EPS) ans=min(ans,sum+pb+a2);
		else ans=min(ans,sum+pb+a1);
		if(ABS(pb-b1)<EPS) ans=min(ans,sum+pa+b2);
		else ans=min(ans,sum+pa+b1);
	}
	printf("%.10f\n",(double) ans);
	return 0;
}