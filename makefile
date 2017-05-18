SOURCE = src
DROP = drop

TARGET = driver
CC = g++
LUA_LIB = lua

install:
	$(CC) -o $(DROP)/$(TARGET).exe $(SOURCE)/$(TARGET).cpp -l$(LUA_LIB) -ldl
	
clean:
	rm $(DROP)/$(TARGET).exe