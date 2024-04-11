//
//  main.cpp
//  A
//
//  Created by  on 2017/3/15.
//  Copyright  2017 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

string s[5] = {"Tetrahedron","Cube","Octahedron","Dodecahedron","Icosahedron"};
int num[5] = {4,6,8,12,20};

int main(int argc, const char * argv[]) {
    int n;
    string str;
    cin >> n;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        cin >> str;
        for(int j = 0;j < 5;j++){
            if(str == s[j]){
                ans += num[j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}