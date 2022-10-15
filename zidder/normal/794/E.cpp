// https://codeforces.com/problemset/problem/794/E

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3000001;

int n;
int Todd[4*N], Teven[4*N];

void _build(int* arr, vector<int>& vec, int left, int right, int node){
    if(left + 1 == right){
        arr[node] = vec[left];
        return;
    }
    int mid = (left+right)/2;
    _build(arr, vec, left, mid, 2*node);
    _build(arr, vec, mid, right, 2*node+1);
    arr[node] = max(arr[2*node], arr[2*node+1]);
}

void build(int* arr, vector<int>& vec){
    _build(arr, vec, 0, n, 1);
}

int _query(int* arr, int ql, int qr, int l, int r, int node){
    if (ql <= l && r <= qr){
        return arr[node];
    }
    if (qr <= l || r <= ql){
        return 0;
    }
    int mid = (l+r)/2;
    return max(_query(arr, ql, qr, l, mid, 2*node), _query(arr, ql, qr, mid, r, 2*node+1));
}

int query(int* arr, int ql, int qr){
    return _query(arr, ql, qr, 0, n, 1);
}

int main(){
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    // n % 2 == 0 => max of middle two elements
    // n % 2 == 1 => min(middle element, max(next to middle elements))

    int mx = a[0];
    vector<int> even(n);
    for(int i = 0; i < n - 1; i++){
        even[i] = max(a[i], a[i + 1]);
        mx = max(mx, even[i]);
    }

    build(Teven, even);
    vector<int> odd(n);

    for (int i=0;i<n;++i){
        odd[i] = a[i];
        if (i>0 && i+1<n){
            odd[i] = min(odd[i], max(a[i-1], a[i+1]));
        }
    }
    build(Todd, odd);

    for (int i=0;i<n;++i){
        if (n - i == 1){
            cout << mx << endl;
        }
        else if ((n - i) % 2){
            int l = (n - i) / 2;
            int r = (n + i) / 2;
            printf("%d ", query(Todd, l, r + 1));
        } else {
            int l = (n - i) / 2 - 1;
            int r = (n + i) / 2 - 1;
            printf("%d ", query(Teven, l, r + 1));
        }
    }
    return 0;
}