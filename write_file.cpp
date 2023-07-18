#include <vector>
#include <iostream>
#include <ctime>
#include "employee.h"
#include "lmanager.h"
using namespace std;

int main()
{
  struct Employee acc, acc2, acc3;

  cout << "Employee has " << sizeof(Employee) << " bytes\n";
  /*acc = Employee("Рябченко Юрій", 2, 9);
  acc.updateTimestamp();
  acc2 = Employee("Рябченко Соломія Юрівна", 2, 100);
  acc2.updateTimestamp();
  acc3 = Employee("Рябченко О.М.", 3, 100);
  acc3.updateTimestamp();
  vector <Employee> workers;
  workers.push_back(acc);
  workers.push_back(acc2);
  workers.push_back(acc3);
  cout << "From vector:\n";
  for(auto i = workers.begin(); i != workers.end(); i++)
  {
    cout << i->getName() << endl;
  }*/

  vector <Employee> workers;
  LoadMan lmngr(workers);  
  for(auto i = workers.begin(); i != workers.end(); i++)
  {
    cout << "№" << i->getNomenclature() << " " << i->getName() << " "
      << i->getForm() << " форма допуска знайдено" << endl;
    time_t time = i->getModified();
    cout << "Запис оновлено " << ctime(&time);
  }
  //lmngr.ClearFile();


  //lmngr.Save(acc);
  //lmngr.Save(acc2);
  //lmngr.Save(acc3);

  return 0;
}
