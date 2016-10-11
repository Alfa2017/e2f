all:
		g++ -Wall -O3 -std=c++11 main.cpp algo.cpp -o f2e
utest:
		g++ -Wall -DUTEST -O3 -std=c++11 main.cpp algo.cpp unittest.cpp -o f2e
		./f2e words dict
clean:
rm -rf f2e