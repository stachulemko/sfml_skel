# Definiowanie plików źródłowych i bibliotek
C_FILES         := $(wildcard tests/*.c)
CPP_FILES       := $(wildcard tests/*.cpp)
RC_FILES        := $(wildcard res/*.rc)
O_FILES         := $(patsubst tests/%.c,build/%.o,$(C_FILES)) $(patsubst tests/%.cpp,build/%.o,$(CPP_FILES)) $(patsubst res/%.rc,build/%.o,$(RC_FILES))
LIB_FILES       := $(wildcard lib/*.a) $(wildcard lib/*.*.a)

# Definiowanie flag kompilacji
C_FLAGS         := -std=c18 -pedantic -Wextra -Wall -O3
CPP_FLAGS       := -std=c++2a -pedantic -Wextra -Wall -O3  

# Dodanie katalogów z plikami nagłówkowymi
INCLUDE_DIRECTORIES := -Iinclude 

# Katalog wyjściowy dla plików obiektowych
BUILD_DIR := build

# Reguła do tworzenia katalogu wyjściowego
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Kompilacja aplikacji
app: $(BUILD_DIR) $(O_FILES)
	g++ -mconsole $(O_FILES) -o $@ $(LIB_FILES)

# Kompilacja plików .cpp do .o
$(BUILD_DIR)/%.o: tests/%.cpp | $(BUILD_DIR)
	g++ -c $< -o $@ $(INCLUDE_DIRECTORIES) $(CPP_FLAGS) 

# Kompilacja plików .c do .o
$(BUILD_DIR)/%.o: tests/%.c | $(BUILD_DIR)
	gcc -c $< -o $@ $(INCLUDE_DIRECTORIES) $(C_FLAGS)

# Kompilacja plików .rc do .o
$(BUILD_DIR)/%.o: res/%.rc | $(BUILD_DIR)
	windres $< -O coff -o $@

# Czyszczenie plików obiektowych i aplikacji
clean:
	del build\*.o
	del app.exe

# Uruchamianie aplikacji na Windows
run: app
	.\app.exe
