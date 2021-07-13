CXX = @g++
CFLAGS  = -c -g -Wall -std=c++11

MAINFILE = ./source/main.cpp
CODEDIR = ./source/code
EXEC = install

all:
	$(CXX) $(CFLAGS) $(CODEDIR)/*.cpp
	$(CXX) $(CFLAGS) $(MAINFILE)

	$(CXX) -o $(EXEC) *.o
	@$(RM) *.o

	@echo "All right!"
	@echo "./$(EXEC) [--ip; --boot; --sysupgrade]"
