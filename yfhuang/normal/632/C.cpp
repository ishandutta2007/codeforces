//
//  main.cpp
//  c
//
//  Created by  on 16/3/2.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int maxn=5e4+10;

string a[maxn];

bool cmp(string&a,string&b){
    return (a+b)<(b+a);
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        cout<<a[i];
    cout<<endl;
    return 0;
}