#ifndef _COMMON_API_H_
#define _COMMON_API_H_

#include "common_api_if.h"

namespace osm_diff_analyzer_new_user
{
  class common_api
  {
  public:
    inline common_api(osm_diff_analyzer_if::module_library_if::t_register_function p_func);
    inline void get_user_subscription_date(const std::string & p_name,std::string & p_date); 

  private:
    osm_diff_analyzer_if::common_api_if::t_get_user_subscription_date m_get_user_subscription_date;
  };

   //---------------------------------------------------------------------------- 
  common_api::common_api(osm_diff_analyzer_if::module_library_if::t_register_function p_func) 
    {
      void * l_api_ptr[COMMON_API_IF_SIZE];
      for(uint32_t l_index = 0 ;l_index < COMMON_API_IF_SIZE ; ++l_index)
        {
          l_api_ptr[l_index] = NULL;
        }
      p_func(l_api_ptr,COMMON_API_IF_SIZE);

      m_get_user_subscription_date = (osm_diff_analyzer_if::common_api_if::t_get_user_subscription_date)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_USER_SUBSCRIPTION_DATE];      
    }

  //----------------------------------------------------------------------------
  void common_api::get_user_subscription_date(const std::string & p_name,std::string & p_date)
  {
    m_get_user_subscription_date(p_name,p_date);
  }
}
#endif // _COMMON_API_H_
//EOF
