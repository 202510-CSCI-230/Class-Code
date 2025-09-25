#include <iostream>

using namespace std;

class Dumb{
    public:
    Dumb(int a){
        this->a = a;
        c = new int;
        *c = 12345;
    }

    Dumb(const Dumb &other){
        cout << "Copy constructor called";
        this->a = other.a;
        c = new int;
        *c = *(other.c);
    }

    ~Dumb(){
        cout << "Inside destructor" << endl;
        cout.flush();
        delete c;
        c = NULL;
    }

    int getA(){
        return a;
    }

    void setB(int* temp){
        b = temp;
    }

    void printB(){
        cout << *b << endl;
    }

    void printC(){
        cout << *c << endl;
    }

    int* getApointer(){
        return &a;
    }

    private:
    int a;
    int* b;
    int* c;

};

void anotherFunction(Dumb sent){
    cout << "Sent C:";
    sent.printC();
}

int main(){

    Dumb thing(10);
    cout << "Dumb thing get a:" << thing.getA() << endl;
    int a = 78;
    thing.setB(&a);
    thing.printB();
    thing.printC();

    anotherFunction(thing);

}