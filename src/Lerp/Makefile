# Toolchain/Environment
SHELL := /bin/bash
CC    := g++


# Options
INSTALLDIR := $(CURDIR)
CFLAGS     := -Wall


# Files
SUBSYSTEM := Lerp
SOURCES   := $(wildcard *.cpp)
HEADERS   := $(wildcard *.h)


# General targets
.PHONY: install clean


default:
# Since this is a templated library there's nothing to do here;
# it will be generated at compile-time when the user instantiates it.


# Install the headers files.
install:
# Make sure an include directory exists
	@if [ ! -e "$(INSTALLDIR)/include" ]; then \
		mkdir "$(INSTALLDIR)/include"; \
		mkdir "$(INSTALLDIR)/include/$(SUBSYSTEM)"; \
	elif [ ! -d "$(INSTALLDIR)/include" ]; then \
		echo "Failed to install headers files."; \
		echo "$(INSTALLDIR)/include is not a valid directory."; \
		exit 1; \
	else \
		if [ ! -e "$(INSTALLDIR)/include/$(SUBSYSTEM)" ]; then \
			mkdir "$(INSTALLDIR)/include/$(SUBSYSTEM)"; \
		elif [ ! -d "$(INSTALLDIR)/include/$(SUBSYSTEM)" ]; then \
			echo "Failed to install headers files."; \
			echo "$(INSTALLDIR)/include/$(SUBSYSTEM) is not a valid directory."; \
			exit 1; \
		fi \
	fi
# Install the header files
	@for file in $(HEADERS); do \
		cp "$$file" "$(INSTALLDIR)/include/$(SUBSYSTEM)"; \
	done


clean:
# There are no output files to remove.
