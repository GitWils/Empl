#include <iostream>
#include <fstream>
#include "employee.h"
#include "lmanager.h"

LoadMan::LoadMan():m_pFName("data")
{
  using namespace std;
  cout << "Loading from file " << m_pFName << endl;
  ifstream file(m_pFName, ios::in | ios::binary);
  if(!file) {
    cout << "Cannot open file \"" << m_pFName << "\".\n";
  }
  int i = 0;
  Employee empl;
  file.read((char *) &empl, sizeof(struct Employee));
  while(file.good())
  {
    i++;
    cout << "форма №" << empl.getForm() << " " << empl.getName() << " найден" << endl;
    file.read((char *) &empl, sizeof(struct Employee));
  }
  file.close();
  cout << i << " записів знайдено" << endl;
}

LoadMan::~LoadMan()
{
}

void LoadMan::Save(Employee &empl)
{
  using namespace std;
  ofstream file(m_pFName , ios::out | ios::binary | ios::app);
  if(!file) {
    cout << "Cannot open file.\"" << m_pFName << "\"\n";
    return;
  }
  file.write((char *) &empl, sizeof(struct Employee));
  cout << "Запись " << empl.getName() << " сохранена\n";
  file.close();
}

void LoadMan::ClearFile()
{
  std::ofstream file;
  file.open(m_pFName, std::ofstream::out | std::ofstream::trunc);
  file.close();
}
