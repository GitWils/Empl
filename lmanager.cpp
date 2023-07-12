#include <iostream>
#include <fstream>
#include "lmanager.h"

static char fname[] = "data";

LoadMan::LoadMan()
{
  using namespace std;
  cout << "Loading from file..." << endl;
  ifstream file(fname, ios::in | ios::binary);
  if(!file) {
    cout << "Cannot open file \"data\".\n";
  }
  int i = 0;
  Employee empl;
  file.read((char *) &empl, sizeof(struct Employee));
  while(file.good())
  {
    i++;
    cout << "№" << empl.id<< " " << empl.name << " найден" << endl;
    file.read((char *) &empl, sizeof(struct Employee));
  }
  file.close();
  cout << i << " записів знайдено" << endl;
}

LoadMan::~LoadMan()
{
  //delete m_pFile;
}

void LoadMan::Save(Employee &empl)
{
  using namespace std;
  ofstream file(fname , ios::out | ios::binary | ios::app);
  if(!file) {
    cout << "Cannot open file.\n";
    return;
  }
  file.write((char *) &empl, sizeof(struct Employee));
  cout << "Запись " << empl.name << " сохранена\n";
  file.close();
}

void LoadMan::ClearFile()
{
  std::ofstream file;
  file.open(fname, std::ofstream::out | std::ofstream::trunc);
  file.close();
}
