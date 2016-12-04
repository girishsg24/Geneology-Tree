#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;
int _print=0,_level=0;

Person::Person():level(0),name(""){};
Person::Person(int level, string name):level(level),name(name){};
Person::Person(int level, string name, string spouse):level(level),name(name),spouse_name(spouse){};
/**
 * Destructor
 */
Person::~Person()
{
    
    if(parent!=nullptr)
        parent->children.erase( parent->children.begin());
}

/**
 * Have a child.
 * @param child pointer to the new child.
 */
void Person::have_child(Person *child)
{
    
    children.push_back(child);
    child->parent=this;
}

/**
 * Print a person.
 */
void Person::print()const
{
  
        if (_print==0)
            {
                cout<<name;
                if(spouse_name!="") 
                   { cout<<" ("+spouse_name+")"<<endl;}
                _print++;
                
            }
        if (children.size()==1)
         {
            _level=level;
            print_bar(); 
            if (level==0)
            cout<<"+---";
            else if ((level==1) and (children[0]->spouse_name!=""))
            cout<<"    +---";
            else if (level==1)
            cout<<"   +---";
            else if(level==2 && children[0]->name.length()==3)
            cout<<"   +---";
             else if (level==2)
            cout<<"        +---";
        
            if(children.size()!=0)
            {cout<<children[0]->name;
            if(children[0]->spouse_name!="") 
            cout<<" ("+children[0]->spouse_name+")";
            cout<<endl;
            if (children[0]->children.size()!=0)
                (children[0])->print();
              
            }
         }
         else 
         {
             
            _level=level;
            print_bar(); 
            if (level==0)
            cout<<"+---";
             else if ((level==1) and (children[0]->spouse_name!=""))
            cout<<"    +---";
            else if (level==1)
            cout<<"   +---";
            else if(level==2 && children[0]->name.length()==3)
            cout<<"   +---";
             else if (level==2)
            cout<<"        +---";
             
            
            cout<<children[0]->name;
            if(children[0]->spouse_name!="") 
            cout<<" ("+children[0]->spouse_name+")";
            cout<<endl;
            if (children[0]->children.size()!=0)
                (children[0])->print();
          
            
            if (children.size()!=0)
            {
                children[0]->~Person();
                print();
                
            }
        
         }
        
    
}

/**
 * 
 * Print the vertical bar.
 */
void Person::print_bar() const
{
    /***** Complete this member function: Recursively print vertical bars. *****/
  
   string printbar[]={"|   |\n|","    |   |\n    |"};
   if(level==1 && children[0]->spouse_name=="")
        cout<<printbar[0];
    else if(level==2 && children[0]->name.length()==3)
        cout<<printbar[1];
    //Recursive Section   
    else{
  
            if (_level<1)
            {
                cout<<"|"<<endl;
                return;
            }
            else
            {
                cout<<"    ";
                _level--;
         //Recursive call
                print_bar();
            }
        }
}