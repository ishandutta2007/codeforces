#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;

pair<long long int, long long int>leftup(long long int time, pair<long long int, long long int>p) {
    p.first -= time;
    p.second += time * 2;
    return p;
}
pair<long long int, long long int>left(long long int time, pair<long long int, long long int>p) {
    p.first -= time*2;
    return p;
}
pair<long long int, long long int>leftdown(long long int time, pair<long long int, long long int>p) {
    p.first -= time;
    p.second -= time * 2;
    return p;
}
pair<long long int, long long int>rightdown(long long int time, pair<long long int, long long int>p) {
    p.first += time;
    p.second -= time * 2;
    return p;
}
pair<long long int, long long int>right(long long int time, pair<long long int, long long int>p) {
    p.first += time * 2;
    return p;
}
pair<long long int, long long int>rightup(long long int time, pair<long long int, long long int>p) {
    p.first += time;
    p.second += time * 2;
    return p;
}

int main() {
    long long int aa; cin >> aa;
    long long int k = aa;
    int keta = 1;
    pair<long long int, long long int>n;
    if (aa == 0) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    while (1) {
        if (k > 6 * keta) {
            k -= 6*keta;
            keta++;
        }
        else {
            long long int startx = 2 * keta;
            long long int starty = 0;
            n= (make_pair(startx, starty));
            if (k < keta) {
                n = leftup(k, n);
                break;
            }
            else {
                n = leftup(keta, n);
                k -= (keta);
            }
            bool ok = true;
            for (int i = 0; i < 5; ++i) {
                if (k < keta) {
                    if (i == 0) {
                        n = left(k, n);
                    }
                    else if (i == 1) {
                        n = leftdown(k, n);
                    }
                    else if (i == 2) {
                        n = rightdown(k, n);
                    }
                    else if (i == 3) {
                        n = right(k, n);
                    }
                    else if (i == 4) {
                        n = rightup(k, n);
                    }
                    break;
                }
                else {
                    if (i == 0) {
                        n = left(keta, n);
                    }
                    else if (i == 1) {
                        n = leftdown(keta, n);
                    }
                    else if (i == 2) {
                        n = rightdown(keta, n);
                    }
                    else if (i == 3) {
                        n = right(keta, n);
                    }
                    else if (i == 4) {
                        n = rightup(keta, n);
                    }
                    k -= keta;
                }   
            }
            break;
        }
    }
    cout << n.first <<" "<< n.second << endl;

    return 0;
}