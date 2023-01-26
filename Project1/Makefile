TARGET = project1

$(TARGET).exe: $(TARGET).o
	g++ -g -ggdb -o $(TARGET).exe $(TARGET).o
$(TARGET).o: $(TARGET).cpp
	g++ -g -ggdb -c $(TARGET).o $(TARGET).cpp

run: $(TARGET).exe
	./$(TARGET).exe