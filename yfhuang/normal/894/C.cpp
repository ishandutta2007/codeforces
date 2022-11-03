#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1e4 + 5;

int s[maxn],m,n,a[maxn];

int main(){
    cin >> m;
    for(int i = 1;i <= m;i++){
        scanf("%d",&s[i]);
    }
    int x = s[1];
    for(int i = 2;i <= m;i++){
        x = __gcd(x,s[i]);
    }
    if(x != s[1]){
        printf("-1\n");
        return 0;
    }else{
        cout << 2 * m + 1 << endl;
        for(int i = 1;i <= m;i++){
            printf("%d %d ",s[i],s[1]);
        }
        printf("%d\n",s[1]);
    }
    return 0;
}