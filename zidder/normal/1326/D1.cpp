#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define ll long long
using namespace std;

void solve(int test_ind){
    string s, s1;
    cin >> s;
    s1 = s;
    int i, j;
    for (i=0, j=s.size()-1;i<=j && s[i]==s[j];i++,j--);
    reverse(s1.begin(), s1.end());
    if (s==s1){
        cout << s << endl;
        return;
    }
    ll p = 31, mod = 1000000007, pp = 1;
    ll h1 = 0, h2 = 0;
    int maxk = i;
    for(int k=i;k<j;k++){
        ((h1 *= p) += (s[k] - 'a')) %= mod;
        (h2 += (s[k] - 'a') * pp % mod) %= mod;
        (pp *= p) %= mod;
        if (h1 == h2)
            maxk = k;
    }
    string t1="", t2="";
    for(int k=0;k<=maxk;k++)
        t1+=s[k];
    for(int k=j+1;k<s.size();++k)
        t1+=s[k];
    pp = 1;
    h1 = 0;
    h2 = 0;
    int mink = j;
    for(int k=j;k>i;k--){
        ((h1 *= p) += (s[k] - 'a')) %= mod;
        (h2 += (s[k] - 'a') * pp % mod) %= mod;
        (pp *= p) %= mod;
        if (h1 == h2)
            mink = k;
    }
    for(int k=0;k<i;k++)
        t2+=s[k];
    for(int k=mink;k<s.size();++k)
        t2+=s[k];
    if(t1.size() < t2.size())
        t1 = t2;
    cout << t1 << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}