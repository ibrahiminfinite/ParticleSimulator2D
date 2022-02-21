cmake_minimum_required(VERSION 3.1)
project(ParticleSimulator)

set(CMAKE_CXX_STANDARD 14)

find_package(Eigen3 REQUIRED NO_MODULE)
add_definitions     ( ${EIGEN3_DEFINITIONS} )
include_directories ( ${EIGEN3_INCLUDE_DIRS} )


find_package(OpenCV 4.1 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

add_executable(simulator main.cpp Particle.cpp Box.cpp ParticleDynamics.cpp Renderer.cpp ParticleGenerator.cpp Simulator.cpp )
target_link_libraries (simulator ${OpenCV_LIBRARIES} )
