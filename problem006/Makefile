objects = main.o
target = problem006
CXXFLAGS = -std=c++11

$(target) : $(objects)
	$(CXX) $(CXXFLAGS) -o $(target) $(objects)

main.o :
	$(CXX) $(CXXFLAGS) -c main.cpp

clean :
	rm -f $(target) $(objects)
