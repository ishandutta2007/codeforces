#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
char s[MAXN];

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        if(n <= 26){
            for(int i = 0; i < n; i++)
                s[i] = 'a' + i;
            s[n] = 0;
            printf("%s\n", s);

            continue;
        }

        if(n % 2 == 0){
            for(int i = 0; i < n / 2; i++)
                s[i] = 'a';
            s[n / 2] = 'b';
            for(int i = n / 2 + 1; i < n; i++)
                s[i] = 'a';
            s[n] = 0;

            printf("%s\n", s);
        }else{
            for(int i = 0; i < n / 2; i++)
                s[i] = 'a';
            s[n / 2] = 'b';
            for(int i = n / 2 + 1; i < n - 1; i++)
                s[i] = 'a';
            s[n - 1] = 'c';
            s[n] = 0;

            printf("%s\n", s);
        }
    }

    return 0;
}