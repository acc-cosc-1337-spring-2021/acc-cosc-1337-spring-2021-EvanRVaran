//include statement for decision header
#include "decision.h"
//cpp

std::string get_letter_grade_using_if(int grade)
{
    std::string letterGrade;

    if(grade >= 90 && grade <= 100)
    {
        letterGrade = "A";
    }
    if(grade >= 80 && grade <= 89)
    {
        letterGrade = "B";
    }
    if(grade >= 70 && grade <= 79)
    {
        letterGrade = "C";
    }
    if(grade >= 60 && grade <= 69)
    {
        letterGrade = "D";
    }
    if(grade >= 0 && grade <= 59)
    {
        letterGrade = "F";
    }
    return letterGrade;
}

std::string get_letter_grade_using_switch(int grade)
{
    //rounds the two digit integer to the tens place, ex. 87 becomes 80
    std::string letterGrade;
    double dividedGrade = grade /10;
    int integerGrade = (int)dividedGrade * 10;

    switch(integerGrade)
    {
        case 100:
            letterGrade = "A";
            break;
        case 90:
            letterGrade = "A";
            break;
        case 80:
            letterGrade = "B";
            break;
        case 70:
            letterGrade = "C";
            break;
        case 60:
            letterGrade = "D";
            break;
        default:
            letterGrade = "F";
    }

    return letterGrade;
}