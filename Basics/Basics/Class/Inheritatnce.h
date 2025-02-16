#include <iostream>


#define print(VARIABLE) std::cout << #VARIABLE << std::endl;

namespace v
{
    class Animal
    {
    public:
        virtual void eats()
        {
            print("the animal eats food") 
        }

        virtual void drinks()
        {
            print("the animal drinks water")
        }

        virtual ~Animal() {}
    };

    class Dog : public Animal
    {
    public:
        virtual void eats() override
        {
            print("the dog eats food");  // Add semicolon here
        }

        virtual void drinks() override
        {
            print("the dog drinks water");  // Add semicolon here
        }

        ~Dog() override {}
    };

    class Cat : public Animal
    {
    public:
        virtual void eats() override
        {
            print("the cat eats food");  // Add semicolon here
        }

        virtual void drinks() override
        {
            print("the cat drinks water");  // Add semicolon here
        }

        ~Cat() override {}
    };
}
