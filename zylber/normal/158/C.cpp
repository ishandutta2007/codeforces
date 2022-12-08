#include <iostream>
#include <string>
using namespace std;

int main()
{
    string direc="/";
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string command;
        cin >> command;
        if(command=="pwd")
        cout << direc << endl;
        else
        {
            string change;
            cin >> change;

            if(change[0]=='/')
                direc="";

                if(change!="/")
                change+="/";

                string folder="";

                for(int j=0; j<change.size(); j++)
                {
                    folder+=change[j];
                    if(change[j]=='/')
                    {
                        if(folder=="../")
                        {
                            string newdirec="";
                            int last=0;
                            for(int k=0; k<direc.size()-1; k++)
                            if(direc[k]=='/')
                            last=k;

                            for(int k=0; k<=last; k++)
                            newdirec+=direc[k];
                            direc=newdirec;
                        }
                        else
                        {
                            direc+=folder;
                        }
                        folder="";
                    }

            }
        }

    }
}