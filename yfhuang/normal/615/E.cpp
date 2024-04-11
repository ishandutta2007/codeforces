//
//  main.cpp
//  E
//
//  Created by  on 16/1/10.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;

int main(int argc, const char * argv[]) {
    ll n;
    cin>>n;
    if(n==0) printf("0 0\n");
    else{
    ll a=n/3;
    ll b=floor(sqrt(a)+0.5);
    //cout<<b<<' ';
        //cout<<b*3*(b+1)<<endl;
    while(3*b*(b+1)>=n) b--;
    //cout<<b<<' ';
    //    cout<<n-1-3*b*(b+1)<<endl;
    ll l=b+1;
    ll c=(n-1-3*b*(b+1))/l;
    ll d=(n-1-3*b*(b+1))%l;
    //    cout<<' '<<c<<' '<<d<<endl;
    ll x,y;
    switch (c) {
        case 0: x=l,y=2*l;x+=l-1-d,y-=2*(l-d-1);
            break;
        case 1:x=-l,y=2*l;x+=(l-1-d)*2;
            break;
        case 2: x=-2*l,y=0;x+=l-1-d;y+=2*(l-1-d);
            break;
        case 3: x=-l,y=-2*l;x-=l-1-d;y+=2*(l-1-d);
            break;
        case 4: x=l,y=-2*l;x-=2*(l-1-d);
            break;
        case 5: x=2*l,y=0; x-=l-1-d;y-=2*(l-1-d);
            break;
        default:
            break;
    }
        cout<<x<<' '<<y<<endl;}
    return 0;
}