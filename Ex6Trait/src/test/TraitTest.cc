#include <gtest/gtest.h>
#include "../Ex6Trait/PersGroup.hh"

TEST(PERSON, TRAITEQ)
{
    Person person(1, "Ivan", "Ivanov");
    EXPECT_EQ(sizeof(person.id) + person.firstName.size() + person.lastName.size(),
              Trait<Person>::size(person));
}

TEST(GROUP, TRAITEQ)
{
    Person *persons = new Person[9];
    Group group(0, "Workers");

    for (int i = 0; i < 9; i++)
    {
        persons[i].id = i;
        persons[i].firstName = "WorkerName" + i;
        persons[i].lastName = "WorkerLastName" + i;
        group.persons.insert(persons[i]);
    }
    int persSize = 0;
    for (int i = 0; i < 9; i++)
        persSize = persSize + Trait<Person>::size(persons[i]);

    EXPECT_EQ(sizeof(group.id) + group.name.size() + persSize,
              Trait<Group>::size(group));
}