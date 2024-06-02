CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lpthread

TARGETS = server client

# Regla para compilar todos los objetivos
all: $(TARGETS)

# Regla para compilar el servidor
server: main.o server.o game.o socket_utils.o 
	$(CXX) -o $@ $^ $(LDFLAGS)

# Regla para compilar el cliente
client: main.o client.o game.o socket_utils.o
	$(CXX) -o $@ $^ $(LDFLAGS)

# Regla para compilar el archivo main.cpp
main.o: main.cpp game.hpp socket_utils.hpp start.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Regla para compilar el archivo server.cpp
server.o: server.cpp game.hpp socket_utils.hpp start.hpp
	$(CXX) $(CXXFLAGS) -c server.cpp

# Regla para compilar el archivo client.cpp
client.o: client.cpp game.hpp socket_utils.hpp start.hpp
	$(CXX) $(CXXFLAGS) -c client.cpp

# Regla para compilar el archivo game.cpp
game.o: game.cpp game.hpp
	$(CXX) $(CXXFLAGS) -c game.cpp

# Regla para compilar el archivo socket_utils.cpp
socket_utils.o: socket_utils.cpp socket_utils.hpp
	$(CXX) $(CXXFLAGS) -c socket_utils.cpp

# Regla para limpiar los archivos compilados
clean:
	rm -f *.o $(TARGETS)