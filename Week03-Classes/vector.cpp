#include <iostream>
#include <vector>

using namespace std;

void weird(const vector<int> &that){
    cout << "sizof that: " << sizeof(that) << endl;
    //that.push_back(56);
    //that[0] = 99999;
    cout << "size of that: " << that.size() << endl;
    
}

void weird2(const vector<int>* that){
    //cout << "sizof that: " << sizeof(that) << endl;
    that->push_back(56);
    //that[0] = 99999;
    cout << "size of that: " << (*that).size() << endl;
    cout << "size of that: " << that->size() << endl;
    
}

int main(){
    int a[10] = {56, 7,8};
    vector<int> b;

    cout << "sizeof a:" << sizeof(a) << endl;

    char* thing = "This";

    b.push_back(10);
    b.push_back(22);
    b.push_back(4334234);

    weird(b);
    weird2(&b);

    cout << "b size: " << b.size() << endl;
}