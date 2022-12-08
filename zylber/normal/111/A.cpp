#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    long long n, x, y, g;
    cin >> n >> x >> y;
    int can=1;
    if(n>y) can=0; else
    {
        g=y-n+1;
        if(g*g+n-1<x) can=0;
    }
    
    if(can)
    {
        cout << g << endl;
        for(int i=1; i<n; i++) cout << 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}