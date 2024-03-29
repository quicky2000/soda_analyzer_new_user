/*
    This file is part of osm_diff_analyzer_new_user, SAX based 
    Openstreetmap diff analyzer whose aim is to detect users arrived
    in Openstreetmap Project for less than 3 Months
    Copyright (C) 2012  Julien Thevenon ( julien_thevenon at yahoo.fr )

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#include "new_user_wrapper.h"
#include "new_user_analyzer_description.h"
#include "new_user_analyzer.h"
#include "new_user_common_api.h"
#include "quicky_exception.h"
#include <sstream>
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
    m_common_api = new new_user_common_api(p_func);
  }

  //----------------------------------------------------------------------------
  void new_user_wrapper::cleanup(void)
  {
    delete m_common_api;
  }
  new_user_common_api * new_user_wrapper::m_common_api = NULL;

  extern "C"
  {
    void register_module(uintptr_t* p_api,uint32_t p_api_size)
    {
      if(p_api_size != MODULE_LIBRARY_IF_API_SIZE)
	{
	  std::stringstream l_stream;
	  l_stream << "p_api_size < MODULE_LIBRARY_IF_API_SIZE : " << p_api_size << " < " << MODULE_LIBRARY_IF_API_SIZE << ". Please use a newver version of saoda";
	  throw quicky_exception::quicky_logic_exception(l_stream.str(),__LINE__,__FILE__);
	}
#ifdef DEBUG
      std::cout << "Registration of new_user analyzer API " << std::endl ;
#endif
      p_api[osm_diff_analyzer_if::module_library_if::GET_API_VERSION] = (uintptr_t)new_user_wrapper::get_api_version;
      p_api[osm_diff_analyzer_if::module_library_if::GET_API_SIZE] = (uintptr_t)new_user_wrapper::get_api_size;
      p_api[osm_diff_analyzer_if::module_library_if::GET_DESCRIPTION] = (uintptr_t)new_user_wrapper::get_new_user_description;
      p_api[osm_diff_analyzer_if::module_library_if::CREATE_ANALYZER] = (uintptr_t)new_user_wrapper::create_new_user_analyzer;
      p_api[osm_diff_analyzer_if::module_library_if::REQUIRE_COMMON_API] = (uintptr_t)new_user_wrapper::require_common_api;
      p_api[osm_diff_analyzer_if::module_library_if::CLEAN_UP] = (uintptr_t)new_user_wrapper::cleanup;
    }
  }
}
//EOF
