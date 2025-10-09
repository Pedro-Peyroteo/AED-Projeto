# ==================================================
# Makefile for AED-PROJETO (Windows + MinGW compatible)
# ==================================================

# --- Compiler and flags ---
CC       := gcc
CFLAGS   := -Iinclude -Wall -Wextra -std=c11 -Wno-format
AR       := ar rcs

# --- Directories ---
SRCDIR   := src
INCDIR   := include
BUILDDIR := build

# --- Targets ---
TARGET   := $(BUILDDIR)/main.exe
LIB_NAME := cutils
LIB_FILE := $(BUILDDIR)/lib$(LIB_NAME).a

# --- Source and object files ---
LIB_SRC  := $(SRCDIR)/cutils.cj
APP_SRC  := $(SRCDIR)/main.c $(SRCDIR)/app.c
LIB_OBJ  := $(BUILDDIR)/cutils.o
APP_OBJ  := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(APP_SRC))

# ==================================================
# Rules
# ==================================================

# Default target
all: $(TARGET)

# --- Step 1: Build static library (.a) ---
$(LIB_FILE): $(LIB_OBJ)
	@if not exist "$(BUILDDIR)" mkdir "$(BUILDDIR)"
	$(AR) $(LIB_FILE) $(LIB_OBJ)
	@echo 📦 Built static library: $(LIB_FILE)

# --- Step 2: Link everything into main.exe ---
$(TARGET): $(APP_OBJ) $(LIB_FILE)
	$(CC) $(CFLAGS) $(APP_OBJ) -L$(BUILDDIR) -l$(LIB_NAME) -o $(TARGET)
	@echo ✅ Build complete: $(TARGET)

# --- Object file build rules ---
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@if not exist "$(BUILDDIR)" mkdir "$(BUILDDIR)"
	$(CC) $(CFLAGS) -c $< -o $@

# --- Cleanup ---
clean:
	@if exist "$(BUILDDIR)" rmdir /S /Q "$(BUILDDIR)"
	@echo 🧹 Cleaned build directory

# --- Run program ---
run: all
	@$(TARGET)

.PHONY: all clean run
