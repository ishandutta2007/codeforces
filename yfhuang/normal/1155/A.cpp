#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 3e5 + 5;

char s[maxn];
int n;
int main(){
    while(cin >> n){
        bool flag = false;
        scanf("%s", s + 1);
        int i;
        for(i = 1;i < n;i++){
            if(s[i] > s[i + 1]){
                flag = true;
                swap(s[i], s[i + 1]);
                break;
            }
        }
        if(flag){
            puts("YES");
            printf("%d %d\n", i, i + 1);
        }else{
            puts("NO");
        }
    } 
    return 0;
}