set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/engine_core.cpp
)

add_library(jcal_core SHARED ${SOURCES})

target_compile_definitions(jcal_core PRIVATE
    JUMI_EXPORT_API
)

if (WIN32)
    target_compile_definitions(jcal_core PUBLIC JUMI_WINDOWS)
endif()

target_include_directories(jcal_core
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)
