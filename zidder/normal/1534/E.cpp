#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n, k;

void solve(int test_ind){
	cin >> n >> k;
    bool end = n%2 == 1;
    end &= k % 2 == 0;
    if (end) {
        cout << "-1" << endl;
        fflush(stdout);
        return;
    }
    long long ans = 0, i;
    if (n%k == 0){
        for (i=0;i<n;i+=k){
            cout << "?";
            for (int j=0;j<k;++j)
                cout << " " << i + j + 1;
            cout << endl;
            fflush(stdout);
            long long x;
            cin >> x;
            ans ^= x;
        }
        cout << "! " << ans << endl;
        fflush(stdout);
        return;
    }
    long long x;
    if (n > 2 * k){
        if (0 == (n%k+k)%2) {
            for (i=n%k+k;i<n;i+=k){
                cout << "?";
                for (int j=0;j<k;++j)
                    cout << " " << i + j + 1;
                cout << endl;
                fflush(stdout);
                cin >> x;
                ans ^= x;
            }
            int xx = n%k+k;
            cout << "?";
            for (i=0;i<xx/2;++i){
                cout << " " << i + 1;
            }
            for (i=xx/2;i<k;++i){
                cout << " " << n - (i - xx/2);
            }
            cout << endl;
            fflush(stdout);
            cin >> x;
            ans ^= x;
            cout << "?";
            for (i=xx/2;i<xx;++i){
                cout << " " << i + 1;
            }
            for (i=xx/2;i<k;++i){
                cout << " " << n - (i - xx/2);
            }
            cout << endl;
            fflush(stdout);
            cin >> x;
            ans ^= x;
            cout << "! " << ans << endl;
            return;
        }
    }
    // n < 2k || n%k+k = 1 mod 2
    if ((n%k)%2 == 0){
        while (n > 2 * k){
            cout <<"?";
            for (int j=0;j<k;++j){
                cout << " " << n - j;
            }
            cout << endl;
            fflush(stdout);
            cin >> x;
            ans ^= x;
            n -= k;
        }
        // n < 2k
        int xx = n%k;
        cout << "?";
        for (int j=0;j<xx/2;++j){
            cout << " " << j + 1;
        }
        for (int j=xx/2;j<k;++j){
            cout << " " << n - (j-xx/2);
        }
        cout<<endl;
        fflush(stdout);
        cin >> x;
        ans ^= x;
        cout << "?";
        for (int j=xx/2;j<xx;++j){
            cout << " " << j + 1;
        }
        for (int j=xx/2;j<k;++j){
            cout << " " << n - (j-xx/2);
        }
        cout<<endl;
        fflush(stdout);
        cin >> x;
        ans ^= x;
        // got also first xx
        cout << "?";
        for (int j=0;j<k;++j){
            cout << " " << n - j;
        }
        cout<<endl;
        fflush(stdout);
        cin >> x;
        ans ^= x;
        cout << "! " << ans << endl;
        fflush(stdout);
        return;
    }
    // n < 2k otherwise n%k+k or n%k is even
    // n = n%k+k is even and k is odd
    // n = n%k+k is odd and k is even XXXXXXX
    //
    // therefore n is even and k is odd
    int d = 4;
    while ((d-1)*n<d*k){
        d += 2;
    }
    int sv = d * k - n;  //even
    vector<int> v(n, 1);
    for (i=0;i<n;++i){
        if (sv <= d - 2){
            v[i] += sv;
            sv = 0; // even
        }
        else{
            v[i] = d-1;
            sv -= d-2; // even
        }
    }
    set<pair<int, int> > vals;
    for (i=0;i<n;++i){
        vals.emplace(v[i], i+1);
    }
    for (i=0;i<d;++i){
        vector<pair<int, int> > v;
        cout << "?";

        for (int j=0;j<k;++j){
            v.push_back(*vals.rbegin());
            vals.erase(v.back());
            cout << " " << v.back().second;
        }

        cout << endl;
        fflush(stdout);
        cin >> x;
        ans ^= x;

        for (int j=0;j<k;++j){
            vals.emplace(v[j].first - 1, v[j].second);
        }
    }
    cout << "! " << ans << endl;
    fflush(stdout);
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}