#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#define oo 1 << 25
using namespace std;
int N, K;
string s[2505][4];
string r[2505], ry = "aaaa", cur;
bool isvowel(char a){
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}
bool rhyme(string a, string b){
    int cnt = 0;
    string a1 = "", b1 = "";
    for(int i = a.size() - 1; i >= 0; i--){
        if(isvowel(a[i]))
            cnt++;
        if(cnt == K){
            a1 = a.substr(i);
            break;
        }
    }
    if(a1.empty())return 0;
    cnt = 0;
    for(int i = b.size() - 1; i >= 0; i--){
        if(isvowel(b[i]))
            cnt++;
        if(cnt == K){
            b1 = b.substr(i);
            break;
        }
    }
    if(b1.empty())return 0;
    return a1 == b1;
}
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    for(int j = 0; j < 4; j++)
        cin >> s[i][j];
    for(int i = 0; i < N; i++){
        cur = "ffff";
        int cnt = -1;
        for(int j = 0; j < 4; j++){
            if(cur[j] != 'f')continue;
            cnt++;
            for(int k = 0; k < 4; k++)
                if(rhyme(s[i][j], s[i][k]))
                    cur[k] = cnt + 'a';
        }
        if(cur == "aaaa")continue;
        if(cur == "aabb" || cur == "abab" || cur == "abba"){
            if(ry == "aaaa")ry = cur;
            else{
                if(ry == cur)continue;
                else{
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << ry << endl;
    return 0;
}