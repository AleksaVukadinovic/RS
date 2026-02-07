#include "Student.hpp"
#include <numeric>

Student::Student() : _studies(Studies::Mathematics) {}

Student::Student(const std::string &fullName, Studies studies, const std::vector<int> &grades)
    : _fullName(fullName), _studies(studies), _grades(grades) {}

double Student::averageGrade() const {
    if (_grades.empty()) return 0.0;
    return std::accumulate(_grades.begin(), _grades.end(), 0.0) / _grades.size();
}

void Student::addGrade(const int grade) {
    _grades.push_back(grade);
}

std::string Student::introduceYourself() const {
    return "I am " + _fullName + ". In the " + programName() + " program, I have an average grade of " + std::to_string(averageGrade());
}

std::string Student::programName() const {
    switch (_studies) {
        case Studies::Mathematics: return "Mathematics";
        case Studies::Informatics: return "Informatics";
        default: return "Astronomy and Astrophysics";
    }
}
