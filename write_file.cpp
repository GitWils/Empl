#include <iostream>
#include <fstream>
#include <cstring>
#include "lmanager.h"
using namespace std;

struct MyRecord {
  char name[200];
  double balance;
  unsigned long account_num;
};

int main()
{
  struct Employee acc, acc2, acc3;

  LoadMan lmngr;
  lmngr.ClearFile();

  strcpy(acc.name, "Рябченко Юрій");
  acc.id = 5;

  strcpy(acc2.name, "Рябченко Соломія Юрівна");
  acc2.id = 6;

  strcpy(acc3.name, "Рябченко О.М.");
  acc3.id = 7;

  lmngr.Save(acc);
  lmngr.Save(acc2);
  lmngr.Save(acc3);

  return 0;
}
