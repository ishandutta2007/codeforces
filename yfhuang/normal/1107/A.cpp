#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;
char s[305];
int main(){
    int q;
    int n;
    while(cin >> q){
        for(int i = 1;i <= q;i++){
            cin >> n;
            scanf("%s", s + 1);
            if(n == 2){
                if(s[1] >= s[2]){
                    puts("NO");
                }else{
                    puts("YES");
                    puts("2");
                    cout << s[1] << " " << s[2] << endl;
                }
            }else{
                puts("YES");
                puts("2");
                if(n & 1){
                   for(int i = 1;i <= n / 2;i++){
                       putchar(s[i]);
                   } 
                   putchar(' ');
                   for(int i = 1 + n / 2;i <= n;i++){
                       putchar(s[i]);
                   }
                   cout << endl;
                }else{
                   for(int i = 1;i <= n / 2 - 1;i++){
                       putchar(s[i]);
                   } 
                   putchar(' ');
                   for(int i = n / 2;i <= n;i++){
                       putchar(s[i]);
                   }
                   cout << endl;
                }
            }
        }
    }

    return 0;
}