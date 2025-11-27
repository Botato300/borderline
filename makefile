CXX = g++
CXXFLAGS = -Wall -I include
LDFLAGS = -L lib/raylib -lraylib -lgdi32 -lwinmm 

NAME = borderline
EXT_FILENAME =
SOURCE_DIR = src
BUILD_DIR = build
DIST_DIR = dist

SOURCES := $(shell find "$(SOURCE_DIR)" -name "*.cpp")
OBJECTS := $(patsubst $(SOURCE_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

ifeq ($(OS),Windows_NT)
    EXT = .exe
endif

BIN = $(DIST_DIR)/$(NAME)$(EXT)

.PHONY: all run clean

all: $(BIN)
	@echo "[INFO]: There is nothing to update, everything is ok! :)"

$(BIN): $(OBJECTS) | $(DIST_DIR)
	$(CXX) $^ $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DIST_DIR):
	@mkdir -p $(DIST_DIR)
	@echo "[INFO]: ${DIST_DIR} directory created"

run: $(BIN)
	@echo "[INFO]: Running $(BIN)"
	@./$(BIN)

clean:
	@rm -rf $(BUILD_DIR) $(DIST_DIR)
	@echo "[INFO]: $(BUILD_DIR) and $(DIST_DIR) directories deleted"
