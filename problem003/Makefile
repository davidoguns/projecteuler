objects = main.o
target = problem003

$(target) : $(objects)
	$(CXX) -o $(target) $(objects)

main.o :
	$(CXX) -c main.cpp

primes.o :
	$(CXX) -c primes.cpp

clean :
	rm -f $(target) $(objects)
