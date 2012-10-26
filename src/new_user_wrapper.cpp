#include "new_user_wrapper.h"
#include "new_user_analyzer_description.h"
#include "new_user_analyzer.h"
#include "common_api.h"

#include <cassert>
#include <iostream>

namespace osm_diff_analyzer_new_user
{
  //----------------------------------------------------------------------------
  const char * new_user_wrapper::get_api_version(void)
  {
    return MODULE_LIBRARY_IF_VERSION;
  }

  //----------------------------------------------------------------------------
  uint32_t new_user_wrapper::get_api_size(void)
  {
    return MODULE_LIBRARY_IF_API_SIZE;
  }

  //----------------------------------------------------------------------------
  osm_diff_analyzer_if::analyzer_description_if * new_user_wrapper::get_new_user_description(void)
  {
    return new new_user_analyzer_description();
  }

  //----------------------------------------------------------------------------
  osm_diff_analyzer_if::general_analyzer_if * new_user_wrapper::create_new_user_analyzer(const osm_diff_analyzer_if::module_configuration * p_conf)
  {
    return new new_user_analyzer(p_conf,*m_common_api);
  }

  //----------------------------------------------------------------------------
  void new_user_wrapper::require_common_api(osm_diff_analyzer_if::module_library_if::t_register_function p_func)
  {
    m_common_api = new common_api(p_func);
  }

  //----------------------------------------------------------------------------
  void new_user_wrapper::cleanup(void)
  {
    delete m_common_api;
  }
  common_api * new_user_wrapper::m_common_api = NULL;

  extern "C"
  {
    void register_module(void** p_api,uint32_t p_api_size)
    {
      assert(p_api_size == MODULE_LIBRARY_IF_API_SIZE);
      std::cout << "Registration of new_user analyzer API " << std::endl ;
      p_api[osm_diff_analyzer_if::module_library_if::GET_API_VERSION] = (void*)new_user_wrapper::get_api_version;
      p_api[osm_diff_analyzer_if::module_library_if::GET_API_SIZE] = (void*)new_user_wrapper::get_api_size;
      p_api[osm_diff_analyzer_if::module_library_if::GET_DESCRIPTION] = (void*)new_user_wrapper::get_new_user_description;
      p_api[osm_diff_analyzer_if::module_library_if::CREATE_ANALYZER] = (void*)new_user_wrapper::create_new_user_analyzer;
      p_api[osm_diff_analyzer_if::module_library_if::REQUIRE_COMMON_API] = (void*)new_user_wrapper::require_common_api;
      p_api[osm_diff_analyzer_if::module_library_if::CLEAN_UP] = (void*)new_user_wrapper::cleanup;
    }
  }
}
//EOF
