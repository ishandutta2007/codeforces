//
//  main.cpp
//  D
//
//  Created by  on 9/12/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace  std;


typedef vector<double> vec;
typedef vector<vec> mat;


mat mul(mat & A,mat & B){
    mat C(A.size(),vec(B[0].size()));
    for(int i = 0;i < A.size();i++){
        for(int k = 0;k < B.size();k++){
            for(int j = 0;j < B[0].size();j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]);
            }
        }
    }
    return C;
}

mat pow(mat A,int n){
    mat B(A.size(),vec(A[0].size()));
    for(int i = 0;i < A.size();i++){
        B[i][i] = 1.0;
    }
    while(n > 0){
        if(n & 1) B = mul(B,A);
        A = mul(A,A);
        n >>= 1;
    }
    return B;
}

int n;

int x;

double p[200];

int main(int argc, const char * argv[]) {
    cin >> n;
    cin >> x;
    memset(p,0,sizeof(p));
    for(int i = 0;i <= x;i++) cin >> p[i];
    mat A(128,vec(128));
    for(int i = 0;i < 128;i++){
        for(int j = 0;j < 128;j++){
            int tmp = i ^ j;
            A[j][i] += p[tmp];
        }
    }
    A = pow(A,n);
//    for(int i = 0;i < 128;i++){
//        for(int j = 0;j < 128;j++){
//            cout << A[i][j] << " ";
//        }
//        cout << endl;
//    }
    double ans = 0;
    for(int i = 1;i < 128;i++){
        ans += A[i][0];
    }
    printf("%.10lf\n",ans);
    return 0;
}