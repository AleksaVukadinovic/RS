#include "MasterStudent.hpp"

MasterStudent::MasterStudent() : Student() {}

MasterStudent::MasterStudent(const std::string &thesisTitle, const std::string &mentorName,
                             const std::string &fullName, Studies studies, const std::vector<int> &grades)
    : Student(fullName, studies, grades), _thesisTitle(thesisTitle), _mentorName(mentorName) {}

std::string MasterStudent::introduceYourself() const {
    return Student::introduceYourself() + ". My thesis is '" + _thesisTitle + "' under mentor " + _mentorName + ".";
}
