#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;

char s[maxn];
int n;

int main(){
    while(cin >> n){
        scanf("%s", s + 1);
        int numz = 0;
        int nume = 0;
        for(int i = 1;i <= n;i++){
            if(s[i] == 'z')
                numz++;
            if(s[i] == 'e')
                nume++;
        }
        for(int i = 1;i <= nume - numz;i++){
            printf("1 ");
        }
        for(int i = 1;i <= numz;i++){
            printf("0 ");
        }
    }


    return 0;
}