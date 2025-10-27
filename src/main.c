// TODO: CMake file to integrate every module.
#include "cutils.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[32];
    int age;
} Person;

int main() {
    ArrayList people;
    arraylist_init(&people, sizeof(Person)); // store full structs

    Person p1 = {"Alice", 25};
    Person p2 = {"Bob", 30};

    arraylist_append(&people, &p1);
    arraylist_append(&people, &p2);

    for (size_t i = 0; i < people.count; i++) {
        Person *p = arraylist_get(&people, i);
        printf("Person[%zu] = %s (%d years old)\n", i, p->name, p->age);
    }

    arraylist_free(&people);
    return 0;
}