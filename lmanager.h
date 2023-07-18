#ifndef LMANAGER_H_
#define LMANAGER_H_

class LoadMan
{
  private:
    const char *m_pFName;
  public:
    LoadMan(std::vector<Employee> &workers);
    ~LoadMan();
    void Save(Employee &e);
    void ClearFile();
};

#endif
