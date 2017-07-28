# Define two variables in order not to repeat ourselves.
set(LIBRARY_NAME "${PROJECT_NAME}")

set(EXAMPLE_APPLICATION_NAME "${PROJECT_NAME}_run")

prepend(LIB_HEADERS "${CMAKE_CURRENT_BINARY_DIR}/../include/${PROJECT_NAME}" ${HEADER_FILES})

set(LIB_SOURCES
	version.cpp
)


set(APP_SOURCES
    example.cpp
)


# Define the library
add_library(${LIBRARY_NAME} SHARED ${LIB_SOURCES})

# Set the build version. It will be used in the name of the lib, with corresponding
# symlinks created. SOVERSION could also be specified for api version. 
set_target_properties(${LIBRARY_NAME} PROPERTIES
    VERSION ${VERSION}  # ${VERSION} was defined in the main CMakeLists.
    FRAMEWORK FALSE
    PUBLIC_HEADER "${LIB_HEADERS}" # specify the public headers
)

# expose header files to other libraries
target_include_directories(${LIBRARY_NAME}
    PUBLIC 
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/../include/
)

# This is a make target, so you can do a "make projBrunner"
add_executable(${EXAMPLE_APPLICATION_NAME} ${APP_SOURCES})

target_link_libraries(${EXAMPLE_APPLICATION_NAME} ${LIBRARY_NAME} )

configure_file("test.sh" "${BIN_DIR}/test.sh" COPYONLY)
