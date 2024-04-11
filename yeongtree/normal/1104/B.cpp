#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string ori; cin >> ori;
    vector<char> read{ori[0]};
    int ans = 0;
    int ori_size = ori.size();

    for(int i = 1; i < ori_size; ++i)
    {
        if(read[read.size() - 1] == ori[i]) {read.pop_back(); ++ans;}
        else read.push_back(ori[i]);
    }

    cout << ((ans%2) ? "Yes" : "No") << endl;
    return 0;
}