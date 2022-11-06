#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        string s;
        cin>>s;
        sort(s.begin(), s.end());
        cout<<s<<endl;
    }
    return 0;
}