objects = main.o
target = problem003

$(target) : $(objects)
	$(CXX) -o $(target) $(objects)

main.o :
	$(CXX) -c main.cpp

clean :
	rm -f $(target) $(objects)
