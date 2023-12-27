set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/application/main.cpp
)

add_executable(jcal_client ${SOURCES})

target_link_libraries(jcal_client PRIVATE jcal_core)

target_include_directories(jcal_client PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
