#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

typedef long long LL;

int main () {
    vector<LL> v;
    v.push_back(0);
    v.push_back(1);
    while (true) {
        LL a=v[v.size()-1];
        LL b=v[v.size()-2];
        if (a > 2e18) break;
        v.push_back(a+b);
    }
    LL id=0;
    LL n;
    cin >> n;
    for (LL i:v) {
        if (i>n) break;
        id++;
    }
    cout<<id-3<<endl;
}