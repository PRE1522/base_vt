#include <iostream>

using namespace std;

class Pet
{
    private:
        string name;

    public:
        Pet(string name_)
        {
            this->name = name_;
        }

        virtual string getSound()
        {
            return "No sound!";
        }

        void makeSound()
        {
            cout << (this->name) << "says: " << getSound() << endl;
        }
};

class Cat : public Pet
{
    public:
        Cat(string name_) : Pet(name_) 
        {
        }

        string getSound() 
        { 
            return "Meow.. Meow..!"; 
        }
};

class Dog : public Pet
{
    public:
        Dog(string n) : Pet(n) 
        {
        }

        string getSound() 
        { 
            return "Gau.. Gau..!"; 
        }
};

int main(void)
{
    Pet *a_pet = new Cat("Kitty");
    a_pet->makeSound();
    delete a_pet;

    a_pet = new Dog("Doggie");
    a_pet->makeSound();
    delete a_pet;

    return 0;
}