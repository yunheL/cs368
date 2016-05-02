/*
 * This program gives examples of how vectors are instantiated and used.
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>   // needed for sort()
using namespace std;


class Student {
      int id;
      string name;
      string login;
   public:
      Student(int id, string name, string login) {
         this->id = id;
         this->name = name;
         this->login = login;
      }
      void print() {
         cout << "ID:" << id << " (" << login << ") " << name << endl;
      }
      int getID() const { return this->id; }
      string getName() const { return name; }
      string getLogin() const { return login; }
      //bool compareID(const Student &t ) { return this->id < t->id; }
      //bool compareLogin(const Student &t ) { return login < t.login; }
};

class CompareID {
    public:
       bool operator() (Student &s, Student &t) const {
           return s.getID() < t.getID();
       }
};

void print(const std::vector<Student>& v) { 
    cout << "v.size()=" << v.size() << endl;
    for ( Student s : v ) {
        s.print() ;
    }
}

int main() {

    Student *s1, *s2, *s3;
    s1 = new Student(3,"Deb Deppeler", "deppeler");
    s2 = new Student(1,"Jim Skrentny", "skrentny");
    s3 = new Student(2,"Beck Hasti", "hasti");

    cout << "Compare using simple if test: ";
    if ( s1->getID() < s2->getID() ) cout << "s1's ID is less than s2's ID \n" ; 
    else                             cout << "s1's ID is greater than s2's ID \n" ; 

    // Using a Function Object
    cout << "CompareID functor example: ";
    CompareID comp;
    if ( comp(*s1,*s2) ) cout << s1->getID() << " is less than " << s2->getID() << endl;
    else                 cout << s1->getID() << " is greater than " << s2->getID() << endl;

    vector<Student> v;
    v.push_back(*s1);
    v.push_back(*s2);
    v.push_back(*s3);
    print(v);

    cout << "====== TEST SORTING STUDENTS EXAMPLES ======" << endl;

    // SORT VECTOR OF STUDENTS BY ID WITH A LAMBDA FUNCTION
    sort(v.begin(),v.end(), [](Student &s, Student &t) { return s.getID() < t.getID(); });
    cout << "\nafter sort(v.begin(),v.end(),[](Student &s, Student &t){return s.getID() < t.getID();}) " << endl;
    print(v);

    // SORT VECTOR OF STUDENTS BY login WITH A LAMBDA FUNCTION
    sort(v.begin(),v.end(), [](Student &s, Student &t) { return s.getLogin().compare(t.getLogin());});
    cout << "\nafter sort(v.begin(),v.end(),[](Student &s, Student &t){return (s.getLogin()).compare(t.getLogin());})\n";
    print(v);
//*/
    return 0;

}
