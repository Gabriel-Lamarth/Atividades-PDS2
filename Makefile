CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude

TARGET = vpl_execution
OBJS = build/main.o build/Ponto.o build/Circulo.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

build/main.o: src/main.cpp include/Ponto.hpp include/Circulo.hpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o build/main.o

build/Ponto.o: src/entidades/Ponto.cpp include/Ponto.hpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c src/entidades/Ponto.cpp -o build/Ponto.o

build/Circulo.o: src/entidades/Circulo.cpp include/Circulo.hpp include/Ponto.hpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c src/entidades/Circulo.cpp -o build/Circulo.o

clean:
	rm -f build/*.o $(TARGET)

.PHONY: all clean
