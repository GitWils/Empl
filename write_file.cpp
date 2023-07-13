#include <iostream>
#include <fstream>
#include <cstring>
#include "employee.h"
#include "lmanager.h"
using namespace std;

int main()
{
  struct Employee acc, acc2, acc3;

  cout << "Employee has " <<sizeof(Employee) << " bytes\n";
  LoadMan lmngr;
  /*lmngr.ClearFile();

  acc = Employee("Рябченко Юрій", 3, 100);
  acc2 = Employee("Рябченко Соломія Юрівна", 5, 100);
  acc3 = Employee("Рябченко О.М.", 6, 100);

  lmngr.Save(acc);
  lmngr.Save(acc2);
  lmngr.Save(acc3);*/

  return 0;
}
