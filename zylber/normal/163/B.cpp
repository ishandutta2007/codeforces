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

struct triple
{
    tint a;
    tint b;
    tint c;
};

vector <triple> lemmings;

bool compa(triple a, triple b)
{
    if(a.a!=b.a)
    return a.a<b.a;

    if(a.b!=b.b)
    return a.b<b.b;

    return a.c<b.c;
}

int main()
{
#ifdef TESTING
	freopen("test.in", "r", stdin);
#endif
    long long n, k, h;
    cin >> n >> k >> h;

    lemmings.resize(n);

    forn(i,n)
    {
        cin >> lemmings[i].a;
        lemmings[i].c=i;
    }

    forn(i,n)
        cin >> lemmings[i].b;

    sort(lemmings.begin(),lemmings.end(), compa);

    double top=20000000000.0, bot=0.0, mid=(top+bot)/2;

    forn(i,100)
    {
        double t=1;

        forn(i,n)
        {
            double gas=lemmings[i].b;
            gas*=mid;
            if(t<gas)
            t+=1.0;
        }

        if(t+0.5>k+1)
        top=mid;
        else
        bot=mid;

        mid=(top+bot)/2;
    }

    int asd[k];
    double t=1; int wer=0;
    forn(i,n)
    {double gas=lemmings[i].b; gas*=mid;
    if(t<gas+0.0000000001 && wer<k)
    {
        t+=1.0;
        asd[wer]=lemmings[i].c;
        wer++;
    }
    }
    forn(i,k-1)
    cout << asd[i]+1 << " ";
    cout << asd[k-1]+1 << endl;
}