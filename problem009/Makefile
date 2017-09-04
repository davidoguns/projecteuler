objects = main.o
target = problem009 
CXXFLAGS = -std=c++14

$(target) : $(objects)
	$(CXX) $(CXXFLAGS) -o $(target) $(objects)

main.o :
	$(CXX) $(CXXFLAGS) -c main.cpp

clean :
	rm -f $(target) $(objects)
