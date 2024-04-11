//
//  main.cpp
//  C
//
//  Created by  on 16/4/30.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
#include <set>

using namespace std;
string s;
map<pair<string,int>,int> mp;
bool vis[20000];
set<string> ans;

bool vis1[10000];

void dfs(int l,string pre){
    if(mp[make_pair(pre,l)] == 1) return;
    mp[make_pair(pre,l)] = 1;

    if(l <= 6 ) return;
        //ans.insert(pre);
    string a = s.substr(l - 2,2);
    //cout << a << endl;
    string b = s.substr(l - 3,3);
    if(a != pre){
        ans.insert(a);
        dfs(l - 2,a);
    }if(b != pre && l > 7){
        ans.insert(b);
        dfs(l - 3,b);
    }
    //int x = (a[0] - 'a' + 1) * 26 + (a[1] - 'a' + 1);
    //int y = (b[0] - 'a' + 1) * 26 * 26 + (b[1] - 'a' + 1) * 26 + (b[2] - 'a' + 1);
    //cout << b << endl;
    /*if(vis[x] == false){
        vis[x] = true;
        ans.insert(a);
        dfs(l - 2);
        //if(vis1[l - 2] == false){vis1[l - 2] = true;dfs(l - 2);}
        vis[x] = false;
    }if(vis[y] == false && l > 7){
        vis[y] = true;
        ans.insert(b);
        dfs(l - 3);
        //if(vis1[l - 3] == false){vis1[l - 3] = true;dfs(l - 3);}
        vis[y] = false;
    }*/
}


int main(int argc, const char * argv[]) {
    
    cin >> s;
    //string a = "abc";
    //cout << a.substr(1,2);
    mp.clear();
    int len = s.length();
    //memset(vis,false,sizeof(vis));
    ans.clear();
    //dfs(len);
    dfs(len,"");
    set<string> :: iterator it;
    it = ans.begin();
    cout << ans.size() << endl;
    while(it != ans.end()){
        cout << *it << endl;
        it++;
    }
    return 0;
}