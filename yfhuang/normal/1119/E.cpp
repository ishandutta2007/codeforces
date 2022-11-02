#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 3e5 + 5;

int n;

long long a[maxn];

int main(){
    while(cin >> n){
        for(int i = 1;i <= n;i++){
            scanf("%lld", &a[i]);
        }  
        int front = 1, rear = n;
        while(rear > 0 && a[rear] < 2) rear--;
        long long ans = 0;
        int now = rear;
        while(now > 0){
            if(a[now] & 1){
                while(rear > 0 && a[rear] < 2)
                    rear--;
                if(rear >= now){
                    a[rear] -= 2;
                    ans++;
                }
                a[now] -= 1;
            }
            now--;
        }
        while(front < rear){
            if(a[rear] & 1){
                a[front] += 1;
                a[rear] -= 1;
            }
            while(a[front] == 0)
                front++;
            if(front >= rear)
                break;
            int del1 = a[rear] / 2;
            int del2 = a[front];
            int del = min(del1, del2);
            a[rear] -= del * 2;
            a[front] -= del;
            if(a[rear] == 0)
                rear--;
            ans += del;
        }
        if(front == rear){
            ans += a[front] / 3;
        }
        cout << ans << endl;
    }
    return 0;
}