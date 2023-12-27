set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/adder/adder.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/utils.cpp
)

add_library(jcal-core SHARED ${SOURCES})

target_compile_definitions(jcal-core PRIVATE
    JUMI_EXPORT_API
)

if (WIN32)
    target_compile_definitions(jcal-core PUBLIC JUMI_WINDOWS)
endif()

target_include_directories(jcal-core
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/jcal-core
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)
