#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class employee
{
public:
    int employeeid;
    char name[50];
    char post[50];
    float salary;
private:
    char lastname[50];
public:
    void accept()
    {
        cout<<endl<<"ENTER EMPLOYEE ID-->";
        cin>>employeeid;
        cout<<endl<<"ENTER FIRST NAME-->";
        cin>>name;
        cout<<endl<<"ENTER LAST NAME-->";
        cin>>lastname;
        cout<<endl<<"ENTER THE SALARY-->";
        cin>>salary;
        cout<<endl<<"ENTER POST-->";
        cin>>post;
    }
    void display()
    {
       /* cout<<endl<<"EMPLOYEE ID : "<<employeeid;
        cout<<endl<<"EMPLOYEE NAME : "<<name;
        cout<<endl<<"EMPLOYEE LAST NAME : "<<lastname;
        cout<<endl<<"SALARY : "<<salary;
        cout<<endl<<"POST : "<<post;
        cout<<endl<<"*************************************************************************";*/
        cout<<endl<<"EMP_ID  "<<"   "<<"NAME"<<"\t\t"<<"SALARY"<<"\t"<<"POST";
        cout<<endl<<employeeid<<"\t"<<name<<" "<<lastname<<"\t"<<salary<<"\t"<<post;
            }

};
employee obj;

class salary
{
private:
    int employeeid;
    float salary_given;
public:
    char month[50];
    char year[4];
    void accept()
    {
        cout<<endl<<"ENTER EMPLOYEE ID : ";
        cin>>employeeid;

        fstream rd;
        rd.open("f:\\salaryproject\\employeedata.txt",ios::in);

        rd.seekg(0,ios::end);
        int n=rd.tellg();
        n=n/sizeof(obj);

        rd.seekg(0,ios::beg);
        for(int i=1;i<=n;i++)
        {
            rd.read((char*)&obj,sizeof(obj));
            if(employeeid==obj.employeeid)
            {
                obj.display();
            }
        }
        cout<<endl<<"ENTER SALARY TO BE DISPENSED : ";
        cin>>salary_given;
        cout<<endl<<"ENTER MONTH : ";
        cin>>month;
        cout<<endl<<"ENTER YEAR : ";
        cin>>year;
    }
    int digit(int n)
    {
        int count=0;
        while(n!=0)
        {
            n=n/10;
            count++;
        }
        return count;
    }
    void display()
    {
        cout<<endl<<"EMPLOYEE ID : "<<employeeid;
        cout<<endl<<"SALARY GIVEN : "<<salary_given;
        cout<<endl<<"MONTH : "<<month;
        cout<<endl<<"YEAR : "<<year;

        /*cout<<"EMPLOYEE ID\t\tSALARY GIVEN\t\tMONTH\t\tYEAR"<<endl;
        cout<<employeeid;
        cout<<"\t\t\t"<<salary_given;
        cout<<"\t\t\t"<<month;
        cout<<"\t\t"<<year;*/
        /*cout<<"employee ID";
        cout<<endl<<employeeid<<"\t\t    ";
        cout<<"SALARY GIVEN";
        cout<<salary_given;
        int p=digit(salary_given);
        for(int i=1;i<=(12-p);i++)
        {
            cout<<" ";
        }
        cout<<"\t"<<month<<"\t"<<year;*/
        /*cout<<endl<<"EMP_ID  "<<"   "<<"NAME"<<"\t\t"<<"SALARY GIVEN"<<"\t"<<"POST";
        cout<<endl<<employeeid<<"\t"<<name<<" "<<lastname<<"\t"<<salary_given<<"\t"<<post;*/


    }
};
salary salobj;

void dispensesalary()
{
    salobj.accept();
    fstream wr;
    wr.open("f:\\salaryproject\\salary.txt",ios::app);
    wr.write((char*)&salobj,sizeof(salobj));
    cout<<endl<<"SALARY RECORDED";
    //salobj.display();
}
void searchsalary()
{
    fstream rd;
    rd.open("f:\\salaryproject\\salary.txt",ios::in);

    char m[50],y[50];
    cout<<endl<<"Enter Month : ";
    cin>>m;
    cout<<endl<<"Enter Year : ";
    cin>>y;
    cout<<endl;

    rd.seekg(0,ios::end);
    int n=rd.tellg()/sizeof(salobj);

    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&salobj,sizeof(salobj));
        if(strcmp(salobj.month,m)==0 && strcmp(salobj.year,y)==0)
        {
            salobj.display();
        }
    }
}

void addemployee()
{
    obj.accept();
    fstream wr;
    wr.open("F:\\salaryproject\\employeedata.txt",ios::app);//in future use ios::app instead of ios::in to save the previous data
    wr.write((char*)&obj,sizeof(obj));
    cout<<endl<<"data written to file";
    obj.display();
}
void showallemployee()
{
    fstream rd;
    rd.open("F:\\salaryproject\\employeedata.txt",ios::in);
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);//doubt

    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {
            rd.read((char*)&obj,sizeof(obj));
            obj.display();
            cout<<endl<<"**************************************************************"<<endl;
    }

}
void searchbyempid()
{
    fstream rd;
    rd.open("f:\\salaryproject\\employeedata.txt",ios::in);

    int id;
    cout<<endl<<"ENTER EMPLOYEE ID TO BE SEARCHED : "<<endl;
    cin>>id;

    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);

    rd.seekg(0,ios::beg);
    for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(obj.employeeid==id)
        {
            obj.display();
            cout<<endl<<"*****************************************************"<<endl;
        }
    }
   /* if(obj.employeeid!=sr)
    {
        cout<<endl<<"no such employee registered with the firm";
    }*/
}

    /*int p=0;
    rd.seekg(0,ios::beg);
  for(int i=1;i<=n;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(obj.employeeid==sr)
        {
            p=1;
        }
        break;
    }
    if(p==1)
    {
        obj.display();
        cout<<endl<<"*******************************************************"<<endl;
    }
    else
    {
        cout<<endl<<"no such employee registered with the firm";
    }
}*/
void searchbyname()
{
    int x;
    fstream rd;
    rd.open("f:\\salaryproject\\employeedata.txt",ios::in);

    char nm[50];
    cout<<endl<<"enter employee's first name to be searched : "<<endl;
    cin>>nm;

    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);

    rd.seekg(0,ios::beg);
    for(int j=1;j<=n;j++)
    {
        rd.read((char*)&obj,sizeof(obj));
        x=stricmp(nm,obj.name);
        if(x==0)

        {
            obj.display();
            cout<<endl<<"*****************************************************************************"<<endl;
        }
    }

}
void searchbypost()
{int x;
fstream rd;
rd.open("f:\\salaryproject\\employeedata.txt",ios::in);

char po[50];
cout<<endl<<"enter the post to be searched"<<endl;
cin>>po;

rd.seekg(0,ios::end);
int n=rd.tellg();
n=n/sizeof(obj);
rd.seekg(0,ios::beg);
for(int k=1;k<=n;k++)
{
    rd.read((char*)&obj,sizeof(obj));
    x=strcmp(po,obj.post);
    if(x==0)
    {
        obj.display();
        cout<<endl<<"**********************************************************"<<endl;
    }
}
}
void searchbysalary()
{
    fstream rd;
    rd.open("f:\\salaryproject\\employeedata.txt",ios::in);

    int sa;
    cout<<endl<<"enter the salary amount to search all the employees getting that much salary"<<endl;
    cin>>sa;

    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);

    rd.seekg(0,ios::beg);
    for(int l=1;l<=n;l++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(obj.salary==sa)
        {
            obj.display();
            cout<<endl<<"*************************************************************************************"<<endl;
        }
    }
}
void removeemployee()
{
    fstream rd,wr;
    rd.open("f:\\salaryproject\\employeedata.txt",ios::in);
    wr.open("f:\\salaryproject\\temp.txt",ios::out);

    int id;
    cout<<endl<<"ENTER THE EMPLOYEE ID TO BE REMOVED : ";
    cin>>id;

    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);

    rd.seekg(0,ios::beg);
    for(int m=1;m<=n;m++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(obj.employeeid==id)
        {
            cout<<endl<<"Employee Removed"<<endl;
        }
        else
        {
            wr.write((char*)&obj,sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("f:\\salaryproject\\employeedata.txt");
    rename("f:\\salaryproject\\temp.txt","f:\\salaryproject\\employeedata.txt");
}
void updateemployee()
{
    fstream rd,wr;
    rd.open("f:\\salaryproject\\employeedata.txt",ios::in);
    wr.open("f:\\salaryproject\\temp.txt",ios::out);

    int id;
    cout<<endl<<"enter the employee ID to be updated";
    cin>>id;

    rd.seekg(0,ios::end);
    int n=rd.tellg();
    n=n/sizeof(obj);

    rd.seekg(0,ios::beg);
    for(int o=1;o<=n;o++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if(obj.employeeid==id)
        {
            obj.accept();
            wr.write((char*)&obj,sizeof(obj));
        }
        else
        {
            wr.write((char*)&obj,sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("f:\\salaryproject\\employeedata.txt");
    rename("f:\\salaryproject\\temp.txt","f:\\salaryproject\\employeedata.txt");
}

main()
{   int e=0;
    while(e!=1)
    {
        cout<<endl<<"\t\t************************************************";
        cout<<endl<<"\t\t**  enter 1 to add new record\t\t      **"<<endl;
        cout<<"\t\t**  enter 2 to show the record of all employee**"<<endl;
        cout<<"\t\t**  enter 3 to search by employee id\t      **"<<endl;
        cout<<"\t\t**  enter 4 to search by name\t\t      **"<<endl;
        cout<<"\t\t**  enter 5 to search by post\t\t      **"<<endl;
        cout<<"\t\t**  enter 6 to search by salary\t\t      **"<<endl;
        cout<<"\t\t**  enter 7 to remove employee\t\t      **"<<endl;
        cout<<"\t\t**  enter 8 to update employee\t\t      **"<<endl;
        cout<<"\t\t**  enter 9 to dispense salary\t\t      **"<<endl;
        cout<<"\t\t**  enter 10 to search salary given\t      **"<<endl;
        cout<<"\t\t**  enter 11 to exit\t\t\t      **"<<endl;
        cout<<"\t\t************************************************";
        //cout<<"\t**********************************************";

        int choice;
        cout<<endl<<"\t\tEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                addemployee();
                break;
            }
        case 2:
            {
                showallemployee();
                break;
            }
        case 3:
            {
                searchbyempid();
                break;
            }
        case 4:
            {
                searchbyname();
                break;
            }
        case 5:
            {
                searchbypost();
                break;
            }
        case 6:
            {
                searchbysalary();
                break;
            }
        case 7:
            {
                removeemployee();
                break;
            }
        case 8:
            {
                updateemployee();
                break;
            }
        case 9:
            {
                dispensesalary();
                break;
            }
        case 10:
            {
                searchsalary();
                break;

            }
        case 11:
            {
                e=1;
            }


        }
       // e=1;
    }
    //addemployee();
   //showallemployee();
   //searchbyempid();
   //searchbypost();
   //searchbysalary();
   //removeemployee();
   //updateemployee();
   //dispensesalary();
   //searchsalary();
}
