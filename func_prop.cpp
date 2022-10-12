#include <iostream>

using namespace std;

class BunDau
{
    private:
        int count = 0;
        int price = 0;
    public: 
        BunDau()
        {
        }

        void set_count(int x)
        {
            count = x;
        }

        void set_price(int x)
        {
            price = x;
        }

        void get_count() const
        {
            cout << "count: " << count << endl;
        }

        void get_price() const
        {
            cout << "price: " << price << endl;
        }

        void payment() const
        {   
            cout << "Total payment: " << count*price << endl;
        }
 
};

int main() 
{
    BunDau *bd = new BunDau();
    bd -> payment();
    
    bd->set_count(7);
    bd->set_price(45);

    bd->get_count();
    bd->get_price();

    bd->payment();
    return 0;
}