#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Teacher
{

public:
    Teacher()
    {
        cout << "Heyy Boyy!";
    }
    // properties
    string teacher;
    string dept;
    string subject;
    double salary;

    // methods
    void changeDpt(string newDpt)
    {
        dept = newDpt;
    }
};

int main()
{
    Teacher t1;

    t1.subject = "DSA";
    cout << t1.subject;
}