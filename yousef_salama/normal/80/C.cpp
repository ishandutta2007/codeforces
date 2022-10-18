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
int n, mon[3], diff, liking, v[7], size[3];
bool g[7][7];
string s1, s2, s3;
map <string, int> mp;
void rec(int ind){
    if(ind == 7){
        for(int i = 0; i <= 2; i++)
            if(size[i] == 0)return;
        int curMax = INT_MIN, curMin = INT_MAX, curLiking = 0;
        for(int i = 0; i < 7; i++){
            curMax = max(curMax, mon[v[i]] / size[v[i]]);
            curMin = min(curMin, mon[v[i]] / size[v[i]]);
        }
        for(int i = 0; i < 7; i++)
        for(int j = 0; j < 7; j++)
            if(i != j && g[i][j] && v[i] == v[j])
                curLiking++;

        if(diff == -1 || diff > curMax - curMin || (diff == curMax - curMin && curLiking > liking)){
            diff = curMax - curMin;
            liking = curLiking;
        }
    }else{
        for(int i = 0; i <= 2; i++){
            v[ind] = i;
            size[i]++;
            rec(ind + 1);

            size[i]--;
        }
    }
}
int main(){
    cin >> n;

    mp["Anka"] = 0;
    mp["Chapay"] = 1;
    mp["Cleo"] = 2;
    mp["Troll"] = 3;
    mp["Dracul"] = 4;
    mp["Snowy"] = 5;
    mp["Hexadecimal"] = 6;

    for(int i = 0; i < n; i++){
        cin >> s1 >> s2 >> s3;
        g[mp[s1]][mp[s3]] = true;
    }
    for(int i = 0; i < 3; i++)
        cin >> mon[i];

    diff = -1;
    rec(0);
    cout << diff << ' ' << liking << endl;
    return 0;
}