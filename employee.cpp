#include <cstring>
#include "employee.h"

static const int NAMESIZE = 200;

Employee::Employee(const char * name, 
    unsigned short int form, 
    unsigned short int nomenclature, 
    long int date)
{
  std::strncpy(m_name, name, NAMESIZE);
  m_name[NAMESIZE - 1] = '\0';
  m_form = form;
  m_nomenclature = nomenclature;
  m_date = date;
}

char * Employee::getName()
{
  return m_name;
}

unsigned short int Employee::getForm()
{
  return m_form;
}

unsigned short int Employee::getNomenclature()
{
  return m_nomenclature;
}
