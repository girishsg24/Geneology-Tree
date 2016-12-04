#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <vector>
using namespace std;

class Person
{
public:
    Person();
    Person(int level, string name);
    Person(int level, string name, string spouse);
    virtual ~Person();

    void have_child(Person *child);
    void print() const;

private:
    int level;  // oldest ancestor is level 0
    string name;
    string spouse_name;
    Person *parent;
    vector<Person*> children;

    void print_bar() const;
};

#endif /* PERSON_H_ */