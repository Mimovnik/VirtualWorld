cmake_minimum_required(VERSION 3.0.0)
project(virtualWorld VERSION 0.1.0)

add_library(
    SOURCE_FILES

    src/settings.hpp
    
    src/World.hpp
    src/World.cpp

    src/Vector.hpp
    src/Vector.cpp

    src/Organism.hpp
    src/Organism.cpp

    src/Animal.hpp
    src/Animal.cpp

    src/animals/Wolf.hpp
    src/animals/Wolf.cpp

    src/animals/Sheep.hpp
    src/animals/Sheep.cpp

    src/animals/Fox.hpp
    src/animals/Fox.cpp

    src/animals/Turtle.hpp
    src/animals/Turtle.cpp

    src/animals/Antelope.hpp
    src/animals/Antelope.cpp

    src/animals/Human.hpp
    src/animals/Human.cpp
    
    src/Plant.hpp
    src/Plant.cpp

    src/plants/Grass.hpp
    src/plants/Grass.cpp

    src/plants/Dandelion.hpp
    src/plants/Dandelion.cpp

    src/plants/Guarana.hpp
    src/plants/Guarana.cpp

    src/plants/Wolfberry.hpp
    src/plants/Wolfberry.cpp

    src/plants/PineBorscht.hpp
    src/plants/PineBorscht.cpp
)

add_executable(virtualWorld src/main.cpp)

target_link_libraries(${PROJECT_NAME} SOURCE_FILES)
