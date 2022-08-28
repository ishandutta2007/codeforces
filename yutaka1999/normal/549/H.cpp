#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <queue>
#define EPS 1e-20
#define DINF 1e20

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll a,b,c,d;

bool ok(double x)
{
	double a1=a-x,a2=a+x;
	double b1=b-x,b2=b+x;
	double c1=c-x,c2=c+x;
	double d1=d-x,d2=d+x;
	double ad1=DINF,ad2=-DINF;
	ad1=min(ad1,a1*d1);
	ad1=min(ad1,a1*d2);
	ad1=min(ad1,a2*d1);
	ad1=min(ad1,a2*d2);
	ad2=max(ad2,a1*d1);
	ad2=max(ad2,a1*d2);
	ad2=max(ad2,a2*d1);
	ad2=max(ad2,a2*d2);
	double bc1=DINF,bc2=-DINF;
	bc1=min(bc1,c1*b1);
	bc1=min(bc1,c1*b2);
	bc1=min(bc1,c2*b1);
	bc1=min(bc1,c2*b2);
	bc2=max(bc2,c1*b1);
	bc2=max(bc2,c1*b2);
	bc2=max(bc2,c2*b1);
	bc2=max(bc2,c2*b2);
	if(ad2+EPS<bc1) return false;
	if(bc2+EPS<ad1) return false;
	return true;
}
int main()
{
	scanf("%I64d %I64d",&a,&b);
	scanf("%I64d %I64d",&c,&d);
	double l=-EPS,r=DINF;
	for(int i=0;i<100000;i++)
	{
		double m=(l+r)/2;
		if(ok(m)) r=m;
		else l=m;
	}
	printf("%.10f\n",r);
}