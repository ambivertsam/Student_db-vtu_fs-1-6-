#include<fstream>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<stdio.h>
//#include<bits/stdc++.h>
#define size 50
using namespace std;
int count1=-1;
class rrn
{
    struct student
    {
        char usn[15],name[15],sem[5];
    };
public:
    void pack();
    void unpack();
};
void rrn::pack()
{
    char buffer[size];
    student s;
    cout<<"Enter details:USN,NAME,SEM\n";
    cin>>s.usn>>s.name>>s.sem;
    ofstream ofile;
    if(count1==-1)
        ofile.open("stud2.txt",ios::out);
    else
        ofile.open("stud2.txt",ios::app);
    sprintf(buffer,"%s|%s|%s$",s.usn,s.name,s.sem);
    ofile<<buffer;
    count1++;
    ofile.close();
}
void rrn::unpack()
{
    int n,x=-1;
    char temp[100];
    A:cout<<"\nEnter rrn:";
    cin>>n;
    if(n>count1)
    {
        cout<<"\nRecord does not exists to go back press-1\n";
        goto A;
    }
    student s;
    ifstream ifile;
    ifile.open("stud2.txt",ios::in);
    while(x!=(n-1))
    {
        ifile.getline(temp,80,'$');
        x++;
    }
    if(x==n-1)
    {

        ifile.getline(s.usn,80,'|');
        ifile.getline(s.name,80,'|');
        ifile.getline(s.sem,80,'$');
        cout<<s.usn<<"\t"<<s.name<<"\t"<<s.sem;
    }
    ifile.close();
}
int main()
{
    int ch;
    rrn r;
    while(1)
    {
        cout<<"\n 1:insert\n2:Search by rrn(from 0)\n#:exit\n";
        cout<<"Enter the choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:r.pack();
            break;
            case 2:r.unpack();
            break;
            case3:exit(0);
            default:cout<<"Invalid choice\n";
            break;
        }
    }
    return 0;
}
