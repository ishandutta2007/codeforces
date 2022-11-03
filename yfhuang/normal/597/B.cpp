//
//  main.cpp
//  B
//
//  Created by  on 15/11/13.
//  Copyright  2015 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
pair <int,int> order[500000+5];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&order[i].second,&order[i].first);
    }
    sort(order+1,order+1+n);
    //printf("%d %d",order[1].first,order[2].first);
    int l=order[1].first+1;
    int num=1;
    for(int i=2;i<=n;i++){
        if(order[i].second>=l) { l=order[i].first+1; num++;}
    }
    cout<<num<<endl;
    return 0;
}