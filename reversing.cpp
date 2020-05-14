#include<iostream>
#include<fstream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
string strrev(string str)
{
    string str1;
    for(int i=str.length()-1;i>=0;i--)
    {
        str1=str1+str[i];
    }
    return str1;
}
string Encrypt(string str)
{
    int ch;
    char str2;
    string str1;
    for(int i=0;i<str.length();i++)
    {
        ch=(int)str[i];
        ch=ch+20;
        str2=(char)ch;
        str1=str1+str2;
    }
    return str1;
}
int main()
{
    int ch;
    fstream fp,fp1;
    string name[5];
    char filename[20],str[50],filename1[20];
    string name1;
    for(;;)
    {
        cout<<"1:Standard input to standard output\n 2:File to standard Output\n 3:file to file\n 4:quit"<<"\n";
            cin>>ch;
            switch(ch)
            {
            case 1:
                cout<<"Enter 5 names\n";
                for(int i=0;i<=4;i++)
                {
                getline(cin,name[i]);
                }
                for(int i=0;i<=4;i++)
                {
                    name1=strrev(name[i]);
                    cout<<name1<<endl;
                }
                break;
            case 2:
                cout<<"Enter i/p filename with names"<<"\n";
                cin>>filename;
                fp.open(filename,ios::in);
                if(fp.fail())
                {
                    cout<<"Cannot open file\n";
                }
                while(1)
                {
                    fp>>str;
                    cout<<str<<"\n";
                    if(fp.eof())
                    {
                        break;
                    }
                }
                    fp.close();
                    break;
            case 3:
                cout<<"Enter i/p filenames\n";
                cin>>filename;
                cout<<"Enter o/p filename\n";
                cin>>filename1;
                fp.open(filename,ios::in);
                fp1.open(filename1,ios::out);
                if(fp.fail()||fp1.fail())
                {
                    cout<<"Cannot open the file"<<"\n";
                    exit(0);
                }
                while(1)
                {
                    fp>>str;
                    cout<<str<<"\t";
                    fp1<<Encrypt(str)<<"\n";
                    if(fp.eof())
                    {
                        break;
                    }
                }
                fp.close();
                fp1.close();
                break;
                default:exit(0);
                }
            }
    }


