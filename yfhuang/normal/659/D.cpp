//
//  main.cpp
//  D
//
//  Created by  on 16/3/31.
//  Copyright  2016 . All rights reserved.
//
//
//  main.cpp
//  M
//
//  Created by  on 16/3/29.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cmath>
using namespace std;

const int maxn = 1000 + 4;
double INF = 1e18 + 7;

int n;

struct Point{
    int x, y;
    Point(int x = 0, int y = 0):x(x), y(y){}
    bool operator < (const Point & rhs) const{
        return x < rhs.x;
    }
}p[maxn];


typedef Point Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y);}
Vector operator - (Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y);}

long long Cross(Vector A,Vector B){
    return (long long)A.x * B.y - (long long)A.y * B.x;
}

double dis(Point a,Point b){
    return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + 1.0 * (a.y - b.y) * (a.y - b.y));
}

int dir[maxn];



int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i = 1; i <= n + 1; i++){
        scanf("%d%d",&p[i].x, &p[i].y);
    }
    for(int i = 1;i<=n;i++){
        if(p[i].x==p[i+1].x&&p[i].y>p[i+1].y) dir[i] = 4;
        else if(p[i].x==p[i+1].x&&p[i].y<p[i+1].y) dir[i]=2;
        else if(p[i].x<p[i+1].x&&p[i].y==p[i+1].y) dir[i]=3;
        else if(p[i].x >p[i+1].x&&p[i].y==p[i+1].y) dir[i]=1;
    }
    int cnt = 0;
    for(int i = 1;i<n;i++){
        if(dir[i+1]-dir[i]==-1||dir[i+1]-4-dir[i]==-1)cnt++;
    }
    if(dir[1]-dir[n]==-1||dir[1]-4-dir[n]==-1) cnt++;
    cout<<cnt<<endl;
    return 0;
}