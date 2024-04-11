#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long k;
    scanf("%d %lld", &n, &k);

    vector <long long> a(n);
    int cnt = 0;
    long long sum = 0;

    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        if(a[i] == 0)cnt++;
        sum += a[i];
    }

    if(-k * cnt > sum || sum > k * cnt){
        printf("-1\n");
        return 0;
    }

    long long res = 0;

    for(int i = 0; i < n; i++){
        long long cur_pos_left = 0, cur_pos_right = 0, cur_cnt = 0;
        for(int j = i + 1; j < n; j++){
            cur_pos_left += a[j];
            cur_pos_right += a[j];
            if(a[j] == 0){
                cur_cnt++;
                cur_pos_left -= k;
                cur_pos_right += k;
            }

            //leftmost then rightmost
            {
                long long rem = -sum + k * cnt;
                res = max(res, cur_pos_left + min(rem, cur_cnt * 2 * k));
            }
            //rightmost then leftmost
            {
                long long rem = sum + k * cnt;
                res = max(res, -cur_pos_right + min(rem, cur_cnt * 2 * k));
            }
        }
    }

    printf("%lld\n", res + 1);

    return 0;
}