#include <iostream>
#include <vector>
using namespace std;
string s;
int ha[15][35];
int ne[15][35];
int ot[15][35];
bool szam(char w)
{
    if('0'<=w && w<='9')
    {
        return true;
    }
    return false;
}
int main()
{
    cin>>s;
    for(int i=0; i<=s.size()-10; i++)
    {
        if(!(s[i+2]=='-' && s[i+5]=='-'))
        {
            continue;
        }
        int d, m, y;
        if(!szam(s[i]))
        {
            continue;
        }
        else
        {
            d=s[i]-'0';
        }
        if(!szam(s[i+1]))
        {
            continue;
        }
        else
        {
            d*=10;
            d+=s[i+1]-'0';
        }

        if(!szam(s[i+3]))
        {
            continue;
        }
        else
        {
            m=s[i+3]-'0';
        }
        if(!szam(s[i+4]))
        {
            continue;
        }
        else
        {
            m*=10;
            m+=s[i+4]-'0';
        }





        if(!szam(s[i+6]))
        {
            continue;
        }
        else
        {
            y=s[i+6]-'0';
        }
        if(!szam(s[i+7]))
        {
            continue;
        }
        else
        {
            y*=10;
            y+=s[i+7]-'0';
        }
        if(!szam(s[i+8]))
        {
            continue;
        }
        else
        {
            y*=10;
            y+=s[i+8]-'0';
        }
        if(!szam(s[i+9]))
        {
            continue;
        }
        else
        {
            y*=10;
            y+=s[i+9]-'0';
        }






        if(m==1)
        {
            if(d<1 or d>31)
            {
                continue;
            }
        }
        else if(m==2)
        {
            if(d<1 or d>28)
            {
                continue;
            }
        }
        else if(m==3)
        {
            if(d<1 or d>31)
            {
                continue;
            }
        }
        else if(m==4)
        {
            if(d<1 or d>30)
            {
                continue;
            }
        }
        else if(m==5)
        {
            if(d<1 or d>31)
            {
                continue;
            }
        }
        else if(m==6)
        {
            if(d<1 or d>30)
            {
                continue;
            }
        }
        else if(m==7)
        {
            if(d<1 or d>31)
            {
                continue;
            }
        }
        else if(m==8)
        {
            if(d<1 or d>31)
            {
                continue;
            }
        }
        else if(m==9)
        {
            if(d<1 or d>30)
            {
                continue;
            }
        }
        else if(m==10)
        {
            if(d<1 or d>31)
            {
                continue;
            }
        }
        else if(m==11)
        {
            if(d<1 or d>30)
            {
                continue;
            }
        }
        else if(m==12)
        {
            if(d<1 or d>31)
            {
                continue;
            }
        }
        else
        {
            continue;
        }



        if(y==2013)
        {
            ha[m][d]++;
        }
        else if(y==2014)
        {
            ne[m][d]++;
        }
        else if(y==2015)
        {
            ot[m][d]++;
        }
        else
        {
            continue;
        }
    }
    vector<char> f;
    int maxi=0;
    for(int i=0; i<=13; i++)
    {
        for(int j=0; j<=33; j++)
        {
            if(ha[i][j]>maxi)
            {
                maxi=ha[i][j];
                f.clear();
                f.push_back(j/10+'0');
                f.push_back(j%10+'0');
                f.push_back('-');
                f.push_back(i/10+'0');
                f.push_back(i%10+'0');
                f.push_back('-');
                f.push_back('2');
                f.push_back('0');
                f.push_back('1');
                f.push_back('3');
            }
            if(ne[i][j]>maxi)
            {
                maxi=ne[i][j];
                f.clear();
                f.push_back(j/10+'0');
                f.push_back(j%10+'0');
                f.push_back('-');
                f.push_back(i/10+'0');
                f.push_back(i%10+'0');
                f.push_back('-');
                f.push_back('2');
                f.push_back('0');
                f.push_back('1');
                f.push_back('4');
            }
            if(ot[i][j]>maxi)
            {
                maxi=ot[i][j];
                f.clear();
                f.push_back(j/10+'0');
                f.push_back(j%10+'0');
                f.push_back('-');
                f.push_back(i/10+'0');
                f.push_back(i%10+'0');
                f.push_back('-');
                f.push_back('2');
                f.push_back('0');
                f.push_back('1');
                f.push_back('5');
            }
        }
    }
    for(int i=0; i<f.size(); i++)
    {
        cout<<f[i];
    }
    return 0;
}