objects = main.o primes.o
target = problem003
CXXFLAGS = -std=c++11

$(target) : $(objects)
	$(CXX) $(CXXFLAGS) -o $(target) $(objects)

main.o :
	$(CXX) $(CXXFLAGS) -c main.cpp

primes.o :
	$(CXX) $(CXXFLAGS) -c primes.cpp

clean :
	rm -f $(target) $(objects)
