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
int n;
string opr, dir;
vector <string> v;
vector <string> split(string a){
    stringstream ss;
    ss << a;
    vector <string> ret;
    while(ss >> a)
        ret.push_back(a);
    return ret;
}
int main(){
    cin >> n;
    while(n--){
        cin >> opr;
        if(opr == "pwd"){
            cout << '/';
            for(int i = 0; i < v.size(); i++)
                cout << v[i] << '/';
            cout << endl;
        }else{
            cin >> dir;
            if(dir[0] == '/')v.clear();
            for(int i = 0; i < dir.size(); i++)
                if(dir[i] == '/')dir[i] = ' ';
            vector <string> a = split(dir);
            for(int i = 0; i < a.size(); i++){
                if(a[i] == "..")
                    v.pop_back();
                else v.push_back(a[i]);
            }
        }
    }
    return 0;
}