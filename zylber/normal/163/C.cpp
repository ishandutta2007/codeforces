#include <set>
#include <map>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)
#define dforn(a,n) for(int a = (n)-1; a >= 0; --a)
#define forsn(a,s,n) for(int a = (s); a < n; ++a)

typedef long long tint;

vector <pair <double,int> > choc;
    int n;
     double p[100010], l, v1, v2;

double tr(double d)
{
    while(d>=2.0*l)
    d-=2.0*l;
    while(d<0.0)
    d+=2.0*l;
    return d;
}



int main(){
#ifdef TESTING
	freopen("test.in", "r", stdin);
#endif
    cin >> n >> l >> v1 >> v2;

    choc.resize(2*n);

    double d=l*v2; d/=(v1+v2);

    forn(i,n)
    {
        double k;
        cin >> k;
        choc[2*i]=make_pair(k,1);
        choc[2*i+1]=make_pair(tr(k+d),-1);
    }
    sort(choc.begin(), choc.end());

    int c=0;
    int s;

    for(s=0; s<2*n && choc[s].first<d; s++)
    if(choc[s].second==1)
    c++;

    forn(i,2*n)
    {
        c+=choc[(i+s)%(2*n)].second;
        p[c]+=tr(-choc[(i+s)%(2*n)].first+choc[(i+s+1)%(2*n)].first+2.0*l)/(2.0*l);
    }

    forn(i,n+1)
    printf("%.9llf\n",p[i]);

}