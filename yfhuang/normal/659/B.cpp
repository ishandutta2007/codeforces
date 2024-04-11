//
//  main.cpp
//  B
//
//  Created by  on 16/3/30.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int n, m;
const int maxn = 1e5 + 5;

bool ok[10005];

pair<int,int> ans[10005];

string mp[maxn];

struct person{
    int id;
    int re;
    int t;
    bool operator < (const person & rhs) const{
        return re < rhs.re || (re == rhs.re && t < rhs .t);
    }
}p[maxn];


int main(int argc, const char * argv[]) {
    cin >> n >> m;
    string a;
    int r,tt;
    for(int i = 1; i <= n; i++){
        cin >> a;
        cin >> r >> tt;
        mp[i] = a;
        p[i].re = r;
        p[i].t = tt;
        p[i].id = i;
    }
    sort(p + 1,p + 1 + n);
    memset(ok,true,sizeof(ok));
    for(int i =1, j =1; i<=n;i = j + 1,j = i){
        while(j<n&&p[j].re==p[j+1].re) j++;
        if(j == i + 1){
            ans[p[j].re].first = p[j].id;
            ans[p[j].re].second = p[j-1].id;
        }
        else{
        if(p[j].t==p[j-1].t){
            {
                if(p[j-1].t == p[j-2].t) ok[p[j].re] = false;
                else {
                    ans[p[j].re].first = p[j].id;
                    ans[p[j].re].second = p[j-1].id;
                }
            }
            
        }else{
            if(p[j-1].t==p[j-2].t) ok[p[j-1].re] = false;
            else{
                ans[p[j].re].first = p[j].id;
                ans[p[j-1].re].second = p[j-1].id;
            }
        }
        }
    }
    for(int i =1 ;i<= m;i++){
        if(ok[i]){
            cout<<mp[ans[i].first]<<' '<<mp[ans[i].second]<<endl;
        }else{
            puts("?");
        }
    }
    return 0;
}