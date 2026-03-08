# List of subdirectories
SUBDIRS = q_1 q_2

# The default rule
all:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

# Clean everything
clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done