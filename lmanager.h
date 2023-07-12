#ifndef LMANAGER_H_
#define LMANAGER_H_

struct Employee
{
  char name[80];
  unsigned int id;
};

class LoadMan
{
  private:
  const char *m_pFName;
  public:
    LoadMan();
    ~LoadMan();
    void Save(Employee &e);
    void ClearFile();
};

#endif
