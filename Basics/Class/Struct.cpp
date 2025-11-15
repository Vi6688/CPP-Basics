#include <iostream>
#include <string>
using namespace std;

struct Book
{
    string name;
    int pages;
    float price;
    char revision = '1';
    double pricePerPage()
    {
        return price / pages;
    }
};

struct Registers{
    unsigned int a:4;
    unsigned short int b:2;
};
int main()
{


    Registers register1 = { 2,1};
    cout<<register1.a<<sizeof(register1)<<endl;
    cout<<register1.b<<sizeof(register1)<<endl;

    Book book1, book2;
    book1.name = "c++";
    book1.pages = 1000;
    book1.price = 100;

    book2.name = "python";
    book2.pages = 800;
    book2.price = 80;

    Book book3 = {"c", 1101, 140, '2'};
    Book library[3] = {book1, book2, book3};
    // for (int i = 0; i < sizeof(library)/sizeof(library[0]); i++)
    // {
    //     cout<<endl;
    //     cout << "Book" << i + 1 << ": name:          " << library[i].name << endl;
    //     cout << "Book" << i + 1 << ": price:         " << library[i].price << endl;
    //     cout << "Book" << i + 1 << ": pages:         " << library[i].pages << endl;
    //     cout << "Book" << i + 1 << ": revision:      " << library[i].revision << endl;
    //     cout << "Book" << i + 1 << ": price per page:" << library[i].pricePerPage() << endl;
    //     cout<<endl;
    // }
    return 0;
}