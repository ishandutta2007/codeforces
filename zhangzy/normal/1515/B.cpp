#include <bits/stdc++.h>
using namespace std;

int T, n;
set<long long>S;

bool chk(){
    if (n%2==0){
        if (S.count(n/2)) return 1;
    }
    if (n%4==0){
        if (S.count(n/4)) return 1;
    }
    return 0;
}

int main(){
    for (int i=1;i<=100000;++i) S.insert((long long)i*i);
    for (cin>>T;T--;){
        cin>>n;
        puts(chk()? "YES": "NO");
    }
}