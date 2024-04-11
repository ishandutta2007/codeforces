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
using namespace std;
vector <string> v;
int n, bi, ci;
string ai;
bool rem[10005];
int main(){
    for(int i = 0; i < 10000; i++){
        stringstream ss;
        ss << i;
        string s = ss.str();
        while(s.size() < 4)
            s = "0" + s;

        bool wrong = false;
        for(int i = 0; i < 4; i++)
        for(int j = i + 1; j < 4; j++)
            if(s[i] == s[j])wrong = true;

        if(!wrong)v.push_back(s);
    }
    memset(rem, 0, sizeof rem);
    cin >> n;
    while(n--){
        cin >> ai >> bi >> ci;
        for(int i = 0; i < v.size(); i++)
            if(!rem[i]){
                int x = 0, y = 0;
                for(int j = 0; j < 4; j++)
                for(int k = 0; k < 4; k++){
                    if(ai[j] == v[i][k]){
                        if(j == k)x++;
                        else y++;
                    }
                }
                if(x != bi || y != ci)rem[i] = true;
            }
    }
    int cnt = 0, cur;
    for(int i = 0; i < v.size(); i++)
        if(!rem[i]){
            cnt++;
            cur = i;
        }
    if(cnt == 0)cout << "Incorrect data" << endl;
    else if(cnt == 1)cout << v[cur] << endl;
    else cout << "Need more data" << endl;
    
    return 0;
}