#include <iostream>

using namespace std;

class Dumb{
    public:
    Dumb(int a){
        this->a = a;
        c = new int;
        *c = 12345;
    }

    ~Dumb(){
        delete c;
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

int main(){

    Dumb thing(10);
    cout << "Dumb thing get a:" << thing.getA() << endl;
    int a = 78;
    thing.setB(&a);
    thing.printB();

    Dumb g(66);
    g.setB(&a);

    a = 100;

    g.printB();
    cout << " -------------------- " << endl;
    cout << *g.getApointer() << endl;

    thing.setB(g.getApointer());
    thing.printB();

    thing.printC();

    Dumb* d = new Dumb(9999);

    int* e = (int*)malloc(sizeof(int));

    d->setB(g.getApointer());

    d->printB();

    delete e;
    delete d;
    d = NULL;

}