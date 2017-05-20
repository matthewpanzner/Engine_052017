SOURCE = src
DROP = drop

TARGET = driver

CC = g++ 
CC_FLAG = -std=c++11
LUA_LIB = lua

install:
	@$(CC) $(CC_FLAG) \
	-o $(DROP)/$(TARGET).exe \
	$(SOURCE)/ECS/Entity/Entity.cpp  \
	$(SOURCE)/$(TARGET).cpp \
	-l$(LUA_LIB) -ldl
	
clean: 
	@echo "******************** Removing files in $(PWD)\$(DROP)\* ****************************"
	@rm $(DROP)/* -R -I