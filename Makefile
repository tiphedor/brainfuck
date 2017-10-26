# Note that i essentially stole Yanick Rochon's work from here : https://stackoverflow.com/questions/7004702/how-can-i-create-a-makefile-for-c-projects-with-src-obj-and-bin-subdirectories
# Thank you, Yanick Rochon. I hate creating makefiles.

TARGET   = bf

CC       = gcc
CFLAGS   = -Wall -Wextra -Werror -I. -g
LINKER   = gcc
LFLAGS   = -Wall -Wextra -Werror -g

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -rf

INSTALL_LOCATION = /usr/local/bin

.PHONY: clean fclean re all install

all: $(BINDIR)/$(TARGET)
$(BINDIR)/$(TARGET): $(OBJECTS)
	$(LINKER) $(OBJECTS) $(LFLAGS) -o $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(rm) $(OBJECTS)
fclean: clean
	$(rm) $(BINDIR)/$(TARGET)
re: fclean all

install: all
	cp $(BINDIR)/$(TARGET) $(INSTALL_LOCATION)
