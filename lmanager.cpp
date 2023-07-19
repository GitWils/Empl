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

bool LoadMan::Save(Employee &empl)
{
  using namespace std;
  ofstream file(m_pFName , ios::out | ios::binary | ios::app);
  if(!file) {
    cout << "Cannot open file.\"" << m_pFName << "\"\n";
    return false;
  }
  file.write((char *) &empl, sizeof(struct Employee));
  cout << "Запись " << empl.getName() << " сохранена\n";
  file.close();
  return true;
}

bool LoadMan::Save(std::vector <Employee> &workers)
{
  using namespace std;
  ofstream file(m_pFName , ios::out | ios::binary | ios::app);
  if(!file) {
    cout << "Cannot open file.\"" << m_pFName << "\"\n";
    return false;
  }
  for(long unsigned int i = 0; i < workers.size(); i++)
  {
    file.write((char *) &workers[i], sizeof(struct Employee));
    cout << "Запись " << workers[i].getName() << " сохранена\n";
  }
  file.close();
  return true;
}

void LoadMan::ClearFile()
{
  std::ofstream file;
  file.open(m_pFName, std::ofstream::out | std::ofstream::trunc);
  file.close();
}
