include(biicode/boost/setup)
ADD_BII_TARGETS()

bii_find_boost(COMPONENTS unit_test_framework REQUIRED)
 
target_include_directories(${BII_BLOCK_TARGET} INTERFACE ${Boost_INCLUDE_DIRS})
target_link_libraries(${BII_BLOCK_TARGET} INTERFACE ${Boost_LIBRARIES})

###############################################################################
#      HELP                                                                   #
###############################################################################
#
# This CMakeLists.txt file helps defining your block builds
# To learn more visit http://docs.biicode.com/c++.html
#
# To include published cmake scripts:
#   1. INCLUDE(user/block/myrecipe) # include myrecipe.cmake from remote user/block
#   2. Remember to execute bii find
#   Example:
#      INCLUDE(biicode/cmake/tools) # Include tools.cmake file from cmake block from "biicode" user
#      ACTIVATE_CPP11(INTERFACE ${BII_BLOCK_TARGET})
#
# Useful variables:
#   To be modified BEFORE the call to ADD_BII_TARGETS()
#     ${BII_LIB_SRC}  File list to create the library
#
#   To be modified AFTER the call to ADD_BII_TARGETS()
#     ${BII_BLOCK_TARGET}  Interface (no files) target for convenient configuration of all
#                          targets in this block, as the rest of targets always depend on it
#                          has name in the form "user_block_interface"
#     ${BII_LIB_TARGET}  Target library name, usually in the form "user_block". May not exist
#                        if BII_LIB_SRC is empty
#     ${BII_BLOCK_TARGETS} List of all targets defined in this block
#     ${BII_BLOCK_EXES} List of executables targets defined in this block
#     ${BII_exe_name_TARGET}: Executable target (e.g. ${BII_main_TARGET}. You can also use
#                            directly the name of the executable target (e.g. user_block_main)
#
# > EXAMPLE: Add include directories to all targets of this block
#
#    TARGET_INCLUDE_DIRECTORIES(${BII_BLOCK_TARGET} INTERFACE myincludedir)
#
# > EXAMPLE: Link with pthread:
#
#    TARGET_LINK_LIBRARIES(${BII_BLOCK_TARGET} INTERFACE pthread)
#        or link against library:
#    TARGET_LINK_LIBRARIES(${BII_LIB_TARGET} PUBLIC pthread)
#
#    NOTE:  This can be also done adding pthread to ${BII_LIB_DEPS}
#            BEFORE calling ADD_BIICODE_TARGETS()
#
# > EXAMPLE: how to activate C++11
#
#    IF(APPLE)
#         TARGET_COMPILE_OPTIONS(${BII_BLOCK_TARGET} INTERFACE "-std=c++11 -stdlib=libc++")
#    ELSEIF (WIN32 OR UNIX)
#         TARGET_COMPILE_OPTIONS(${BII_BLOCK_TARGET} INTERFACE "-std=c++11")
#    ENDIF(APPLE)
#
# > EXAMPLE: Set properties to target
#
#    SET_TARGET_PROPERTIES(${BII_BLOCK_TARGET} PROPERTIES COMPILE_DEFINITIONS "IOV_MAX=255")
#


