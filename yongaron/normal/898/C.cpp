#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> names;
vector<string> num[50];
vector<bool> jo[50];

int n;

bool ends_with(string value, string ending)
{
    if (ending.size() > value.size()) return false;
    return equal(ending.rbegin(), ending.rend(), value.rbegin());
}

int main()
{
    cin>>n;
    string s;
    for(int i = 0; i < n; i++)
    {
        cin>>s;
        int in = -1;
        for(int j = 0; j < names.size(); j++)
        {
            if(s == names[j])
            {
                in = j;
                break;
            }
        }
        if(in < 0)
        {
            in = names.size();
            names.push_back(s);
        }
        int k;
        cin>>k;
        //cout<<i<<endl;
        for(int j = 0; j < k; j++)
        {
            cin>>s;
            num[in].push_back(s);
            jo[in].push_back(true);
            //cout<<in<<" "<<j<<" "<<num[in].back()<<endl;
        }
    }
    //cout<<"!";
    for(int i = 0; i < names.size(); i++)
    {
        for(int j = 0; j < num[i].size(); j++)
        {
            for(int l = 0; l < num[i].size(); l++)
            {
                if(j == l)
                    continue;
                if(jo[i][j])
                {
                    if(ends_with(num[i][j], num[i][l]))
                        jo[i][l] = false;
                }
            }
        }
    }
    //cout<<"!"<<endl;
    cout<<names.size()<<endl;
    for(int i = 0; i < names.size(); i++)
    {
        cout<<names[i]<<" ";
        int x = 0;
        for(int j = 0; j < jo[i].size(); j++)
        {
            if(jo[i][j])
                x++;
        }
        cout<<x<<" ";
        for(int j = 0; j < jo[i].size(); j++)
        {
            if(jo[i][j])
                cout<<num[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}