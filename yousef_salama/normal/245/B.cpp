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
string s;
int main(){
    cin >> s;
    
    string pro, dom, con; 
    int st;
    if(s[0] == 'f'){
        pro = "ftp";
        st = 3;
    }else{
        pro = "http";
        st = 4;
    }
    
    for(int i = st + 1; i < s.size() - 1; i++){
        if(s[i] == 'r' && s[i + 1] == 'u'){
            dom = s.substr(st, i - st);
            con = s.substr(i + 2);
            break;
        }
    }
    cout << pro;
    cout << "://";
    cout << dom;
    cout << ".ru";
    
    if(!con.empty()){
        cout << "/";
        cout << con;
    }
    cout << endl;
    return 0;
}