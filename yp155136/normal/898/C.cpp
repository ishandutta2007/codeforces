#include <bits/stdc++.h>
using namespace std;

const int N = 106;

vector<string> v[N];
string names[N];

bool kirino(string a,string b)
{
    //if b is a's suffix, return true
    if (a.size() < b.size()) return false;
    int a_pos = a.size()-1,b_pos = b.size()-1;
    while (b_pos != -1)
    {
        if (a[a_pos] != b[b_pos]) return false;
        b_pos--;
        a_pos--;
    }
    //cout << a<<" beats " << b<<endl;
    return true;
}

void doo(vector<string> &v)
{
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    vector<string> ret;
    for (int i=0;v.size()>i;i++)
    {
        bool can=true;
        for (int j=0;v.size()>j;j++)
        {
            if (v[j] == v[i] && i!=j) assert(0);
            if (i != j) can &= (!kirino(v[j],v[i]) );
        }
        if (can) ret.push_back(v[i]);
    }
    v = ret;
}

int main ()
{
    int n;
    cin >> n;
    map<string,int> mp;
    int id=0;
    while (n--)
    {
        string s;
        cin >> s;
        int ret = mp[s];
        if (ret == 0)
        {
            mp[s] = (++id);
            ret = id;
        }
        names[ret] = s;
        int k;
        cin >> k;
        while (k--)
        {
            string s;
            cin >> s;
            v[ret].push_back(s);
        }
    }
    cout << id << endl;
    for (int i=1;id>=i;i++)
    {
        doo(v[i]);
        cout << names[i] << ' ' <<v[i].size();
        for (string s:v[i]) cout << ' ' << s;
        cout<<endl;
    }
}