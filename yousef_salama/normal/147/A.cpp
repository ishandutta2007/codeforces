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
string s;
vector <string> split(string a){
    stringstream ss;
    ss << a;
    vector <string> v;
    while(ss >> a)
        v.push_back(a);
    return v;
}
int main(){
    getline(cin, s);
    vector <string> v = split(s);
    s = "";
    for(int i = 0; i < v.size(); i++){
        if(i != 0)
            if(!ispunct(v[i][0]))s += ' ';
        string a = v[i];
        for(int j = 0; j < v[i].size(); j++){
            s += v[i][j];
            if(ispunct(v[i][j]) && j != v[i].size() - 1)s += ' ';
        }
    }
    cout << s << endl;
    return 0;
}