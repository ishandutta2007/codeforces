#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

#define ll long long

using namespace std;

int n, t;

int a[1234];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        set<int> s;
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
            for(int j = 0; j < i; j++)
                s.insert(a[i]-a[j]);
        }
        cout<<s.size()<<endl;
    }
    return 0;
}