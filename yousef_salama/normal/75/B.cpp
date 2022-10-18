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
string name, action;
int N;
map <string, int> mp;
vector < pair <string, int> > p;
bool cmp(pair <string, int> a, pair <string, int> b){
    if(a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}
int main(){
    cin >> name >> N;
    getline(cin, action);
    while(N--){
        getline(cin, action);
        vector <string> v;
        stringstream ss;
        ss << action;
        while(ss >> action)
            v.push_back(action);

        if(v[1] == "posted"){
            string name1 = v[0], name2 = v[3].substr(0, v[3].size() - 2);

            if(!mp.count(name1))mp[name1] = 0;
            if(!mp.count(name2))mp[name2] = 0;

            if(name1 == name){
                mp[name2] += 15;
            }else if(name2 == name){
                mp[name1] += 15;
            }
        }else if(v[1] == "commented"){
            string name1 = v[0], name2 = v[3].substr(0, v[3].size() - 2);

            if(!mp.count(name1))mp[name1] = 0;
            if(!mp.count(name2))mp[name2] = 0;

            if(name1 == name){
                mp[name2] += 10;
            }else if(name2 == name){
                mp[name1] += 10;
            }

        }else{
            string name1 = v[0], name2 = v[2].substr(0, v[2].size() - 2);

            if(!mp.count(name1))mp[name1] = 0;
            if(!mp.count(name2))mp[name2] = 0;

            if(name1 == name){
                mp[name2] += 5;
            }else if(name2 == name){
                mp[name1] += 5;
            }
        }
    }
    for(map <string, int> :: iterator it = mp.begin(); it != mp.end(); it++)
        if(it->first != name)p.push_back(make_pair(it->first, it->second));
    sort(p.begin(), p.end(), cmp);
    for(int i = 0; i < p.size(); i++)
        cout << p[i].first << endl;
    return 0;
}