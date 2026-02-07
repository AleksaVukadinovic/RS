#include <iostream>
#include "Student.hpp"
#include "MasterStudent.hpp"

using namespace std;

int main() {
    // Undergraduate student
    Student s1("John Doe", Studies::Mathematics, {7, 8, 9, 10});
    cout << s1.introduceYourself() << endl;

    // Master student instance
    MasterStudent s2("AI in Robotics", "Dr. Smith", "Jane Smith", Studies::Informatics, {10, 10, 9});

    // Demonstrating polymorphism via pointer
    Student* s3 = &s2;
    cout << s3->introduceYourself() << endl; // Calls MasterStudent's version

    // Demonstrating polymorphism via reference
    Student &s4 = s2;
    cout << s4.introduceYourself() << endl;

    // Heap allocation
    Student *s5 = new MasterStudent("Quantum Computing", "Dr. Heisenberg", "Mark Brown", Studies::Mathematics, {9, 10});
    cout << s5->introduceYourself() << endl;

    delete s5; // Cleanup

    return 0;
}
