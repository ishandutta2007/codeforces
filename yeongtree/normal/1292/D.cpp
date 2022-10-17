#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int arr[n]; for(auto &i : arr) cin >> i;
    sort(arr, arr + n);

    vector<int> prime;
    int cnt[5001]{};
    for(int i = 2; i <= 5000; ++i)
    {
        int tmp = i;
        for(int j = 2; j * j <= tmp; ++j)
        {
            while(tmp % j == 0)
            {
                ++cnt[i];
                tmp /= j;
            }
        }

        if(tmp == i) prime.push_back(i);
        if(tmp != 1) ++cnt[i];
    }
    prime.push_back(5001);
    for(int i = 2; i <= 5000; ++i) cnt[i] += cnt[i - 1];

    long long ans = 0;
    for(auto i : arr) ans += cnt[i];

    int pt1 = 0, pt2 = n;
    bool flag = false;
    int pri;
    for(int i = 1; i < prime.size(); ++i)
    {
        if(lower_bound(arr, arr + n, prime[i]) - lower_bound(arr, arr + n, prime[i - 1]) > n / 2)
        {
            pt2 = lower_bound(arr, arr + n, prime[i]) - arr;
            pt1 = lower_bound(arr, arr + n, prime[i - 1]) - arr;
            flag = true;
            ans += (n - 2 * (pt2 - pt1));
            pri = i - 2;
            break;
        }
    }

    if(flag)
    {
        for(int i = pri; i >= 0; --i)
        {
            bool flag = true;
            for(int j = 1; j <= 5000 / prime[i]; ++j)
            {
                if((arr + pt2) - lower_bound(arr + pt1, arr + pt2, j * prime[i]) > n / 2)
                {
                    pt1 = lower_bound(arr + pt1, arr + pt2, j * prime[i]) - arr;
                    int pow = 1; int tj = j;
                    while(tj % prime[i] == 0) {++pow; tj /= prime[i];}
                    ans += (n - 2 * (pt2 - pt1)) * pow;
                }
                else if(lower_bound(arr + pt1, arr + pt2, j * prime[i]) - (arr + pt1) > n / 2)
                {
                    pt2 = lower_bound(arr + pt1, arr + pt2, j * prime[i]) - arr;
                    break;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
    }

    cout << ans;
    return 0;
}