cmake_minimum_required(VERSION 3.16...3.29)

set(MAIN_FILES ${CPP_FILES} ${HEADERS})

add_executable(Trinagle
    ${MAIN_FILES}
    ${GL_C_FILE}
)

target_link_directories(Trinagle PRIVATE Dependencies)

target_link_libraries(Trinagle ${GLFW3} OpenGL::GL)

set_target_properties(Trinagle PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Export_Files
    # LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Export_Files/bin
)
