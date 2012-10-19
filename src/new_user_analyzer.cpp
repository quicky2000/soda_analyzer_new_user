#include "new_user_analyzer.h"
#include "common_api.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cassert>

namespace osm_diff_analyzer_new_user
{
  //------------------------------------------------------------------------------
  new_user_analyzer::new_user_analyzer(const std::string & p_name,common_api * p_api):
    osm_diff_analyzer_sax_if::sax_analyzer_base("user_analyser",p_name,""),
    m_api(p_api),
    m_report("new_user.txt")
  {
    if(m_report == NULL)
      {
	std::cout << "Error when trying to open file \"new_user.txt\"" << std::endl ;
	exit(EXIT_FAILURE);
      }
    m_report << "Contributors since less than one month : "  << std::endl ;

    m_months.insert(std::map<std::string,uint32_t>::value_type("January",1));
    m_months.insert(std::map<std::string,uint32_t>::value_type("February",2));
    m_months.insert(std::map<std::string,uint32_t>::value_type("March",3));
    m_months.insert(std::map<std::string,uint32_t>::value_type("April",4));
    m_months.insert(std::map<std::string,uint32_t>::value_type("May",5));
    m_months.insert(std::map<std::string,uint32_t>::value_type("June",6));
    m_months.insert(std::map<std::string,uint32_t>::value_type("July",7));
    m_months.insert(std::map<std::string,uint32_t>::value_type("August",8));
    m_months.insert(std::map<std::string,uint32_t>::value_type("September",9));
    m_months.insert(std::map<std::string,uint32_t>::value_type("October",10));
    m_months.insert(std::map<std::string,uint32_t>::value_type("November",11));
    m_months.insert(std::map<std::string,uint32_t>::value_type("December",12));
  }

  //------------------------------------------------------------------------------
  new_user_analyzer::~new_user_analyzer(void)
  {
    m_report.close();
  }

  //------------------------------------------------------------------------------
  void new_user_analyzer::init(void)
  {
  }

  //------------------------------------------------------------------------------
  void new_user_analyzer::start_element(const std::string & p_name)
  {
    m_uid = 0;
    m_user_name = "";
  }

  //------------------------------------------------------------------------------
  void new_user_analyzer::end_element(const std::string & p_name)
  {
    if(m_uid != 0 && m_user_name != "")
      {
	// Check if user has still been detected
	std::map<uint32_t,std::string>::const_iterator l_iter = m_users.find(m_uid);
	if(l_iter == m_users.end())
	  {
            std::string l_date;
            m_api->get_user_subscription_date(m_user_name,l_date);
	    m_users.insert(std::map<uint32_t,std::string>::value_type(m_uid,l_date));
	    std::cout << "==> User \"" << m_user_name << "\"\t\"" << l_date << "\"" << std::endl ;
	    // Expecting date looking like "August 13, 2009"
	    size_t l_first_space = l_date.find(" ");
	    size_t l_comma = l_date.find_last_of(",");
	    std::string l_month_str = l_date.substr(0,l_first_space);
	    std::string l_day_str = l_date.substr(l_first_space+1,l_comma-l_first_space-1);
	    std::string l_year_str = l_date.substr(l_comma+1);
#ifdef DEBUG_NEW_USER_ANALYZER
	    std::cout << "Day = \"" << l_day_str << "\"" << std::endl ;
	    std::cout << "Month = \"" << l_month_str << "\"" << std::endl ;
	    std::cout << "Year = \"" << l_year_str << "\"" << std::endl ;
#endif
	    std::map<std::string,uint32_t>::const_iterator l_iter_month = m_months.find(l_month_str);
	    assert(m_months.end() != l_iter_month);
    
	    uint32_t l_inscription_day = atoi(l_day_str.c_str());   
	    uint32_t l_inscription_month  = l_iter_month->second  ;
	    uint32_t l_inscritpion_year = atoi(l_year_str.c_str()) ; 
	    time_t l_today = time(NULL);
	    struct tm l_inscription;
    
	    memset(&l_inscription,0,sizeof(l_inscription));
	    l_inscription.tm_mday = l_inscription_day;   /* 1er                */
	    l_inscription.tm_mon  = l_inscription_month - 1;   /* janvier            */
	    l_inscription.tm_year = l_inscritpion_year - 1900; /* 2000 (2000 - 1900) */
	    l_inscription.tm_hour = 0;   /* 0 heure            */
	    l_inscription.tm_min  = 0;   /* 0 minute           */
	    l_inscription.tm_sec  = 0;   /* 0 seconde          */

	    time_t l_inscription_date = mktime(&l_inscription);

	    time_t l_duration_time = (time_t)difftime(l_today, l_inscription_date);
	    struct tm * l_duration = localtime(&l_duration_time);
	    std::cout << (l_duration->tm_year - 70 ) << " year " << (l_duration->tm_mon ) << " months " << l_duration->tm_mday << " days" << std::endl ;
	    if((l_duration->tm_year - 70 )== 0 && l_duration->tm_mon == 0)
	      {
		m_report << "\"" << m_user_name << "\" : " << l_date << std::endl ;
	      } 
	  }
      }
  }

  //------------------------------------------------------------------------------
  void new_user_analyzer::get_attribute(const std::string & p_name,const std::string & p_value)
  {
    if(p_name == "uid") m_uid = atoi(p_value.c_str());
    if(p_name == "user") m_user_name = p_value;
  }

  //TO DELETE  //------------------------------------------------------------------------------
  //TO DELETE  std::string new_user_analyzer::get_user_inscription_date(const std::string & p_user)const
  //TO DELETE  {
  //TO DELETE    std::string l_user = p_user;
  //TO DELETE    std::string l_user_date;

  //TO DELETE    std::string l_user_url("http://www.openstreetmap.org/user/");
  //TO DELETE    url_reader l_url_reader;
  //TO DELETE    char * l_escaped_user = l_url_reader.escape_string(l_user.c_str());
  //TO DELETE    l_user_url += l_escaped_user;
  //TO DELETE    download_buffer l_buffer;
  //TO DELETE    l_url_reader.read_url(l_user_url.c_str(),l_buffer);
  //TO DELETE    curl_free(l_escaped_user);

  //TO DELETE    std::stringstream l_stream;
  //TO DELETE    l_stream << l_buffer.get_data();
  //TO DELETE    std::string l_line;
  //TO DELETE    bool l_found = false;
  //TO DELETE    while(!l_found && !getline(l_stream,l_line).eof())
  //TO DELETE      {
  //TO DELETE	size_t l_pos ;
  //TO DELETE	// expecting line like "Mapper since: August 13, 2009"
  //TO DELETE	if((l_pos = l_line.find("Mapper since:")) != std::string::npos)
  //TO DELETE	  {
  //TO DELETE	    size_t l_begin = l_line.find(":",l_pos);
  //TO DELETE	    l_begin = l_line.find_first_not_of(" ",l_begin+1);
  //TO DELETE	    l_user_date = l_line.substr(l_begin);
  //TO DELETE	    l_found = true;
  //TO DELETE	  }
  //TO DELETE      }
  //TO DELETE    assert(l_found);
  //TO DELETE    return l_user_date;
  //TO DELETE  }
}
//EOF
