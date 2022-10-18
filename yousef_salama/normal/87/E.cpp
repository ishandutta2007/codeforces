//In the name of Allah

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#include <complex>
#include <unordered_map>

using namespace std;

struct point{
    long long x, y;
};

point operator -(point a){
    point c;
    c.x = -a.x, c.y = -a.y;
    return c;
}
point operator +(point a, point b){
    point c;
    c.x = a.x + b.x, c.y = a.y + b.y;
    return c;
}

long long operator *(point a, point b){
    return a.y * b.x - a.x * b.y;
}
bool operator <(point a, point b){
    if(a * b > 0)return true;
    else return false;
}

point min_point(vector <point> X){
    point mX = X[0];
    for(int i = 0; i < X.size(); i++){
        if(X[i].x < mX.x)mX = X[i];
        else if((X[i].x == mX.x) && (X[i].y < mX.y))mX = X[i];
    }
    return mX;
}

vector <point> difference(vector <point> X){
    vector <point> dX;
    for(int i = 1; i < X.size(); i++)
        dX.push_back(X[i] + (-X[i - 1]));
    dX.push_back(X[0] + (-X[X.size() - 1]));
    
    return dX;
}

vector <point> sum(vector <point> dX){
    vector <point> X;
    
    point O;
    O.x = 0, O.y = 0;
    
    X.push_back(O);
    
    for(int i = 0; (i + 1) < dX.size(); i++)
        X.push_back(X.back() + dX[i]);
    return X;
}

void print(vector <point> X){
    printf("%d\n", X.size());
    for(int i = 0; i < X.size(); i++)
        printf("(%I64d,%I64d),\n", X[i].x, X[i].y);
}
vector <point> sort_(vector <point> X){
    vector <point> A, B;
    for(int i = 0; i < X.size(); i++){
        if(X[i].y > 0)A.push_back(X[i]);
        else if(X[i].y < 0)B.push_back(X[i]);
        else{
            if(X[i].x < 0)A.push_back(X[i]);
            else B.push_back(X[i]);
        }
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    vector <point> R;
    R.insert(R.end(), A.begin(), A.end());
    R.insert(R.end(), B.begin(), B.end());
    return R;
}

vector <point> minkowski_sum(vector <point> A, vector <point> B){
    vector <point> dA = difference(A);
    vector <point> dB = difference(B);
    
    //print(dA);
    //print(dB);
    
    vector <point> dC;
    dC.insert(dC.end(), dA.begin(), dA.end());
    dC.insert(dC.end(), dB.begin(), dB.end());
    
    dC = sort_(dC);
    
    //print(dC);
    
    vector <point> C = sum(dC);
    point d = (-min_point(C)) + (min_point(A) + min_point(B));
    
    for(int i = 0; i < C.size(); i++)C[i] = C[i] + d;
    return C;
}

long long ccw(point a, point b, point c){
    return (b + (-a)) * (c + (-a));
}

vector <point> zabat(vector <point> X){
    int j = 0;
    for(int i = 0; i < X.size(); i++){
        if(X[i].x < X[j].x)j = i;
        else if((X[i].x == X[j].x) && (X[i].y < X[j].y))j = i;
    }
    
    vector <point> R;
    R.push_back(X[j]);
    
    //for(int d = 1; d < X.size(); d++)
      //  R.push_back(X[(j + d) % X.size()]);
    
    for(int d = 1; d < X.size(); d++){
        if(R.size() < 2)R.push_back(X[(j + d) % X.size()]);
        else{
            if(ccw(R[R.size() - 2], R[R.size() - 1], X[(j + d) % X.size()]) == 0)R.pop_back();
            R.push_back(X[(j + d) % X.size()]);
        }
    }
    
    while(R.size() >= 3){
        if(ccw(R[0], R[R.size() - 1], R[R.size() - 2]) == 0)R.pop_back();
        else break;
    }
    return R;
}

int m, nA, nB, nC;
vector <point> A, B, C;
    
int main(){
    scanf("%d", &nA);
    for(int i = 0; i < nA; i++){
        point p;
        scanf("%I64d %I64d", &p.x, &p.y);
        A.push_back(p);
    }
    scanf("%d", &nB);
    for(int i = 0; i < nB; i++){
        point p;
        scanf("%I64d %I64d", &p.x, &p.y);
        B.push_back(p);
    }
    scanf("%d", &nC);
    for(int i = 0; i < nC; i++){
        point p;
        scanf("%I64d %I64d", &p.x, &p.y);
        C.push_back(p);
    }
    
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    reverse(C.begin(), C.end());
    
    
    vector <point> M = zabat(minkowski_sum(minkowski_sum(A, B), C));
    
    //print(A);
    //print(B);
    //print(C);
    
    //print(minkowski_sum(A, B));
    //print(minkowski_sum(A, C));
    //print(minkowski_sum(B, C));
    
    //print(M);
    
    scanf("%d", &m);
    while(m--){
        point p;
        scanf("%I64d %I64d", &p.x, &p.y);
        
        p.x *= 3, p.y *= 3;
        
        int L = 1, R = M.size() - 1;
        while((R - L) >= 2){
            int mid = (L + R) / 2;
            
            long long c = ccw(M[0], M[mid], p);
            if(c > 0)L = mid;
            else R = mid;
        }
        
        /*if((p.x == 0) && (p.y == 12)){
            cout << M[0].x << ',' << M[0].y << endl;
            cout << M[L].x << ',' << M[L].y << ' ' << M[R].x << ',' << M[R].y << endl;
        }*/
        
        bool f = true;
        if(ccw(M[0], M[L], p) < 0)f = false;
        if(ccw(M[L], M[R], p) < 0)f = false;
        if(ccw(M[R], M[0], p) < 0)f = false;
        
        if(f)printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}