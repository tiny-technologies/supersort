SHELL = /bin/sh

# directory paths
BUILDDIR = ./build
SRCDIR = ./src

SRCLIST = $(wildcard $(SRCDIR)/*.*)



.PHONY: all 
all: $(BUILDDIR)/supersort

$(BUILDDIR)/supersort: $(SRCLIST) | $(BUILDDIR)
	gcc -Wall -g $^ -o $@

$(BUILDDIR):
	@mkdir $@
	@echo $@ directoy created



.PHONY: clean
clean:
	@rm -r build
