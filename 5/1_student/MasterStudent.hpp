#pragma once
#include "Student.hpp"

class MasterStudent : public Student {
public:
    MasterStudent();
    MasterStudent(const std::string &thesisTitle, const std::string &mentorName,
                  const std::string &fullName, Studies studies, const std::vector<int> &grades);

    std::string introduceYourself() const override;

private:
    std::string _thesisTitle;
    std::string _mentorName;
};
