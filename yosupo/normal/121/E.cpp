#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

const int MAX_N = 100010;
const int MAX_D = 10010;

const int BUCKET_SIZE = 256;
const int BUCKET_NUM = (MAX_N+BUCKET_SIZE-1)/BUCKET_SIZE;

int data[MAX_N];
int bucket[BUCKET_NUM][MAX_D] = {}, bucket2[BUCKET_NUM] = {}, bucket3[BUCKET_NUM] = {};
bool isLucky[MAX_D] = {}, counted[BUCKET_NUM] = {};
vector<int> rucky_numbers;

void add1(int i, int x) {
    bucket[i/BUCKET_SIZE][data[i]]--;
    data[i] += x;
    bucket[i/BUCKET_SIZE][data[i]]++;
}

void add(int l, int r, int x) {
    counted[l/BUCKET_SIZE] = false;
    counted[(r-1)/BUCKET_SIZE] = false;
    while (l < r && l % BUCKET_SIZE) {
        add1(l, x);
        l++;
    }
    while (l < r && r % BUCKET_SIZE) {
        r--;
        add1(r, x);
    }
    l /= BUCKET_SIZE; r /= BUCKET_SIZE;
    while (l < r) {
        counted[l] = false;
        bucket2[l] += x;
        l++;
    }    
}

int count1(int i) {
    return isLucky[data[i]+bucket2[i/BUCKET_SIZE]] ? 1 : 0;
}

int count(int l, int r) {
    int c = 0;
    while (l < r && l % BUCKET_SIZE) {
        c += count1(l);
        l++;
    }
    while (l < r && r % BUCKET_SIZE) {
        r--;
        c += count1(r);
    }
    l /= BUCKET_SIZE; r /= BUCKET_SIZE;
    while (l < r) {
        if (counted[l]) {
            c += bucket3[l];
        } else {
            int r = 0;
            for (int d: rucky_numbers) {
                if (bucket2[l] > d) continue;
                r += bucket[l][d-bucket2[l]];
            }
            bucket3[l] = r;
            counted[l] = true;
            c += r;
        }
        l++;
    } 
    return c;
}

bool lucky_check(int n) {
    while (n) {
        if (n%10 != 4 && n%10 != 7) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < MAX_D; i++) {
        if (lucky_check(i)) {
            rucky_numbers.push_back(i);
            isLucky[i] = true;
        }
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
        bucket[i/BUCKET_SIZE][data[i]]++;
    }
    for (int i = 0; i < m; i++) {
        string s;
        int l, r;
        cin >> s >> l >> r;
        l--;
        if (s == "add") {
            int x;
            scanf("%d", &x);
            add(l, r, x);
        } else {
            printf("%d\n", count(l, r));
        }
    }
    return 0;
}