#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
  int i, idx;
    string input;
    long long ans=0;
    vector<int>::iterator it;
    vector<int> idx1, idx2;
    cin >> input;
    
    for (i=0; i<input.length(); i++)
    {
        idx = input.find("heavy", i);
        if (idx != string::npos)
            idx1.push_back(idx);
        else break;
        i = idx+1;
    }
    
    for (i=0; i<input.length(); i++)
    {
        idx = input.find("metal", i);
        if (idx != string::npos)
            idx2.push_back(idx);
        else break;
        i = idx+1;
    }
    
    for (i=0; i<idx1.size(); i++)
    {
        it = lower_bound(idx2.begin(), idx2.end(), idx1[i]+5);
        if (it == idx2.end()) break;
        else ans += idx2.end() - it;
    }
    
    cout<<ans<<endl;
    
    return 0;
}