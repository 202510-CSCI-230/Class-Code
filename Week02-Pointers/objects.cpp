/*
    Class example code
    CSCI 230
    Fall 2025
    Sept 3, 2025
*/
#include <iostream>
#include <string>

using namespace std;


class Dog{
    public:
    Dog(){
        cout << "Inside the Dog constructor" << endl;
        name = "not defined";
        age = 0;
    } 

    Dog(string n){
        cout << "Inside the Dog constructor with parameters" << endl;
        name = n;
        age = 0;
    } 
    ~Dog(){
        cout << name << " got destructed" << endl;
    }

    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    
    private:
    int age;
    string name;
};

void anotherFn(){
    Dog a("Terry");
    cout << "Terry lives at " << &a << endl;
}

int main(){
    int another; 
    cout << "another: " << another << endl;

    Dog a("Princess");
    cout << "A's name is " << a.getName()  << endl;
    cout << a.getAge() << endl;
    //Dog b("Prince");
    Dog* b = new Dog("New Prince");
    //cout << "B's name is " << (*b).getName()  << endl;
    cout << "B's name is " << b->getName()  << endl;
    //cout << b.getAge() << endl;

    cout << "Princess lives at " << &a << " Prince: " << b << endl;

    anotherFn();
    cout << "in main" << endl;
    anotherFn();

    delete b;
}