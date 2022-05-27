#
# Compiler
#
CC = gcc
CFLAGS = -Wall -Werror -Wextra
BUILD = DEBUG

ifeq ($(build),DEBUG)
	CFLAGS += -g3 -Og
else
	CFLAGS += -g0 -O3 -s	
endif

#
# Program version info
#
PROJ_NAME = $(shell basename $(CURDIR))
COPYRIGHT = Copyright (c) 2022 aaf6
BUILD_TIME = $(shell date -u --iso=seconds)

DEFINES = -DPROJ_NAME="\"$(PROJ_NAME)\"" -DBUILD="\"$(BUILD)\"" -DCOPYRIGHT="\"$(COPYRIGHT)\"" -DBUILD_TIME="\"$(BUILD_TIME)\""

# git info
GIT_VERSION = $(shell git describe --tags)@$(shell git rev-parse --abbrev-ref HEAD)
GIT_ORIGIN = $(shell git config --get remote.origin.url)

DEFINES += -DGIT_VERSION="\"$(GIT_VERSION)\"" -DGIT_ORIGIN="\"$(GIT_ORIGIN)\""

#
# Targets
#
all: build/$(PROJ_NAME)
build/$(PROJ_NAME): obj/$(PROJ_NAME).o
	@$(CC) $(LDFLAGS) -o build/$(PROJ_NAME) obj/$(PROJ_NAME).o $(LDLIBS)
obj/$(PROJ_NAME).o: dir src/$(PROJ_NAME).c
	@$(CC) $(DEFINES) $(CFLAGS) -o obj/$(PROJ_NAME).o -c src/$(PROJ_NAME).c
dir:
	@mkdir -p build
	@mkdir -p obj
clean:
	@rm -f build/main obj/*