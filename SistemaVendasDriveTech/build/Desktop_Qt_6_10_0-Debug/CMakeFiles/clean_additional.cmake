# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/InterfaceSistemaVendasConcessionaria_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/InterfaceSistemaVendasConcessionaria_autogen.dir/ParseCache.txt"
  "InterfaceSistemaVendasConcessionaria_autogen"
  )
endif()
