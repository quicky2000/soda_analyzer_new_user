#ifndef _COMMON_API_H_
#define _COMMON_API_H_

#include "common_api_if.h"

namespace osm_diff_analyzer_new_user
{
  class common_api
  {
  public:
    inline common_api(osm_diff_analyzer_if::module_library_if::t_register_function p_func);

    inline void get_user_subscription_date(const std::string & p_name,std::string & p_date,
					   void * p_user_data=NULL); 

    inline const osm_api_data_types::osm_node * get_node(const osm_api_data_types::osm_object::t_osm_id & p_id,
							 void * p_user_data=NULL);

    inline const osm_api_data_types::osm_node * get_node_version(const osm_api_data_types::osm_object::t_osm_id & p_id,
								 const osm_api_data_types::osm_core_element::t_osm_version & p_version=0,
								 void * p_user_data=NULL);

    inline const std::vector<osm_api_data_types::osm_node*> * const get_node_history(const osm_api_data_types::osm_object::t_osm_id & p_id,
										     void * p_user_data = NULL);

    inline const std::vector<osm_api_data_types::osm_way*> * const get_node_ways(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                                 void * p_user_data = NULL);

    inline const std::vector<osm_api_data_types::osm_relation*> * const get_node_relations(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                                 void * p_user_data = NULL);

    inline const std::vector<osm_api_data_types::osm_node*> * const get_nodes(const std::vector<osm_api_data_types::osm_object::t_osm_id> & p_ids,
									      void * p_user_data=NULL);

    inline const osm_api_data_types::osm_way * get_way(const osm_api_data_types::osm_object::t_osm_id & p_id,
						       void * p_user_data=NULL);

    inline const osm_api_data_types::osm_way * get_way_version(const osm_api_data_types::osm_object::t_osm_id & p_id,
							       const osm_api_data_types::osm_core_element::t_osm_version & p_version=0,
							       void * p_user_data=NULL);

    inline const std::vector<osm_api_data_types::osm_way*> * const get_way_history(const osm_api_data_types::osm_object::t_osm_id & p_id,
										   void * p_user_data = NULL);

    inline const std::vector<osm_api_data_types::osm_relation*> * const get_way_relations(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                                 void * p_user_data = NULL);

    inline const osm_api_data_types::osm_way * const get_way_full(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                  std::vector<osm_api_data_types::osm_node*> & p_nodes,
                                                                  void * p_user_data=NULL);

    inline const std::vector<osm_api_data_types::osm_way*> * const get_ways(const std::vector<osm_api_data_types::osm_object::t_osm_id> & p_ids,
									    void * p_user_data=NULL);

    inline const osm_api_data_types::osm_relation * get_relation(const osm_api_data_types::osm_object::t_osm_id & p_id,
						       void * p_user_data=NULL);

    inline const osm_api_data_types::osm_relation * get_relation_version(const osm_api_data_types::osm_object::t_osm_id & p_id,
							       const osm_api_data_types::osm_core_element::t_osm_version & p_version=0,
							       void * p_user_data=NULL);
    inline const std::vector<osm_api_data_types::osm_relation*> * const get_relation_history(const osm_api_data_types::osm_object::t_osm_id & p_id,
										   void * p_user_data = NULL);
    inline const std::vector<osm_api_data_types::osm_relation*> * const get_relation_relations(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                                 void * p_user_data = NULL);

    inline const osm_api_data_types::osm_relation * const get_relation_full(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                            std::vector<osm_api_data_types::osm_node*> & p_nodes,
                                                                            std::vector<osm_api_data_types::osm_way*> & p_ways,
                                                                            void * p_user_data=NULL);

    inline const std::vector<osm_api_data_types::osm_relation*> * const get_relations(const std::vector<osm_api_data_types::osm_object::t_osm_id> & p_ids,
									    void * p_user_data=NULL);
    inline const osm_api_data_types::osm_changeset * get_changeset(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                   void * p_user_data=NULL);
    inline const std::vector<osm_api_data_types::osm_change*> * const get_changeset_content(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                                            void * p_user_data = NULL);
    inline const std::vector<osm_api_data_types::osm_changeset* > * const get_changesets(const osm_api_data_types::osm_bounding_box & p_bounding_box,
                                                                                                const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                                                const std::string & p_user_name,
                                                                                                const std::string & p_time1,
                                                                                                const std::string & p_time2,
                                                                                                bool p_open,
                                                                                                bool p_close,
                                                                                                void * p_user_data=NULL);
    inline void get_map(const osm_api_data_types::osm_bounding_box & p_bounding_box,
                        std::vector<osm_api_data_types::osm_node*> & p_nodes,
                        std::vector<osm_api_data_types::osm_way*> & p_ways,
                        std::vector<osm_api_data_types::osm_relation*> & p_relations,
                        void *p_user_data=NULL);
  private:
    osm_diff_analyzer_if::common_api_if::t_get_user_subscription_date m_get_user_subscription_date;
    osm_diff_analyzer_if::common_api_if::t_get_node m_get_node;
    osm_diff_analyzer_if::common_api_if::t_get_node_version m_get_node_version;
    osm_diff_analyzer_if::common_api_if::t_get_node_history m_get_node_history;
    osm_diff_analyzer_if::common_api_if::t_get_node_ways m_get_node_ways;
    osm_diff_analyzer_if::common_api_if::t_get_node_relations m_get_node_relations;
    osm_diff_analyzer_if::common_api_if::t_get_nodes m_get_nodes;
    osm_diff_analyzer_if::common_api_if::t_get_way m_get_way;
    osm_diff_analyzer_if::common_api_if::t_get_way_version m_get_way_version;
    osm_diff_analyzer_if::common_api_if::t_get_way_history m_get_way_history;
    osm_diff_analyzer_if::common_api_if::t_get_way_relations m_get_way_relations;
    osm_diff_analyzer_if::common_api_if::t_get_way_full m_get_way_full;
    osm_diff_analyzer_if::common_api_if::t_get_ways m_get_ways;
    osm_diff_analyzer_if::common_api_if::t_get_relation m_get_relation;
    osm_diff_analyzer_if::common_api_if::t_get_relation_version m_get_relation_version;
    osm_diff_analyzer_if::common_api_if::t_get_relation_history m_get_relation_history;
    osm_diff_analyzer_if::common_api_if::t_get_relation_relations m_get_relation_relations;
    osm_diff_analyzer_if::common_api_if::t_get_relation_full m_get_relation_full;
    osm_diff_analyzer_if::common_api_if::t_get_relations m_get_relations;
    osm_diff_analyzer_if::common_api_if::t_get_changeset m_get_changeset;
    osm_diff_analyzer_if::common_api_if::t_get_changeset_content m_get_changeset_content;
    osm_diff_analyzer_if::common_api_if::t_get_changesets m_get_changesets;
    osm_diff_analyzer_if::common_api_if::t_get_map m_get_map;
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
      m_get_node = (osm_diff_analyzer_if::common_api_if::t_get_node)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_NODE];
      m_get_node_version = (osm_diff_analyzer_if::common_api_if::t_get_node_version)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_NODE_VERSION];
      m_get_node_history = (osm_diff_analyzer_if::common_api_if::t_get_node_history)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_NODE_HISTORY];
      m_get_node_ways = (osm_diff_analyzer_if::common_api_if::t_get_node_ways)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_NODE_WAYS];
      m_get_node_relations = (osm_diff_analyzer_if::common_api_if::t_get_node_relations)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_NODE_RELATIONS];
      m_get_nodes = (osm_diff_analyzer_if::common_api_if::t_get_nodes)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_NODES];
      m_get_way = (osm_diff_analyzer_if::common_api_if::t_get_way)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_WAY];
      m_get_way_version = (osm_diff_analyzer_if::common_api_if::t_get_way_version)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_WAY_VERSION];
      m_get_way_history = (osm_diff_analyzer_if::common_api_if::t_get_way_history)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_WAY_HISTORY];
      m_get_way_relations = (osm_diff_analyzer_if::common_api_if::t_get_way_relations)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_WAY_RELATIONS];
      m_get_way_full = (osm_diff_analyzer_if::common_api_if::t_get_way_full)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_WAY_FULL];
      m_get_ways = (osm_diff_analyzer_if::common_api_if::t_get_ways)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_WAYS];
      m_get_relation = (osm_diff_analyzer_if::common_api_if::t_get_relation)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_RELATION];
      m_get_relation_version = (osm_diff_analyzer_if::common_api_if::t_get_relation_version)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_RELATION_VERSION];
      m_get_relation_history = (osm_diff_analyzer_if::common_api_if::t_get_relation_history)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_RELATION_HISTORY];
      m_get_relation_relations = (osm_diff_analyzer_if::common_api_if::t_get_relation_relations)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_RELATION_RELATIONS];
      m_get_relation_full = (osm_diff_analyzer_if::common_api_if::t_get_relation_full)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_RELATION_FULL];
      m_get_relations = (osm_diff_analyzer_if::common_api_if::t_get_relations)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_RELATIONS];
      m_get_changeset = (osm_diff_analyzer_if::common_api_if::t_get_changeset)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_CHANGESET];
      m_get_changeset_content = (osm_diff_analyzer_if::common_api_if::t_get_changeset_content)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_CHANGESET_CONTENT];
      m_get_changesets = (osm_diff_analyzer_if::common_api_if::t_get_changesets)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_CHANGESETS];
      m_get_map = (osm_diff_analyzer_if::common_api_if::t_get_map)l_api_ptr[osm_diff_analyzer_if::common_api_if::GET_MAP];
    }

  //----------------------------------------------------------------------------
  void common_api::get_user_subscription_date(const std::string & p_name,std::string & p_date,void * p_user_data)
  {
    m_get_user_subscription_date(p_name,p_date,p_user_data);
  }

  //----------------------------------------------------------------------------
  const osm_api_data_types::osm_node * common_api::get_node(const osm_api_data_types::osm_object::t_osm_id & p_id,
							    void * p_user_data)
    {
      return m_get_node(p_id,p_user_data);
    }
  //----------------------------------------------------------------------------
  const osm_api_data_types::osm_node * common_api::get_node_version(const osm_api_data_types::osm_object::t_osm_id & p_id,
								    const osm_api_data_types::osm_core_element::t_osm_version & p_version,
								    void * p_user_data)
    {
      return m_get_node_version(p_id,p_version,p_user_data);
    }
  //----------------------------------------------------------------------------
  const std::vector<osm_api_data_types::osm_node*> * const common_api::get_node_history(const osm_api_data_types::osm_object::t_osm_id & p_id,
											void * p_user_data)
    {
      return m_get_node_history(p_id,p_user_data);
    }
  //----------------------------------------------------------------------------
  const std::vector<osm_api_data_types::osm_way*> * const common_api::get_node_ways(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                                    void * p_user_data)
    {
      return m_get_node_ways(p_id,p_user_data);
    }

  //----------------------------------------------------------------------------
  const std::vector<osm_api_data_types::osm_relation*> * const common_api::get_node_relations(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                                              void * p_user_data)
    {
      return m_get_node_relations(p_id,p_user_data);
    }

  //----------------------------------------------------------------------------
  const std::vector<osm_api_data_types::osm_node*> * const common_api::get_nodes(const std::vector<osm_api_data_types::osm_object::t_osm_id> & p_ids,
										 void * p_user_data)
    {
      return m_get_nodes(p_ids,p_user_data);
    }
  //----------------------------------------------------------------------------
  const osm_api_data_types::osm_way * common_api::get_way(const osm_api_data_types::osm_object::t_osm_id & p_id,
							  void * p_user_data)
    {
      return m_get_way(p_id,p_user_data);
    }
  //----------------------------------------------------------------------------
  const osm_api_data_types::osm_way * common_api::get_way_version(const osm_api_data_types::osm_object::t_osm_id & p_id,
								  const osm_api_data_types::osm_core_element::t_osm_version & p_version,
								  void * p_user_data)
    {
      return m_get_way_version(p_id,p_version,p_user_data);
    }
  //----------------------------------------------------------------------------
  const std::vector<osm_api_data_types::osm_way*> * const common_api::get_way_history(const osm_api_data_types::osm_object::t_osm_id & p_id,
											void * p_user_data)
    {
      return m_get_way_history(p_id,p_user_data);
    }
  //----------------------------------------------------------------------------
  const std::vector<osm_api_data_types::osm_relation*> * const common_api::get_way_relations(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                                              void * p_user_data)
    {
      return m_get_way_relations(p_id,p_user_data);
    }

  //----------------------------------------------------------------------------
  const osm_api_data_types::osm_way * const common_api::get_way_full(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                     std::vector<osm_api_data_types::osm_node*> & p_nodes,
                                                                     void * p_user_data)
    {
      return m_get_way_full(p_id,p_nodes,p_user_data);
    }


  //----------------------------------------------------------------------------
  const std::vector<osm_api_data_types::osm_way*> * const common_api::get_ways(const std::vector<osm_api_data_types::osm_object::t_osm_id> & p_ids,
										 void * p_user_data)
    {
      return m_get_ways(p_ids,p_user_data);
    }
  //----------------------------------------------------------------------------
  const osm_api_data_types::osm_relation * common_api::get_relation(const osm_api_data_types::osm_object::t_osm_id & p_id,
							  void * p_user_data)
    {
      return m_get_relation(p_id,p_user_data);
    }
  //----------------------------------------------------------------------------
  const osm_api_data_types::osm_relation * common_api::get_relation_version(const osm_api_data_types::osm_object::t_osm_id & p_id,
								  const osm_api_data_types::osm_core_element::t_osm_version & p_version,
								  void * p_user_data)
    {
      return m_get_relation_version(p_id,p_version,p_user_data);
    }
  //----------------------------------------------------------------------------
  const std::vector<osm_api_data_types::osm_relation*> * const common_api::get_relation_history(const osm_api_data_types::osm_object::t_osm_id & p_id,
											void * p_user_data)
    {
      return m_get_relation_history(p_id,p_user_data);
    }
  //----------------------------------------------------------------------------
  const std::vector<osm_api_data_types::osm_relation*> * const common_api::get_relation_relations(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                                              void * p_user_data)
    {
      return m_get_relation_relations(p_id,p_user_data);
    }

  //----------------------------------------------------------------------------
  const osm_api_data_types::osm_relation * const common_api::get_relation_full(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                            std::vector<osm_api_data_types::osm_node*> & p_nodes,
                                                                            std::vector<osm_api_data_types::osm_way*> & p_ways,
                                                                            void * p_user_data)
    {
      return m_get_relation_full(p_id,p_nodes,p_ways,p_user_data);
    }

  //----------------------------------------------------------------------------
  const std::vector<osm_api_data_types::osm_relation*> * const common_api::get_relations(const std::vector<osm_api_data_types::osm_object::t_osm_id> & p_ids,
										 void * p_user_data)
    {
      return m_get_relations(p_ids,p_user_data);
    }

  //----------------------------------------------------------------------------
  const osm_api_data_types::osm_changeset * common_api::get_changeset(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                      void * p_user_data)
    {
      return m_get_changeset(p_id,p_user_data);
    }
  //----------------------------------------------------------------------------
  const std::vector<osm_api_data_types::osm_change*> * const common_api::get_changeset_content(const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                                               void * p_user_data)
    {
      return m_get_changeset_content(p_id,p_user_data);
    }
  //----------------------------------------------------------------------------
  const std::vector<osm_api_data_types::osm_changeset* > * const common_api::get_changesets(const osm_api_data_types::osm_bounding_box & p_bounding_box,
                                                                                            const osm_api_data_types::osm_object::t_osm_id & p_id,
                                                                                            const std::string & p_user_name,
                                                                                            const std::string & p_time1,
                                                                                            const std::string & p_time2,
                                                                                            bool p_open,
                                                                                            bool p_close,
                                                                                            void * p_user_data)
    {
      return m_get_changesets(p_bounding_box,p_id,p_user_name,p_time1,p_time2,p_open,p_close,p_user_data);
    }
  //----------------------------------------------------------------------------
  void common_api::get_map(const osm_api_data_types::osm_bounding_box & p_bounding_box,
                           std::vector<osm_api_data_types::osm_node*> & p_nodes,
                           std::vector<osm_api_data_types::osm_way*> & p_ways,
                           std::vector<osm_api_data_types::osm_relation*> & p_relations,
                           void *p_user_data)
  {
    return m_get_map(p_bounding_box,p_nodes,p_ways,p_relations,p_user_data);
  }

}
#endif // _COMMON_API_H_
//EOF
