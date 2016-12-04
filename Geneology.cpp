#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

Person *make_tree();

/**
 * Main
 */
int main()
{
    Person *root = make_tree();
    root->print();
    delete root;

    cout << endl << "Done!" << endl;
    return 0;
}

/**
 * Dynamically construct a genealogy tree.
 * @return the root of the tree.
 */
Person *make_tree()
{
    Person *charles = new Person(0, "Charles", "Mary");

    Person *susan   = new Person(1, "Susan", "Bob");
    Person *george  = new Person(1, "George");
    Person *tom     = new Person(1, "Tom", "Alice");

    charles->have_child(susan);
    charles->have_child(george);
    charles->have_child(tom);

    Person *dick  = new Person(2, "Dick");
    Person *harry = new Person(2, "Harry");

    susan->have_child(dick);
    susan->have_child(harry);

    Person *eliza     = new Person(2, "Eliza", "Bud");
    Person *charlotte = new Person(2, "Charlotte", "Frank");
    Person *emily     = new Person(2, "Emily", "Carl");

    tom->have_child(eliza);
    tom->have_child(emily);
    tom->have_child(charlotte);

    Person *tim = new Person(3, "Tim");
    emily->have_child(tim);

    Person *carol = new Person(3, "Carol");
    Person *sara  = new Person(3, "Sara");

    charlotte->have_child(carol);
    charlotte->have_child(sara);

    return charles;
}