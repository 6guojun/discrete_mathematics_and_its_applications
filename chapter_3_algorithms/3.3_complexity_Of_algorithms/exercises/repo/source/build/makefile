##########################################################################################
# Simple Makefile to build the Chapter 3.3 Exercises
# It will build the test cases and all problem solutions
# Rakesh Kumar @ cpp.rakesh(at)gmail.com
# Date: Feb 9th, 2017
##########################################################################################

SRC_PATH := ../source/src
OBJ_PATH := objs

SRC_FILES := $(wildcard $(SRC_PATH)/*.cpp)
OBJ_FILES := $(addprefix $(OBJ_PATH)/,$(notdir $(SRC_FILES:.cpp=.o)))

INC         := -I ../source/inc
TEST_INC    := -I ../test/inc
INTEGER_INC := -I ~/git_hub/Utility/integer/inc/
MATHS_INC   := -I ~/git_hub/Utility/maths/inc/
COMMON_INC  := -I ~/git_hub/Utility/common/inc/
SEARCH_INC  := -I ~/git_hub/Utility/algorithms/search/inc
SORT_INC    := -I ~/git_hub/Utility/algorithms/sort/inc

INCLUDES := $(INC)
INCLUDES += $(TEST_INC)
INCLUDES += $(INTEGER_INC)
INCLUDES += $(MATHS_INC)
INCLUDES += $(COMMON_INC)
INCLUDES += $(SOURCE_INC)
INCLUDES += $(SEARCH_INC)
INCLUDES += $(SORT_INC)

UTILITY_LIB := -lutility
UTILITY_LIB_PATH := -L ~/git_hub/Utility/lib/

TARGET := exe

GXX := g++ -std=c++11
CC_FLAGS := -g -c -Wall -O3

$(TARGET) : $(OBJ_FILES) test
	@echo "Generating executable --> test"
	@$(GXX) -o $(TARGET) $(OBJ_PATH)/*.o $(UTILITY_LIB_PATH) $(UTILITY_LIB)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.cpp
	@echo "Compiling --> " $<
	@$(GXX) $(CC_FLAGS) $(INCLUDES) $< -o $@

test: $ ../test/src/Main.cpp
	@echo "Compiling the test file"
	@$(GXX) $(CC_FLAGS) $(INCLUDES) -o objs/TestSuite.o ../test/src/TestSuite.cpp
	@$(GXX) $(CC_FLAGS) $(INCLUDES) -o objs/Main.o ../test/src/Main.cpp

clean:
	@echo "Removing -->> all object files and executable"
	@rm -rf $(OBJ_PATH)/* $(TARGET)