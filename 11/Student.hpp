#pragma once
#include "Serializable.h"
#include <QVector>

class CourseItem;

class Student : public Serializable {
public:
    Student(const QString &name = "", const QString &surname = "", const QString &index = "", const QString &personalNumber = "",
            bool enrolled = false, const QVector<CourseItem *> courseItems = {});
    ~Student();

    enum Attributes { Name, Surname, Index, PersonalNumber, Enrolled, CourseItems };

    QString getName() const;
    QString getSurname() const;
    QString getIndex() const;
    QString getPersonalNumber() const;
    bool getEnrolled() const;
    QVector<CourseItem *> &getCourseItems();

    void setAttribute(Attributes attr, QVariant value);

    QVariant toVariant() const override;
    void fromVariant(const QVariant &variant) override;

private:
    QString m_name;
    QString m_surname;
    QString m_index;
    QString m_personalNumber;
    bool m_enrolled;
    QVector<CourseItem *> m_courseItems;
};
