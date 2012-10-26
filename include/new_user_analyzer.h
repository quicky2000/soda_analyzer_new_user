#ifndef _NEW_USER_ANALYZER_H_
#define _NEW_USER_ANALYZER_H_

#include "sax_analyzer_base.h"
#include "stdint.h"
#include "new_user_analyzer_description.h"
#include <map>
#include <fstream>

namespace osm_diff_analyzer_new_user
{
  class common_api;

  class new_user_analyzer:public osm_diff_analyzer_sax_if::sax_analyzer_base
  {
  public:
    new_user_analyzer(const osm_diff_analyzer_if::module_configuration * p_conf,common_api & p_api);
    ~new_user_analyzer(void);
    // Methods inherited from sax_analyzer_if
    void init(void);
    void start_element(const std::string & p_name);
    void get_attribute(const std::string & p_name,const std::string & p_value);
    void end_element(const std::string & p_name);
    const std::string & get_input_type(void)const;
    const std::string & get_output_type(void)const;
    const std::string & get_type(void)const;
    // End of inherited methods
  private:
    common_api * m_api;
    std::ofstream m_report;
    uint32_t m_uid;
    std::string m_user_name;
    std::map<uint32_t,std::string> m_users;
    std::map<std::string,uint32_t> m_months;

    static new_user_analyzer_description m_description;
  };
}
#endif
