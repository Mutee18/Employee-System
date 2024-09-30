#include<iostream>
    using namespace std;
    
    class Subemployee
    {
      private:
      public:
      static Subemployee& getInstance()
      {
        static Subemployee instance;
        return instance;
      }
      void addToHierarchy(int ID, string name, string Designation)
      {
        cout<<" Employee added to hierarchy : "<<name<<endl;
      }
      void removeFromHierarchy(int ID)
      {
        cout<<" Employee removed from hierarchy "<<endl;
      }
    };
    class Designation
    {
      private:
      public:
      static Designation& getInstance()
      {
        static Designation instance;
        return instance;
      }
      void addDesignation(int ID, string Designation)
      {
        cout<<" Designation added :"<<Designation;
      }
      void removeDesignation(int ID)
      {
         cout<<" Designation added :";
      }
    };
    struct EmployeeNode
    {
      int ID;
      string name;
      string Designation;
      EmployeeNode *next;
      EmployeeNode(int id, string name, string designation) : ID(id), name(name), Designation(designation), next(nullptr) {}
    };
    class Company
    {
      private:
      EmployeeNode*head;
      int EmpCount;
      public:
      Company() : head(nullptr), EmpCount(0) {}
      void addEmployee(int ID, string name, string Designation)
      {
      EmployeeNode * newEmployee=new EmployeeNode(ID, name, Designation);
      newEmployee ->next=head;
      head= newEmployee;
      EmpCount ++;
      cout<<" Employee added : "<<name<<endl;
      Subemployee::getInstance().addToHierarchy(ID,name,Designation);
      Designation::getInstance().addDesignation(ID, Designation);
      }
      void removeEmployee(int ID)
      {
        EmployeeNode*temp=head, *prev=nullptr;
        if(temp!=nullptr && temp ->ID==ID)
        {
           head= temp ->next;
           delete temp;
           EmpCount--;
           Subemployee::getInstance().removeFromHierarchy(ID);
           Designation::getInstance().removeDesignation(ID);
           cout<<" Employee removed.\n";
           return ;
        }
        while(temp!=nullptr && temp->ID!=ID)
        {
        prev=temp;
        temp=temp ->next;
        }
        if(temp==nullptr)
      {
      return;
      }
      prev ->next= temp ->next;
      delete temp;
      EmpCount --;
      Subemployee :: getInstance().removeFromHierarchy(ID);
      Designation :: getInstance().removeDesignation(ID);
    }
    void displayEmployees()
    {
      EmployeeNode *temp=head;
      while(temp!=nullptr)
      {
        cout<<" ID :"<<temp ->ID<<", name :"<<temp ->name<<", Designation :"<<temp ->Designation<<endl;
        temp = temp ->next;
      }
    }
    };
    Company company;
    
    int main()
    {
      company.addEmployee(18, "Virat", "GOAT");
      company.addEmployee(45, "Rohit", " Captain");
      cout<<"\n Displaying employees.\n";
      company.displayEmployees();
      company.removeEmployee(18);
      cout<<"\n Employees after removing.\n";
      company.displayEmployees();
      return 0;
    }