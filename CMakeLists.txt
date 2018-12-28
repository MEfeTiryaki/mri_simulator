# Specify the minimum version for CMake
cmake_minimum_required(VERSION 2.8)
project(mri_sim)

add_definitions("-std=c++11")

set(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(qt_gui_cpp_USE_QT_MAJOR_VERSION 5)

find_package(Eigen3 REQUIRED)

IF( Eigen3_FOUND )
	message(STATUS "Eigen is found.")
ELSE()
	message(WARNING "Eigen is not found!")
ENDIF()

if("${qt_gui_cpp_USE_QT_MAJOR_VERSION} " STREQUAL "5 ")
  find_package(Qt5Widgets REQUIRED)
	find_package(Qt5Gui REQUIRED)
	find_package(Qt5Core REQUIRED)
	find_package(Qt5PrintSupport REQUIRED)
else()
  find_package(Qt4
  	COMPONENTS
  		QtCore
  		QtGui
  		REQUIRED
  	)
  include(${QT_USE_FILE})
endif()

# For cmake problems refer https://stackoverflow.com/questions/47471629/fail-to-use-q-object-macro-in-cmake-project
set(plotgui_SRCS  PlotGui.cpp)
if("${qt_gui_cpp_USE_QT_MAJOR_VERSION} " STREQUAL "5 ")
	qt5_wrap_ui(plotgui_UIS_H plotgui.ui)
	qt5_wrap_cpp(plotgui_MOCS
		include/PlotGui.h
		include/qcustomplot.h)
else()
  qt4_wrap_cpp(plotgui_MOCS PlotGui.h)
  qt4_wrap_ui(plotgui_UIS_H plotgui.ui)
endif()

# The following folder will be included
#message(WARNING  	${CMAKE_CURRENT_BINARY_DIR})
include_directories(
	include
	${EIGEN3_INCLUDE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
)

add_library(${PROJECT_NAME}
SHARED
	src/OdeSolver.cpp
	src/RungeKutta.cpp
	src/SimplePendulumSolver.cpp
	src/PlotGui.cpp
	src/qcustomplot.cpp
	${plotgui_MOCS}
)
target_link_libraries(
	${PROJECT_NAME}
)

if("${qt_gui_cpp_USE_QT_MAJOR_VERSION} " STREQUAL "5 ")
	qt5_use_modules(${PROJECT_NAME} Core Gui Widgets PrintSupport)
	target_link_libraries(${PROJECT_NAME}
		Qt5::Widgets
		Qt5::Gui
		Qt5::Core
		Qt5::PrintSupport
	)
else()
  target_link_libraries(${PROJECT_NAME}
		${QT_QTCORE_LIBRARY}
		${QT_QTGUI_LIBRARY}
		)
endif()

add_executable(mrisim
	src/mri_sim.cpp
)
target_link_libraries(mrisim
  ${PROJECT_NAME}
)
