#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <boost/lexical_cast.hpp>
#include <vector>

class SignletonDatabase
{
    SignletonDatabase()
    {
        std::cout << "Init database \n";
        std::ifstream ifs("capitals.txt");

        std::string s, s2;
        while(getline(ifs, s))
        {
            std::cout << s;
            getline(ifs,s2);
            int pop = boost::lexical_cast<int>(s2);
            capitals[s] = pop;
        }
    }
    std::map<std::string, int> capitals;
public:
    SignletonDatabase(SignletonDatabase const&) = delete;
    void operator=(SignletonDatabase const&) = delete;

    static SignletonDatabase& get()
    {
        static SignletonDatabase db;
        return db;
    }
    
    int get_population(const std::string& name)
    {
        return capitals[name];
    }
};

int main() 
{
    std::string city = "Tokyo";
    std:: cout << SignletonDatabase::get().get_population(city);

    return 0;
}