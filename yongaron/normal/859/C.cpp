#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> kolac;
vector<pair<int, int> > alice;
vector<pair<int, int> > bob;

int main()
{
    int a;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a;
        kolac.push_back(a);
    }
    alice.push_back(make_pair(0, 0));
    bob.push_back(make_pair(0, 0));
    for(int i = n-1; i >= 0; i--)
    {


        if(kolac[i]+alice.back().second > bob.back().second)
            bob.push_back(make_pair(alice.back().first, kolac[i]+alice.back().second));
        else
            bob.push_back(make_pair(bob.back().first+kolac[i], bob.back().second));
        if(kolac[i]+bob[bob.size()-2].first > alice.back().first)
            alice.push_back(make_pair(bob[bob.size()-2].first+kolac[i], bob[bob.size()-2].second));
        else
            alice.push_back(make_pair(alice.back().first, alice.back().second+kolac[i]));
    }
    cout<<bob.back().first<<" "<<bob.back().second<<endl;
    return 0;
}