#ifndef _NEW_USER_ANALYZER_DESCRIPTION_H_
#define _NEW_USER_ANALYZER_DESCRIPTION_H_

#include "analyzer_description_if.h"

namespace osm_diff_analyzer_new_user
{
  class new_user_analyzer_description: public osm_diff_analyzer_if::analyzer_description_if
  {
  public:
    const std::string & get_input_type(void)const;
    const std::string & get_output_type(void)const;
    const std::string & get_type(void)const;
  private:
    static const std::string m_input_type;
    static const std::string m_output_type;
    static const std::string m_type;
  };
}
#endif // _NEW_USER_ANALYZER_DESCRIPTION_H_
//EOF
