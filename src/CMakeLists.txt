
# Set the C++ standard to be used
# -std=c++11 is a GCC only flag. So don't use that.
set (CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/inc/)
include_directories(${PROJECT_SOURCE_DIR}/fonts/)
include_directories(${PROJECT_SOURCE_DIR}/images/)

# Set source files
set (SOURCE_FILES main.cpp Arkanoid.cpp GameGenerics.cpp MineSweeper.cpp Snake.cpp Tetris.cpp)

# Look for SFML and add it
find_package (SFML REQUIRED system window graphics network audio)

# We add the executable of the program
add_executable (Gameboy ${SOURCE_FILES})
target_link_libraries(Gameboy PUBLIC sfml-system sfml-window sfml-graphics)

install(TARGETS Gameboy)