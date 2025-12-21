cmake_minimum_required(VERSION 3.16)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

# Get all .cpp files in the project folder
file(GLOB CPP_FILES "*.cpp")

# For each .cpp file, create an executable
foreach(file ${CPP_FILES})
    # Get the filename without extension
    get_filename_component(fname ${file} NAME_WE)
    add_executable(${fname} ${file}
            BankQueue.cpp
            Sorting.cpp
            DoublyLinkedList.cpp
            Stack_LinkedList.cpp
            MergeSort.cpp
            QuickSort.cpp
            Advanced_Sorting.cpp
            QueueLinkedList.cpp)
endforeach()
