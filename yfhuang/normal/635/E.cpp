//
//  main.cpp
//  e
//
//  Created by  on 16/3/1.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int maxm=200005;

pii a[maxm];

int main(int argc, const char * argv[]) {
    int l,c,n;
    cin>>l>>c>>n;
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);// position and price;
    }
    a[n++]={0,0};
    a[n++]={l,0};
    
    ll ans=0; int j=0;
    sort(a,a+n);
    multiset <pair<int,int> > station;
    for(int i=0;i<n-1;i++){
        station.insert({a[i].second,a[i].first});
        
        int pos=a[i].first;
        int next=a[i+1].first;
        while(pos<next){
            while(j<=i&&a[j].first+c<=pos){
                station.erase({a[j].second,a[j].first});
                j++;
            }
            if(station.empty()){
                puts("-1");
                return 0;
            }
            int take=min(next-pos,c-(pos-station.begin()->second));
            ans+=(ll) take*station.begin()->first;
            pos+=take;
        }
    }
    cout<<ans<<endl;
    return 0;
}