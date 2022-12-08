#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define forn(a,n) for(int a = 0; a<n; ++a)

long long h[100500];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {  
        cin >> h[i];
    }
    
    int m;
    cin >> m;
    long long alt=h[0];
    for(int i=0; i<m; i++)
    {
        long long he, w;
        cin >> w >> he;
        alt=max(alt, h[w-1]);
        cout << alt << endl;
        alt+=he;
    }
}