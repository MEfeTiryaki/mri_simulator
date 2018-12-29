# Specify the minimum version for CMake
cmake_minimum_required(VERSION 2.8)
project(mri_sim)

add_definitions("-std=c++11")

find_package(catkin REQUIRED
  COMPONENTS
    ode_solver
    plotgui
)

find_package(Eigen3 REQUIRED)

find_package(Qt5Widgets REQUIRED)

message(WARNING ${catkin_INCLUDE_DIRS})
catkin_package(
  INCLUDE_DIRS
  LIBRARIES
  CATKIN_DEPENDS
		ode_solver
    plotgui
  DEPENDS
)




# The following folder will be included
include_directories(
	include
  ${catkin_INCLUDE_DIRS}
	${EIGEN3_INCLUDE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
)


add_executable(mrisim
	src/mri_sim.cpp
)

target_link_libraries(mrisim
  #${PROJECT_NAME}
	${catkin_LIBRARIES}
  ${Qt5Widgets_LIBRARIES}
)
