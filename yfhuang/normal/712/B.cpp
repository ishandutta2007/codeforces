//
//  main.cpp
//  B
//
//  Created by  on 9/11/16.
//  Copyright  2016 . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 1e5 + 5;

char s[N];

int n[4];


int main(int argc, const char * argv[]) {
    scanf("%s",s + 1);
    memset(n,0,sizeof(n));
    int len = strlen(s + 1);
    for(int i = 1;i <= len;i++){
        if(s[i] == 'U') n[0]++;
        if(s[i] == 'D') n[1]++;
        if(s[i] == 'L') n[2]++;
        if(s[i] == 'R') n[3]++;
    }
    if(len & 1){
        printf("-1");
        return 0;
    }
    int n1 = max(abs(n[0] - n[1]),abs(n[2] - n[3]));
    int n2 = min(abs(n[0] - n[1]),abs(n[2] - n[3]));
    cout << n2 + (n1 - n2) / 2 << endl;
    return 0;
}