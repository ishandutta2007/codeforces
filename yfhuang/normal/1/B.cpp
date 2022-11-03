//
//  main.cpp
//  B
//
//  Created by  on 8/1/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

string s;

int T;

bool check(char a){
    return a >= 'A' && a <= 'Z';
}

int type(string s){
    int change = 0;
    int len = s.length();
    for(int i = 0;i < len - 1;i++){
        if(check(s[i]) != check(s[i + 1])) change++;
    }
    if(change <= 1) return 0;
    return 1;
}

int main(int argc, const char * argv[]) {
    cin >> T;
    while(T--){
        cin >> s;
        int t = type(s);
        //cout << t << endl;
        int len = s.length();
        if(t == 0){
            int i;
            for(i = 0;i < len;i++){
                if(!check(s[i])) break;
            }
            int x = 0;
            for(int j = 0;j < i;j++){
                x = x * 26 + s[j] - 'A' + 1;
                //cout << x << endl;
            }
           // cout << i << endl;
            int y = 0;
            for(int j = i;j < len;j++){
                y = y * 10 + s[j] - '0';
            }
            printf("R%dC%d\n",y,x);
        }else{
            int p1 = 0;
            int p2 = -1;
            for(int i = 0;i < len;i++){
                if(s[i] == 'C') p2 = i;
            }
            int x = 0,y = 0;
            for(int i = p1 + 1;i < p2;i++){
                x = x * 10 + s[i] - '0';
            }
            for(int i = p2 + 1;i < len;i++){
                y = y * 10 + s[i] - '0';
            }
            swap(x,y);
            string s1 = "";
            while(x > 0){
                int tmp = x % 26;
                if(tmp == 0) tmp = 26;
                x = (x - tmp) / 26;
                char c = tmp + 'A' - 1;
                s1 = c + s1;
            }
            cout << s1;
            printf("%d\n",y);
            
        }
    }
    return 0;
}