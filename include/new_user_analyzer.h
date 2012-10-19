#ifndef _NEW_USER_ANALYZER_H_
#define _NEW_USER_ANALYZER_H_

#include "sax_analyzer_base.h"
#include "stdint.h"
#include <map>
#include <fstream>

namespace osm_diff_analyzer_new_user
{
  class common_api;

  class new_user_analyzer:public osm_diff_analyzer_sax_if::sax_analyzer_base
  {
  public:
    new_user_analyzer(const std::string & p_name,common_api * p_api);
    ~new_user_analyzer(void);
    // Methods inherited from sax_analyzer_if
    void init(void);
    void start_element(const std::string & p_name);
    void get_attribute(const std::string & p_name,const std::string & p_value);
    void end_element(const std::string & p_name);
    // End of inherited methods
  private:
    //TO DELETE    std::string get_user_inscription_date(const std::string & p_user)const;


    common_api * m_api;
    std::ofstream m_report;
    uint32_t m_uid;
    std::string m_user_name;
    std::map<uint32_t,std::string> m_users;
    std::map<std::string,uint32_t> m_months;
  };
}
#endif
