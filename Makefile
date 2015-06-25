SOURCES = basecounter.cpp wordcounter.cpp checksumcounter.cpp
HEADERS = basecounter.h wordcounter.h checksumcounter.h

test: $(SOURCES) $(HEADERS) main.cpp
	$(CXX) $(SOURCES) main.cpp --std=c++11 -o test
