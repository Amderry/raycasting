# Цель компиляции
link_target = pseudo3d

# Библиотеки
LIBS = -lSDL2

# Флаги
CXXFLAGS = -std=c++20 -O2 -g 

# Объектовые файлы
objects = main.o \
					CApp.o \
					$(patsubst %.cpp,%.o,$(wildcard ./raycasting/*.cpp))

# Пересобираемые
rebuildables = $(objects) $(link_target)

# Правило сборки
$(link_target): $(objects)
	g++ -o $(link_target) $(objects) $(LIBS) $(CXXFLAGS)

# Правило создания .о файлов
%.o: %.cpp
	g++ -o $@ -c $< $(CXXFLAGS)

.PHONEY:
clean:
	rm $(rebuildables)
