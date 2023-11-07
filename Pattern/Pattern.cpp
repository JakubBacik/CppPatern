#include <iostream>
#include <fstream>
#include <cmath>
#include <memory>
#include <map>
#include <functional>



struct Address
{
    std::string street, city;
    int suite;

    Address(const std::string& street, const std::string& city, int suite) : street
    (street), city(city), suite(suite){}
    
    Address(const Address& other):
    street{other.street}, city{other.city}, suite{other.suite}
    {}

    friend std::ostream& operator<<(std::ostream& os, Address address){
        os << address.street << " " << address.city << " " << address.suite << std::endl;
        return os;
    }
};

struct Contact
{
    std::string name;
    Address *address;

    Contact(const std::string& name, Address *address) : name(name), address(address) {}

    Contact(const Contact& other)
        :name {other.name}
        ,address{new Address{ *other.address}}
        {

        }
    ~Contact(){ delete address; }

    friend std::ostream& operator<<(std::ostream& os, Contact contact){
        os << contact.name << " " << *contact.address << std::endl;
        return os;
    }
};


struct EmployeeFactory
{
    static std::unique_ptr<Contact> new_main_office_employee
    (const std::string& name, const int suite)
    {
        static Contact p{"", new Address{"123 East Dr", "London", 0}};
        return new_employee(name, suite, p);
    }
private:
    static std::unique_ptr<Contact> new_employee(const std::string& name, int suite, const 
    Contact& prototype)
    {
        auto result = std::make_unique<Contact>(prototype);
        result->name = name;
        result->address->suite = suite;
        
        return result;
    }
};

int main()
{   
    auto contat = EmployeeFactory::new_main_office_employee("John", 123);
    std::cout << *contat;
    return 0;
}