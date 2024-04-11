#include <iostream>
#include <cmath>

using namespace std;

int main () {
    int n;
    int s;
    int counts[4];
    int ans=0;

    for(int i=0; i<4; i++) {
        counts[i]=0;
    }

    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> s;
        counts[s-1]++;        
    }    
    
    ans += counts[3];
    counts[3] = 0;
    
    ans += counts[2];
    if(counts[0]>counts[2]) {
        counts[0]-=counts[2];
    } else {
        counts[0]=0;
    }
    counts[2]=0;

    if(counts[1] % 2 == 1) {
        ans += (counts[1] + 1)/2;
        if(counts[0]>2) {
            counts[0]-=2;
        } else {
            counts[0]=0;
        }
    } else {
        ans += counts[1]/2;
    }
        
    ans += ceil(counts[0]/4.0);
    
    cout << ans;
    
    cout << endl;

}