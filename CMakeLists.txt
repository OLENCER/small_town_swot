cmake_minimum_required(VERSION 3.24)
project(small_town_swot)

set(CMAKE_CXX_STANDARD 17)

add_executable(leetcode1       leetcode/1-two-sum.cpp)
add_executable(leetcode2       leetcode/2-add-two-numbers.cpp)
add_executable(leetcode15      leetcode/15-3sum.cpp)
add_executable(leetcode18      leetcode/18-4Sum.cpp)
add_executable(leetcode28      leetcode/28-find-the-index-of-the-first-occurrence-in-a-string.cpp)
add_executable(leetcode443     leetcode/443-string-compression.cpp)
add_executable(leetcode875     leetcode/875-koko-eating-bananas.cpp)
#unfinished
#add_executable(leetcode982     leetcode/982-triples-with-bitwise-and-equal-to-zero.cpp)
add_executable(leetcode1345     leetcode/1345-jump-game-iv.cpp)
add_executable(leetcode1487    leetcode/1487-making-file-names-unique.cpp)
#unfinished
#add_executable(leetcode1599    leetcode/1599-maximum-profit-of-operating-a-centennial-wheel.cpp)
add_executable(leetcode2187    leetcode/2187-minimum-time-to-complete-trips.cpp)
add_executable(leetcode2444    leetcode/2444-count-subarrays-with-fixed-bounds.cpp)

include_directories("D:\\boost_1_81_0\\boost")
link_directories("D:\\boost_1_81_0\\libs")