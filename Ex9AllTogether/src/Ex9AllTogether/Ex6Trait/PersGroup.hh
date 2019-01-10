#include <string>
#include <unordered_set>

struct Person
{
    int id;
    std::string firstName, lastName;
    
    Person(){}
    
    Person(int ID, std::string firstN, std::string lastN)
    {
        id = ID;
        firstName = firstN;
        lastName = lastN;
    }

    bool operator==(const Person &person) const { return id == person.id; }
};

template <>
struct std::hash<Person>
{
    typedef size_t res_type;
    typedef Person arg_type;
    res_type operator()(const arg_type &person) const { return static_cast<res_type>(person.id); }
};

struct Group
{
    int id;
    std::string name;
    std::unordered_set<Person> persons;

    Group(int ID, std::string NAME)
    {
        id = ID;
        name = NAME;
    }
};

template <>
struct std::hash<Group>
{
    typedef size_t res_type;
    typedef Group arg_type;
    res_type operator()(const arg_type &group) const { return static_cast<res_type>(group.id); }
};

template <class T>
struct Trait;

template <>
struct Trait<Person>
{
    static int size(const Person &person) { return sizeof(person.id) + person.firstName.size() + person.lastName.size(); }
};

template <>
struct Trait<Group>
{
    static int size(const Group &group)
    {
        int size = sizeof(group.id) + group.name.size();
        for (auto person = group.persons.begin(); person != group.persons.end(); person++)
            size += Trait<Person>::size(*person);
        return size;
    }
};
