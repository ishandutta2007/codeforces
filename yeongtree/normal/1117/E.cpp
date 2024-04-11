#include <iostream>
#include <string>

using namespace std;

int main()
{
    string des; cin >> des;

    int n = des.size();
    int arr[n]; for(int i = 0; i < n; ++i) arr[i] = i;
    int ans[n]{};
    int pow[3] = {1, 26, 676};

    for(int i = 0; i < 3; ++i)
    {
        cout << "? ";
        for(int j = 0; j < n; ++j)
        {
            cout << (char)(arr[j] % 26 + 97);
            arr[j] /= 26;
        }
        cout << endl;

        string ret; cin >> ret;
        if(ret == "0") return 0;
        for(int j = 0; j < n; ++j)
            ans[j] += ((int)ret[j] - 97) * pow[i];
    }

    string ori(des);
    for(int i = 0; i < n; ++i)
        ori[ans[i]] = des[i];
    cout << "! " << ori << endl;

    return 0;
}