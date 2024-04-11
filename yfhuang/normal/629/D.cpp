//
//  main.cpp
//  D
//
//  Created by  on 16/2/21.
//  Copyright  2016 . All rights reserved.
//


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

int n,r,h;

long long ans=0;

const double pi=acos(-1);

map<long long,long long>mp;

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    mp[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&r,&h);
        long long v=(long long)r*r*h;
        map<long long,long long>::iterator it=mp.lower_bound(v);
        it--;
        long long v1=it->second+v;
        mp[v]=v1;
        ans=max(ans,v1);
        it=mp.find(v);
        it++;
        while(it!=mp.end()){
            if(it->second<=v1){
                map<long long,long long>::iterator it2=it;
                it++;
                mp.erase(it2);
            }else break;
        }
    }
    printf("%.10lf\n",1.0*ans*pi);
    return 0;
}