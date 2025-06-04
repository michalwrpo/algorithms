CXX := g++
CXX_WARN := -Wall -Wextra -Werror -Wsign-conversion -Wpedantic

random:
	$(CXX) $(CXX_WARN) randomlists/random_list.cpp -o rand.out
	$(CXX) $(CXX_WARN) randomlists/random_increasing.cpp -o incrand.out
	$(CXX) $(CXX_WARN) randomlists/random_nondecreasing.cpp -o nondecrand.out
	$(CXX) $(CXX_WARN) randomlists/random_decreasing.cpp -o decrand.out
	$(CXX) $(CXX_WARN) randomlists/random_nonincreasing.cpp -o nonincrand.out

clean:
	rm -rf *.out