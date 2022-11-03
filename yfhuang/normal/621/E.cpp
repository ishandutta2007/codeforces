//
//  main.cpp
//  E
//
//  Created by  on 16/1/31.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<long long> vec;
typedef vector<vec> mat;
typedef long long ll;
const ll Mod=1e9+7;

mat mul(mat& A,mat& B){
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            for(int k=0;k<B[0].size();k++){
                C[i][k]=(C[i][k]+A[i][j]*B[j][k])%Mod;
            }
        }
    }
    return C;
}

mat pow(mat A,ll n){
    mat B(A.size(),vec(A[0].size()));
    for(int i=0;i<A.size();i++)
        B[i][i]=1;
    while(n > 0){
        if(n & 1)B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}


int main(int argc, const char * argv[]) {
    ll n,b,k,x;
    cin>>n>>b>>k>>x;
    int a[10]={0};
    for(int i=1;i<=n;i++){
        int b;
        scanf("%d",&b);
        a[b]++;
    }
    mat A(105,vec(105));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++)
            A[i][j]=0;
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<10;j++){
            A[i][(10*i+j)%x]+=a[j];
        }
    }
    A=pow(A,b);
    cout<<A[0][k]<<endl;
    return 0;
}