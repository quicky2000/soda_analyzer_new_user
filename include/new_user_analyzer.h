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
#ifndef _NEW_USER_ANALYZER_H_
#define _NEW_USER_ANALYZER_H_

#include "sax_analyzer_base.h"
#include "new_user_analyzer_description.h"
#include "module_configuration.h"
#include "osm_api_data_types.h"
#include <inttypes.h>
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
    void init(const osm_diff_analyzer_if::osm_diff_state * p_diff_state);
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
    osm_api_data_types::osm_object::t_osm_id m_uid;
    std::string m_user_name;
    osm_api_data_types::osm_object::t_osm_id m_changeset;
    std::map<uint32_t,std::string> m_users;
    std::map<std::string,uint32_t> m_months;

    static new_user_analyzer_description m_description;
  };
}
#endif
