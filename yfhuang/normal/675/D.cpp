//
//  main.cpp
//  D
//
//  Created by  on 16/5/17.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;

const int maxn = 1e5 + 5;

struct Node{
    int v;
    int h;
    int fav;
    bool operator < (const Node & rhs) const{
        return v < rhs.v;
    }
    Node(int v = 0):v(v){
        h = 0;
        fav = -1;
    }
}p[maxn];

int n;

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 1;i <= n;i++){
        int v;
        scanf("%d",&v);
        p[i] = Node(v);
    }
    set<Node> s;
    p[1].h = 1;
    s.insert(p[1]);
    set<Node> ::iterator it;
    for(int i = 2;i <= n;i++){
        it = s.lower_bound(p[i]);
        if(it == s.end()){
            p[i].h = (--it) -> h + 1;
            p[i].fav = it -> v;
        }else if(it == s.begin()){
            p[i].h = it -> h + 1;
            p[i].fav = it -> v;
        }else{
            int h1 = it->h;
            int v1 = it->v;
            it--;
            int h2 = it->h;
            int v2 = it->v;
            if(h1 >= h2){
                p[i].fav = v1;
            }else{
                p[i].fav = v2;
            }
            p[i].h = max(h1,h2) + 1;
            //cout << h1 << ' ' << v1 << ' ' << h2 << ' ' << v2 << endl;
        }
        s.insert(p[i]);
    }
    for(int i = 2;i <= n;i++){
        printf("%d ",p[i].fav);
    }
    return 0;
}