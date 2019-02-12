#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

Person new_person(char* name, int age){
    char* s = strdup(name);
    return (Person) {
        .name = s,
        .age = age,
    };
}

Person clone_person(Person* p){
    return (Person) {
        .name = strdup(p->name),
        .age = p->age,
    };
}

int person_age(Person* p){
    return p->age;
}

void person_change_age(Person* p, int age){
    p->age = age;
}

void destroy_person(Person* p){
    free(p->name);
}

