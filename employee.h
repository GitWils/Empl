#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

class Employee
{
  private:
    char m_name[200];
    unsigned short int m_form;
    unsigned short int m_nomenclature;
    long int m_date;
  public:
    Employee(const char * name = "none", 
        unsigned short int form = 3, 
        unsigned short int nomenclature = 0,
        long int date = 0);    
    char * getName();
    unsigned short int getForm();
    unsigned short int getNomenclature();
};

#endif
