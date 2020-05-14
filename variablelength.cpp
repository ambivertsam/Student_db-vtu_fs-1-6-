#include<iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

char fname[20]="Experimental2.txt";
struct record
{
    char name[20];
    char usn[15],age[5],sem[5],branch[10];
};
class student
{
    public:void pack(record r);
    record unpack(char a[]);
    void writedata();
    void display();
    void search1();
    void modify();
};
void student::pack(record r)
{
    fstream fp;
    fp.open(fname,ios::out|ios::app);
    if(fp.eof())
    {
        cout<<"\nCannot open file";
        exit(0);
    }
    char buff[45];
    strcpy(buff,r.name);
    strcat(buff,"|");
    strcat(buff,r.usn);
    strcat(buff,"|");
    strcat(buff,r.age);
    strcat(buff,"|");
    strcat(buff,r.sem);
    strcat(buff,"|");
    strcat(buff,r.branch);
    strcat(buff,"|*");
    fp<<buff<<endl;
    fp.close();
}
record student::unpack(char buff[])
{
    record r;
    int i=0,j=0;
    while(buff[j]!='|')
        r.name[i++]=buff[j++];

        r.name[i]='\0';
        i=0;
        j++;
        while(buff[j]!='|')
            r.usn[i++]=buff[j++];
        r.usn[i]='\0';
        i=0;j++;
        while(buff[j]!='|')

            r.age[i++]=buff[j++];

        r.age[i]='\0';
        i=0;j++;
        while(buff[j]!='|')
            r.sem[i++]=buff[j++];
        r.sem[i]='\0';
        i=0;
        j++;
        while(buff[j]!='|')
            r.branch[i++]=buff[j++];
        r.branch[i]='\0';
        return(r);
    }
    void student::writedata()
    {
        record r;
        cout<<"\nEnter Name:";
        cin>>r.name;
        cout<<"\nEnter Usn:";
        cin>>r.usn;
        cout<<"\nEnter Age:";
        cin>>r.age;
        cout<<"\nEnter Semester:";
        cin>>r.sem;
        cout<<"\nEnter branch:";
        cin>>r.branch;
        pack(r);
    }
    void student::display()
    {
        fstream fp;
        char buff[45];
        record r;
        fp.open(fname,ios::in);
        if(fp.eof())
        {
            cout<<"\nCannot open file";
            exit(0);
        }
        cout<<"\n#\tNAME\t     USN    \tAGE\tSEM\tBRANCH\n";
        int c=1;
        char arr1[20];
        while(1)
        {
            fp.getline(buff,45,'*');
            if(fp.eof())
                break;
            r=unpack(buff);
            cout<<c++<<"\t"<<r.name<<"\t"<<r.usn<<"\t"<<r.age<<"\t"<<r.sem<<"\t"<<r.branch<<endl;
        }
        fp.close();
        return;
    }
    void student::modify()
    {
        fstream fp;
        char usn[15],buff[45];
        int i,j;
        record s[100];
        fp.open(fname,ios::in);
        if(fp.eof())
        {
            cout<<"\nCannot open file";
            exit(0);
        }
        cout<<"\nEnter the USN to be modified:";
        cin>>usn;
        i=0;
        while(1)
        {
            fp.getline(buff,45,'*');
            if(fp.eof())
                break;
            s[i]=unpack(buff);
            i++;
        }
        for(j=0;j<i;j++)
        {
            if(strcmp(s[j].usn,usn)==0)
            {
                cout<<"\nValues of the record are:\n";
                cout<<"\nNAME:"<<s[j].name;
                cout<<"\nUSN:"<<s[j].usn;
                cout<<"\nSEM:"<<s[j].sem;
                cout<<"\nAGE:"<<s[j].age;
                cout<<"\nBRANCH:"<<s[j].branch;
                cout<<"\nENTER THE NEW VALUES:\n";
                cout<<"\nNAME:";
                cin>>s[j].name;
                cout<<"\nUSN:";
                cin>>s[j].usn;
                cout<<"\nSEM:";
                cin>>s[j].sem;
                cout<<"\nAGE:";
                cin>>s[j].age;
                cout<<"\nBRANCH:";
                cin>>s[j].branch;
                break;

            }
        }
        if(j==i)
        {
            cout<<"\nRECORD NOT FOUND";
            return;
        }
        fp.close();
        fstream fd;
        fd.open(fname,ios::out|ios::trunc);
        if(fd.eof())
        {
            cout<<"\nCannot open file";
            exit(0);
        }
        for(j=0;j<i;j++)
            pack(s[j]);
        fd.close();
    }
    void student::search1()
    {
        fstream fp;
        char usn[15],buff[45];
        int i,j;
        record s;
        fp.open(fname,ios::in);
        if(fp.eof())
        {
            cout<<"\nCannot open file";
            exit(0);
        }
        cout<<"\nEnter the usn to be searched:";
        cin>>usn;
        i=0;
        while(1)
        {
            fp.getline(buff,45,'*');
            if(fp.eof())
                break;
            s=unpack(buff);
            if(strcmp(s.usn,usn)==0)
            {
                cout<<"\nRECORD FOUND\n";
                cout<<"\nNAME :"<<s.name;
                cout<<"\nUSN :"<<s.usn;
                cout<<"\nSEM :"<<s.sem;
                cout<<"\nAGE :"<<s.age;
                cout<<"\nBRANCH:"<<s.branch;
                return;
            }
        }
        cout<<"\n RECORD NOT FOUND";
        return;
    }
    int main()
    {
        int ch;
        student obj;
        cout<<"1.write data\n 2.display\n 3.search\n 4.modify\n 5.exit";
        while(1)
        {
            cout<<"\nEnter YOUR CHOICE:";
            cin>>ch;
            switch(ch)
            {
                case 1:obj.writedata();
                break;
                case 2:obj.display();
                break;
                case 3:obj.search1();
                break;
                case 4:obj.modify();
                break;
                default:exit(0);
            }
        }
    }

