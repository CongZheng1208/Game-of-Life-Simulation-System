# CMake generated Testfile for 
# Source directory: /workspaces/PHAS0100Assignment1/Testing
# Build directory: /workspaces/PHAS0100Assignment1/build/Testing
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(NoArgs "/workspaces/PHAS0100Assignment1/build/bin/golBasicTest")
set_tests_properties(NoArgs PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/PHAS0100Assignment1/Testing/CMakeLists.txt;36;add_test;/workspaces/PHAS0100Assignment1/Testing/CMakeLists.txt;0;")
add_test(1File "/workspaces/PHAS0100Assignment1/build/bin/golCommandLineArgsTest" "/workspaces/PHAS0100Assignment1/Testing/Data/input.txt")
set_tests_properties(1File PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/PHAS0100Assignment1/Testing/CMakeLists.txt;37;add_test;/workspaces/PHAS0100Assignment1/Testing/CMakeLists.txt;0;")
