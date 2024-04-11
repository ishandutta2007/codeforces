#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#define long long long
#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)

typedef pair < int , int > Point;
#define cx first
#define cy second
#define scanPoint(a) cin >> a.cx >> a.cy

Point a,b,c;

void init(){
    scanPoint(a);scanPoint(b);scanPoint(c); 
}

void sortPoint(){
    if (a > b) swap(a,b);
    if (b > c) swap(b,c);
    if (a > b) swap(a,b);
    if (b > c) swap(b,c);
}

set < Point > ans;

void printPath(Point x,Point y){
    if (x > y) swap(x,y);
    if (x.cx == y.cx) for (int i=x.cy;i<=y.cy;i++) ans.insert( Point ( x.cx,i ) );
    if (x.cy == y.cy) for (int i=x.cx;i<=y.cx;i++) ans.insert( Point ( i,x.cy ) );
}

int main(){
    init();
    sortPoint();
    printPath ( a , Point(b.cx,a.cy) ); 
    printPath ( b , Point(b.cx,a.cy) );
    int yu = a.cy , yd = b.cy;
    if (yu < yd) swap (yu,yd);
    see(yu);see(yd);see(c.cy);
    if (c.cy >= yd && c.cy <= yu) {
        printPath ( Point(b.cx , c.cy) , c );
    } else {
        if (c.cy > yu){
            printPath ( Point(b.cx , yu) , Point(b.cx , c.cy) );
        }else{
            printPath ( Point(b.cx , yd) , Point(b.cx , c.cy) );
        }
        printPath ( Point( b.cx,c.cy ) , c );
    }
    cout << ans.size() << endl;
    for (set < Point > :: iterator it = ans.begin();it!=ans.end();it++){
        cout << it-> cx << ' ' << it-> cy << endl;
    }
    return 0;
}