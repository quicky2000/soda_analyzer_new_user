#include "new_user_analyzer_description.h"

namespace osm_diff_analyzer_new_user
{
  //----------------------------------------------------------------------------
  const std::string & new_user_analyzer_description::get_input_type(void)const
  {
    return m_input_type;
  }

  //----------------------------------------------------------------------------
  const std::string & new_user_analyzer_description::get_output_type(void)const
  {
    return m_output_type;
  }

  //----------------------------------------------------------------------------
  const std::string & new_user_analyzer_description::get_type(void)const
  {
    return m_type;
  }

  const std::string new_user_analyzer_description::m_input_type = "sax";
  const std::string new_user_analyzer_description::m_output_type = "";
  const std::string new_user_analyzer_description::m_type = "new_user";

}
//EOF
