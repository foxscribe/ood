cmake_minimum_required(VERSION 3.14)
project(ood)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(sources
	"source/CCircleAdapter.cpp"
	"source/CConvexAdapter.cpp"
	"source/CPoint.cpp"
	"source/CRectangleAdapter.cpp"
	"source/CRenderWindowAdapter.cpp"
	"source/CShapeParser.cpp"
	"source/Main.cpp")

set(tests
  "tests/CCircleAdapter_tests.cpp"
  "tests/CConvexAdapter_tests.cpp"
  "tests/CRectangleAdapter_tests.cpp")

add_executable(run_tests ${sources} ${tests})
target_link_libraries(run_tests GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests)

add_executable(main ${sources} main.cpp)

target_link_libraries(run_tests sfml-graphics sfml-window sfml-system)
target_link_libraries(main sfml-graphics sfml-window sfml-system)
