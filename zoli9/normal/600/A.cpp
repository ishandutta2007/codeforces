#include <bits/stdc++.h>
using namespace std;
string s;
vector<vector<char> > szoveg;
vector<vector<char> > szam;
vector<char> cv;
void betesz(vector<char> c)
{
    bool szame=true;
    if(c.size()==0) szame=false;
    else
    {
        if(c[0]=='0' && c.size()>1) szame=false;
        else
        {
            for(int i=0; i<c.size(); i++)
            {
                if(!('0'<=c[i] && c[i]<='9')) szame=false;
            }
        }
    }
    if(szame) szam.push_back(c);
    else szoveg.push_back(c);
}
int main()
{
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==';' || s[i]==',')
        {
            betesz(cv);
            cv.clear();
        }
        else
        {
            cv.push_back(s[i]);
        }
    }
    betesz(cv);
    if(szam.size()==0)
    {
        cout<<"-"<<endl;
    }
    else
    {
        cout<<"\"";
        for(int i=0; i<szam.size()-1; i++)
        {
            for(int j=0; j<szam[i].size(); j++)
            {
                cout<<szam[i][j];
            }
            cout<<",";
        }
        for(int j=0; j<szam[szam.size()-1].size(); j++)
        {
            cout<<szam[szam.size()-1][j];
        }
        cout<<"\""<<endl;
    }
    if(szoveg.size()==0)
    {
        cout<<"-"<<endl;
    }
    else
    {
        cout<<"\"";
        for(int i=0; i<szoveg.size()-1; i++)
        {
            for(int j=0; j<szoveg[i].size(); j++)
            {
                cout<<szoveg[i][j];
            }
            cout<<",";
        }
        for(int j=0; j<szoveg[szoveg.size()-1].size(); j++)
        {
            cout<<szoveg[szoveg.size()-1][j];
        }
        cout<<"\"";
    }
    return 0;
}