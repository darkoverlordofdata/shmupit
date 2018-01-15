cmake_minimum_required ( VERSION 3.1 )
#########################################################################################
#
#   Library: MersenneTwister
#
#########################################################################################
project ( mt19937 VERSION 0.1.0 )
set ( C_SOURCES "${C_SOURCES};.lib/mt19937/src/mt19937ar.c" PARENT_SCOPE )
set ( CUSTOM_VAPIS "${CUSTOM_VAPIS};${CMAKE_SOURCE_DIR}/.lib/mt19937/vapis/mt19937ar.vapi" PARENT_SCOPE )
set ( INCLUDES "${INCLUDES}; .lib/mt19937/include" PARENT_SCOPE)