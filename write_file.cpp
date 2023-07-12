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

  LoadMan LMngr;
  LMngr.ClearFile();

  strcpy(acc.name, "Рябченко Юрій");
  acc.id = 5;

  strcpy(acc2.name, "Рябченко Соломія Юрівна");
  acc2.id = 6;

  strcpy(acc3.name, "Рябченко О.М.");
  acc3.id = 7;

  LMngr.Save(acc);
  LMngr.Save(acc2);
  LMngr.Save(acc3);

  /*ofstream outbal("balance", ios::out | ios::binary);
  if(!outbal) {
    cout << "Cannot open file.\n";
    return 1;
  }

  outbal.write((char *) &acc, sizeof(struct MyRecord));
  outbal.write((char *) &acc2, sizeof(struct MyRecord));
  outbal.close();

  ifstream inbal("balance", ios::in | ios::binary);
  if(!inbal) {
    cout << "Cannot open file.\n";
    return 1;
  }

  inbal.read((char *) &acc, sizeof(struct MyRecord));
  inbal.read((char *) &acc2, sizeof(struct MyRecord));

  cout << acc.name << endl;
  cout << "Account # " << acc.account_num;
  cout.precision(2);
  cout.setf(ios::fixed);
  cout << endl << "Balance: $" << acc.balance << endl;

  cout << acc2.name << endl;
  cout << "Account # " << acc2.account_num;
  cout.precision(2);
  cout.setf(ios::fixed);
  cout << endl << "Balance: $" << acc2.balance << endl;

  inbal.close();*/
  return 0;
}
