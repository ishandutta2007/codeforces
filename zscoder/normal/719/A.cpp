#include <bits/stdc++.h>
using namespace std; 

int n; 
int a[100005];
int main() {
    cin >> n; 
    
    if(n==1) {
        int x; cin >> x;
        if(x == 0) cout<<"UP\n";
        else if(x == 15) cout << "DOWN\n";
        else cout << "-1\n"; 
        return 0;
    }
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    
    if (a[n]+1 <= 15 && (a[n] > a[n-1] || a[n]==0) ) { 
        cout << "UP\n";
    }
    else cout << "DOWN\n";
    return 0;
}