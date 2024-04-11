#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <bits/stdc++.h>
using namespace std;
int a[100009];
int main(){
    int n;
    cin>>n;
    int res=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    multiset<int> s;
    int l=1,r=2;
    s.insert(a[1]);
    while(r<=n){
        s.insert(a[r]);
        while(*(s.begin())+1<*(s.rbegin())){
            s.erase(s.find(a[l]));
            l++;
        }
        r++;
        res=max(res,r-l);
    }
    cout<<res<<endl;
}