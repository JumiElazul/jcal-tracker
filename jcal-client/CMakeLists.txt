set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/application/main.cpp
)

add_executable(jcal-client ${SOURCES})

target_link_libraries(jcal-client PRIVATE jcal-core)

target_include_directories(jcal-client PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
