objects = main.o fib.o
target = problem002
CXXFLAGS = -std=c++11

$(target) : $(objects)
	$(CXX) $(CXXFLAGS) -o $(target) $(objects)

main.o :
	$(CXX) $(CXXFLAGS) -c main.cpp

fib.o :
	$(CXX) $(CXXFLAGS) -c fib.cpp

clean :
	rm -f $(target) $(objects)
