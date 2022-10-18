#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <set>
char a[] = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u'};

using namespace std;
int main (){
    set<char> s;
    for(int i = 0; i < 11; i++)s.insert(a[i]);

    string q, t;
    while(cin >> t)
        q += t+" ";

    int p = q.size()-1;
    while(p > 0 && (q[p]==' ' || q[p]=='?'))p--;

    if(s.count(q[p]))cout << "YES";
    else cout << "NO";
}