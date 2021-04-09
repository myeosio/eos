#include <eosio/net_plugin/security_group_manager.hpp>

namespace eosio {
   bool security_group_manager::update_cache(const uint32_t version, const participant_list_t& participant_list) {
      if(version == version_)
         return false;
      ilog("REM update_cache version changed");
      version_ = version;
      cache_ = participant_list;
      for (const auto& part : cache_) {
         ilog("REM participant: ${part}",("part",part.to_string()));
      }
      return true;
   }
}
