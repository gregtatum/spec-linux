CC := gcc
BIN_DIR := .
BUILD_DIR := build
SRC_EXT := c
CFLAGS :=
LIB :=
INCLUDES :=

SRC_DIR := src
BUILD_DIR := $(BUILD_DIR)
CODE_TARGET := $(BIN_DIR)/linux-app
SOURCES := $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))
CODE_OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRC_EXT)=.o))

#Compile to objects
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(shell echo $@ | sed -e 's/\/[^\/]*\.o//g')
	@echo " Compile Code: $(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<"; $(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

#Link binary file
$(CODE_TARGET): $(CODE_OBJECTS)
	@mkdir -p $(BIN_DIR)
	@echo " Link Code: $(CC) $^ -o $(CODE_TARGET) $(LIB)"; $(CC) $^ -o $(CODE_TARGET) $(CFLAGS) $(LIB)

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r ./$(BUILD_DIR)"; $(RM) -r ./$(BUILD_DIR)

.PHONY: clean
