#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;

vector<string> a, b;

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        string s;
        cin >> s;
        a.push_back(s);
    }
    for(int i = 1;i <= m;i++){
        string s;
        cin >> s;
        b.push_back(s);
    }
    int q;
    cin >> q;
    for(int i = 1;i <= q;i++){
        int y;
        scanf("%d", &y);
        y--;
        string s1 = a[y % n];
        string s2 = b[y % m];
        string s = s1 + s2;
        cout << s << endl;
    }
    return 0;
}