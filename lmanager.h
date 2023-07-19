#ifndef LMANAGER_H_
#define LMANAGER_H_

class LoadMan
{
  private:
    const char *m_pFName;
    LoadMan() {};
  public:
    LoadMan(std::vector<Employee> &workers);
    ~LoadMan();
    bool Save(Employee &e);
    bool Save(std::vector<Employee> &workers);
    void ClearFile();
};

#endif
