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
vector <string> split(string s){
    stringstream ss;
    ss << s;
    vector <string> v;
    while(ss >> s)
        v.push_back(s);
    return v;
}
bool suffix(string a, string s){
    if(a.size() > s.size())return false;
    for(int i = a.size() - 1; i >= 0; i--)if(a[i] != s[(s.size() - 1) - ((a.size() - 1) - i)])
            return false;
    return true;
}
bool isGender(vector <string> v, int p[], bool gender[]){
    int cnt = 0;
    for(int i = 1; i < v.size(); i++)if(gender[i] != gender[i - 1])
        return false;
    for(int i = 0; i < v.size(); i++)if(p[i] == 1)
        cnt++;
    return cnt == 1;
}
bool isIncreasing(int p[], int n){
    for(int i = 1; i < n; i++)if(p[i] < p[i - 1])
        return false;
    return true;
}
int main(){
//    freopen("a.in", "r", stdin);
    string s;
    getline(cin, s);
    vector <string> v = split(s);
    int p[v.size()];
    bool gender[v.size()];
    for(int i = 0; i < v.size(); i++){
        if(suffix("lios", v[i]) || suffix("liala", v[i])){
            p[i] = 0;
            gender[i] = (suffix("lios", v[i])?true:false);
        }
        else if(suffix("etr", v[i]) || suffix("etra", v[i])){
            p[i] = 1;
            gender[i] = (suffix("etr", v[i])?true:false);
        }
        else if(suffix("initis", v[i]) || suffix("inites", v[i])){
            p[i] = 2;
            gender[i] = (suffix("initis", v[i])?true:false);
        }
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    if(v.size() == 1)cout << "YES" << endl;
    else if(isIncreasing(p, v.size()) && isGender(v, p, gender))cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}