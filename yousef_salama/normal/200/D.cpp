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
int n, m, k;
string line;
vector <string> v;
vector <vector <string> > proc;
map <string, string> type;
int main(){
    cin >> n;
    getline(cin, line);
    while(n--){
        getline(cin, line);
        for(int i = 0; i < line.size(); i++)
            if(line[i] == '(' || line[i] == ')' || line[i] == ',')line[i] = ' ';
        stringstream ss;
        ss << line;
        v.clear();
        while(ss >> line)
            v.push_back(line);

        proc.push_back(v);
    }

    cin >> m;
    getline(cin, line);
    while(m--){
        string a, b;
        cin >> a >> b;
        type[b] = a;
    }
    cin >> k;
    getline(cin, line);
    while(k--){
        getline(cin, line);
        for(int i = 0; i < line.size(); i++)
            if(line[i] == '(' || line[i] == ')' || line[i] == ',')line[i] = ' ';
        stringstream ss;
        ss << line;
        v.clear();
        while(ss >> line)
            v.push_back(line);

        int cnt = 0;
        for(int i = 0; i < proc.size(); i++){
            if(v.size() == proc[i].size() - 1 && proc[i][1] == v[0]){
                bool wrong = false;
                for(int j = 2; j < proc[i].size(); j++){
                    string cur = type[v[j - 1]];
                    if(proc[i][j] == "T" || proc[i][j] == cur)continue;

                    wrong = true;
                }
                if(!wrong)cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}