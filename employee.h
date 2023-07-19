#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <ctime>

class Employee
{
  private:
    char m_name[200];
    unsigned short int m_form;
    unsigned short int m_nomenclature;
    std::time_t m_datechanged;   
    std::time_t m_birthDate;
    std::time_t m_date;
  public:
    Employee(const char * name = "none", 
        unsigned short int form = 3, 
        unsigned short int nomenclature = 0,
        std::time_t birthday = 0,
        std::time_t date = 0);    
    char * getName();
    unsigned short int getForm();
    unsigned short int getNomenclature();
    std::time_t getBirthDate();
    void updateTimestamp();
    std::time_t getModified();
};

#endif
