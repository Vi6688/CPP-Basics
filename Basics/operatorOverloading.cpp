

class Marks
{
private:
    int mark1, mark2;

public:

    Marks(int &mark1, int &mark2);
    Marks operator+(Marks m)
    {
        
    }
    ~Marks();
};


Marks::Marks(int &mark1,int &mark2)
{
    this->mark1 = mark1;
    this->mark2 = mark2;
}

int main()
{
    Marks m1(10,20), m2(20,20);

}