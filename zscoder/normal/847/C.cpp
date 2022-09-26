#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pii;

template<typename T>
using pq_gt = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using pq_lt = priority_queue<T, vector<T>, less<T>>;

#define se second
#define fi first
#define pb push_back

void printBracket(int x) {
    for(int i = 0; i < x; ++i) {
        cout<<"(";
    }
    for(int i = 0; i < x; ++i) {
        cout<<")";
    }
}

int main() {
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    if(k*2>n*n-n) {
        cout<<"Impossible\n";
        return 0;
    }
    ll sq = sqrt(2*k);
    if(sq*sq+sq>2*k) {
        sq--;
    }
    int fi = sq;
    ll rem = k-sq*(sq+1)/2;
    n-=(sq+1);
    for(int i = 0; i < sq+1; i++) {
        //n-=(sq+1);
        cout<<"(";
    }
    cout<<")";
    //cout<<n<<" "<<sq<<" "<<rem<<endl;
    for(int i = sq; i> 0; i--) {
        if(i==rem) {
            n--;
            cout<<"()";
        }
        cout<<")";
    }
    for(int i = 0; i < n; ++i) {
        cout<<"()";
    }
    cout<<endl;
    /*if(k*2>n*n-n) {
        cout<<"Impossible\n";
        return 0;
    }
    ll a,b,c;
    bool flag = false;
    for(ll i = sqrt(2*k); i>= 0; i--) {
        if(i*i+i==2*k) {
            a = i; b= 0; c = 0;
            printBracket(a+1);
            printBracket(n-a-1);
            cout<<endl;
            return 0;
        }
        ll rem = 2*k-i*i-i;
        for(ll j = 1; j*j+j<=rem; ++j) {
            ll rem1 = rem-j*j-j;
            int k = sqrt(rem1);
            if(k==0) {
                if(i+j+2<=n) {
                    printBracket(i+1);
                    printBracket(j+1);
                    for(int l = 0; l < n-i-j-2; ++l) {
                        printBracket(1);
                    }
                    cout<<endl;
                }
            }
            else if(rem1==k*k+k && i+j+k+3<=n) {
                printBracket(i+1);
                printBracket(j+1);
                printBracket(k+1);
                for(int l = 0; l < n-i-j-k-3; ++l) {
                    printBracket(1);
                }
                cout<<endl;
                return 0;
            }
            
        }
    }
    cout<<"Impossible\n";*/
}