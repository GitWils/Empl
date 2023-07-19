#include <vector>
#include <iostream>
#include <ctime>
#include "employee.h"
#include "lmanager.h"
using namespace std;

void init(LoadMan &lm, vector <Employee> &workers);

int main()
{
  struct Employee acc, acc2, acc3;

  cout << "Employee has " << sizeof(Employee) << " bytes for each\n";
  vector <Employee> workers;
  LoadMan lmngr(workers);  

  //uncoment line for first run use database initialising
  init(lmngr, workers);

  for(auto i = workers.begin(); i != workers.end(); i++)
  {
    cout << "№" << i->getNomenclature() << " " << i->getName() << " "
      << i->getForm() << " форма допуска знайдено" << endl;
    time_t time = i->getModified();
    cout << "Запис оновлено " << ctime(&time);
  }
  lmngr.ClearFile();
  if(lmngr.Save(workers))
    cout << "Succesfully saved\n";

  return 0;
}

void init(LoadMan &lm, vector <Employee> &workers)
{
  //creating data samples
  workers.clear();
  const int SIZE = 3;
  struct Employee acc[SIZE];
  acc[0] = Employee("Кириченко Денис", 2, 9);
  acc[1] = Employee("Петренко Микита Михайлович", 2, 100);
  acc[2] = Employee("Яковенко О.Ї.", 3, 100);
  
  //saving data samples
  for(int i = 0; i < SIZE; i++)
  { 
    acc[i].updateTimestamp();
    workers.push_back(acc[i]);
  }
}
