#include <bits/stdc++.h>
using namespace std;

long long f(int n){
    n--;
    if(n <= 60)return 1LL << n;
    else return 1LL << 60;
}
void construct(int i, int n, long long k, stack <int>& a, stack <int>& b){
    if(i == n){
        a.push(i);
        return;
    }

    if(k <= f(n - i)){
        construct(i + 1, n, k, a, b);
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
        a.push(i);
    }else{
        construct(i + 1, n, k - f(n - i), a, b);
        a.push(i);
    }
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        long long k;
        scanf("%d %lld", &n, &k);

        if(k > f(n)){
            printf("-1\n");
            continue;
        }

        stack <int> a, b;
        construct(1, n, k, a, b);

        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }

        bool first = true;
        while(!b.empty()){
            if(first)first = false;
            else printf(" ");

            printf("%d", b.top());
            b.pop();
        }
        printf("\n");
    }

    return 0;
}