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
int main(){
    int n;
    cin >> n;
    string captain, name, s;
    vector <string> rats;
    vector <string> wC;
    vector <string> mans;
    for(int i = 0; i < n; i++){
        cin >> name >> s;
        if(s == "captain")captain = name;
        else if(s == "rat")rats.push_back(name);
        else if(s == "woman" || s == "child")wC.push_back(name);
        else mans.push_back(name);
    }
    for(int i = 0; i < rats.size(); i++)cout << rats[i] << endl;
    for(int i = 0; i < wC.size(); i++)cout << wC[i] << endl;
    for(int i = 0; i < mans.size(); i++)cout << mans[i] << endl;
    cout << captain << endl;
    return 0;
}