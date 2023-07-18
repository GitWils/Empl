#include <iostream>
#include <fstream>
#include <vector>
#include "employee.h"
#include "lmanager.h"

LoadMan::LoadMan(std::vector<Employee> &workers):m_pFName("data")
{
  using namespace std;
  cout << "Loading records from file \"" << m_pFName << "\"...\n";
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
    workers.push_back(empl);
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
