#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cmath>
#include <memory>
#include <map>
#include <functional>

//=============== HotDrink
struct HotDrink
{
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
    void prepare(int volume) override
    {
        std::cout << "Take tea bag" << std::endl;
    }

};

struct Cofee : HotDrink
{
    void prepare(int volume) override
    {
        std::cout << "Coffe" << std::endl;
    }
};

//=============== HotDrinkFactory

struct HotDrinkFactory
{
    virtual std::unique_ptr<HotDrink> make() const = 0; 
};

struct TeaFactor :HotDrinkFactory
{
    std::unique_ptr<HotDrink> make() const override
    {
        return std::make_unique<Tea>();
    }
};

struct CoffeeFactor :HotDrinkFactory
{
    std::unique_ptr<HotDrink> make() const override
    {
        return std::make_unique<Cofee>();
    }
};

std::unique_ptr<HotDrink> make_drink(std::string name)
{
    std::unique_ptr<HotDrink> drink;
    if(name == "tea")
    {
        drink = std::make_unique<Tea>();
        drink -> prepare(200);
    }
    else
    {
        drink = std::make_unique<Cofee>();
        drink -> prepare(50);
    }
    return drink;
}

// ======== DrinkFactory
class DrinkFactory
{
    std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factories;
public:
    DrinkFactory()
    {
        hot_factories["cofee"] = std::make_unique<CoffeeFactor>();
        hot_factories["tea"] = std::make_unique<TeaFactor>();
    }

    std::unique_ptr<HotDrink> make_drink(const std::string& name)
    {
        auto drink = hot_factories[name]->make();
        drink->prepare(200);

        return drink;
    }
};


class DrinkWithVolumeFactory
{
    std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;
public:
    DrinkWithVolumeFactory()
    {
        factories["tea"] = [] 
        {auto tea = std::make_unique<Tea>();
        tea->prepare(200);
        return tea;
        };
    }
    std::unique_ptr<HotDrink> make_drink(const std::string& name)
    {
        return factories[name]();
    }
};


int main()
{
    DrinkFactory df;
    auto c =df.make_drink("cofee");
    return 0;
}
