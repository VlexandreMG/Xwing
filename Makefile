CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Isrc
LIBS     = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = src/main.cpp \
       src/Fenetre.cpp \
       src/SceneAccueil.cpp \
       src/Jeu.cpp

xwing: $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o xwing $(LIBS)

clean:
	rm -f xwing

.PHONY: clean
