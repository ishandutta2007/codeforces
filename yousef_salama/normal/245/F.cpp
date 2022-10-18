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
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;
int n, m;
string s;
struct entry{
    int mon, day, hour, minu, sec;
};
vector <string> split(string a){
    vector <string> ret;
    stringstream ss;
    ss << a;
    while(ss >> a)
        ret.push_back(a);
    return ret;
}
int sz[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 29};
bool operator <(entry a, entry b){
    if(a.mon != b.mon)return a.mon < b.mon;
    
    if(a.day != b.day)return a.day < b.day;
    
    if(a.hour != b.hour)return a.hour < b.hour;
    
    if(a.minu != b.minu)return a.minu < b.minu;
    
    if(a.sec != b.sec)return a.sec < b.sec;
}
vector <entry> a;
long long dist(int i, int j){
    int sec1 = a[i].sec + a[i].minu * 60LL + a[i].hour * 3600LL + a[i].day * 24LL * 3600LL + a[i].mon * 24LL * 3600LL * sz[a[i].mon];
    int sec2 = a[j].sec + a[j].minu * 60LL + a[j].hour * 3600LL + a[j].day * 24LL * 3600LL + a[j].mon * 24LL * 3600LL * sz[a[i].mon];
    
    return sec1 - sec2;
}
int main(){
    for(int i = 1; i <= 12; i++)
        sz[i] += sz[i - 1];
    
    cin >> n >> m;
    getline(cin, s);
    
    while(getline(cin, s)){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '-' || s[i] == ':')s[i] = ' ';
        }
        //cout << s << endl;
        vector <string> v = split(s);

        entry e;
        e.mon = atoi(v[1].c_str());
        e.day = atoi(v[2].c_str());
        e.hour = atoi(v[3].c_str());
        e.minu = atoi(v[4].c_str());
        e.sec = atoi(v[5].c_str());

        a.push_back(e);
    }
    sort(a.begin(), a.end());
    for(int i = 0, j = 0; i < a.size(); i++){
        while(j < i && dist(i, j) >= n)j++;
        
        if(i - j + 1 >= m){
            printf("2012-%02d-%02d %02d:%02d:%02d\n", a[i].mon, a[i].day, a[i].hour, a[i].minu, a[i].sec);
           return 0;
        }
    }
    printf("-1\n");
    return 0;
}