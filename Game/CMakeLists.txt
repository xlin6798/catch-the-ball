set(HEADER_FILES
	Entity.h
	GameApp.h	
)

set(SOURCE_FILES
	Entity.cpp
	GameApp.cpp
	main.cpp
)

add_executable(Game ${HEADER_FILES} ${SOURCE_FILES})

include_directories(../Engine)

target_link_libraries(Game Engine)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Game)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)