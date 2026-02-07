#pragma once
#include <string>
#include <vector>

enum class Studies {
    Mathematics,
    Informatics,
    AstronomyAndAstrophysics
};

class Student {
public:
    Student();
    virtual ~Student() {} // Virtual destructor is important for inheritance
    Student(const std::string &fullName, Studies studies, const std::vector<int> &grades);

    double averageGrade() const;
    void addGrade(const int grade);
    virtual std::string introduceYourself() const;

protected:
    std::string programName() const;

private:
    std::string _fullName;
    Studies _studies;
    std::vector<int> _grades;
};
