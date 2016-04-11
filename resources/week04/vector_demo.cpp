#include <iostream>  
#include <vector>
using namespace std;

void print(vector<int> param_v) {
    cout << "vector param_v.size()=" << param_v.size() << endl;
    cout << "vector param_v.max_size()=" << param_v.max_size() << endl;
    cout << "vector param_v.capacity()=" << param_v.capacity() << endl;
    cout << "vector param_v.empty()=" << param_v.empty() << endl;
    for (int i=0 ; i < param_v.size(); i++ )
       cout << "vector param_v.at(" << i << ")=" << param_v.at(i) << endl;
    cout << "param_v.front() = " << param_v.front() << endl;
    cout << "param_v.back()  = " << param_v.back() << endl;
}

void change(vector<int> &vRef) {
    vRef.push_back(11);
}

int main() {

    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout << "print(v)" << endl;
    print(v);

    cout << "change(v)" << endl;
    change(v);

    cout << "print(v) after change(v)" << endl;
    print(v);

    return 0;
}
