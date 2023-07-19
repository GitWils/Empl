#include <cstring>
#include <ctime>
#include "employee.h"

static const int NAMESIZE = 200;

Employee::Employee(const char * name, 
    unsigned short int form, 
    unsigned short int nomenclature, 
    std::time_t birthday,
    std::time_t date)
{
  std::strncpy(m_name, name, NAMESIZE);
  m_name[NAMESIZE - 1] = '\0';
  m_form = form;
  m_nomenclature = nomenclature;
  m_birthDate = birthday;
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

std::time_t Employee::getModified()
{
  return m_datechanged;
}

std::time_t Employee::getBirthDate()
{
  return m_birthDate;
}

void Employee::updateTimestamp()
{
  m_datechanged = time(0);
}
