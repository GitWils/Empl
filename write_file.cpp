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
  //LoadMan lmngr();  

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
  struct Employee acc[3];
  acc[0] = Employee("Кириченко Денис", 2, 9);
  acc[0].updateTimestamp();
  acc[1] = Employee("Петренко Микита Михайлович", 2, 100);
  acc[1].updateTimestamp();
  acc[2] = Employee("Яковенко О.М.", 3, 100);
  acc[2].updateTimestamp();
  
  //saving data samples
  lm.ClearFile();
  lm.Save(acc[0]);
  lm.Save(acc[1]);
  lm.Save(acc[2]);
}
