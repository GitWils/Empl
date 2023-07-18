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

  cout << "Employee has " << sizeof(Employee) << " bytes for one\n";
  vector <Employee> workers;
  LoadMan lmngr(workers);  

  //uncoment line for first run use database initialising
  //init(lmngr, workers);

  for(auto i = workers.begin(); i != workers.end(); i++)
  {
    cout << "№" << i->getNomenclature() << " " << i->getName() << " "
      << i->getForm() << " форма допуска знайдено" << endl;
    time_t time = i->getModified();
    cout << "Запис оновлено " << ctime(&time);
  }


  return 0;
}

void init(LoadMan &lm, vector <Employee> &workers)
{
  //creating data samples
  struct Employee acc, acc2, acc3;
  acc = Employee("Кириченко Денис", 2, 9);
  acc.updateTimestamp();
  acc2 = Employee("Петренко Микита Михайлович", 2, 100);
  acc2.updateTimestamp();
  acc3 = Employee("Яковенко О.М.", 3, 100);
  acc3.updateTimestamp();
  
  //saving data samples
  lm.ClearFile();
  lm.Save(acc);
  lm.Save(acc2);
  lm.Save(acc3);
}
