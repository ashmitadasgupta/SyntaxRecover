# SyntaxRecover Makefile.
# We use .RECIPEPREFIX so command lines start with '>' instead of a TAB.
.RECIPEPREFIX = >

CC       = gcc
CSTD     = -std=c11 -D_POSIX_C_SOURCE=200809L
CFLAGS   = $(CSTD) -Wall -Wextra -g -Iinclude -Ibuild
GENFLAGS = $(CSTD) -g -Iinclude -Ibuild

TARGET   = build/syntaxrecover
OBJS     = build/lex.yy.o build/parser.tab.o build/token_stream.o build/typedefs.o build/edits.o build/recovery.o build/validator.o build/reporter.o build/main.o
$(TARGET): $(OBJS)
> $(CC) $(OBJS) -o $@

# --- generated files (Bison and Flex) ---
build/parser.tab.c: src/parser.y
> bison -d -o build/parser.tab.c src/parser.y

build/parser.tab.h: build/parser.tab.c
> @true

build/lex.yy.c: src/lexer.l build/parser.tab.h
> flex -o build/lex.yy.c src/lexer.l

# generated code is compiled without -Wall -Wextra: we don't control its style
build/lex.yy.o: build/lex.yy.c $(HEADERS)
> $(CC) $(GENFLAGS) -c build/lex.yy.c -o $@

build/parser.tab.o: build/parser.tab.c $(HEADERS)
> $(CC) $(GENFLAGS) -c build/parser.tab.c -o $@

# --- our own code ---
build/%.o: src/%.c $(HEADERS) build/parser.tab.h
> $(CC) $(CFLAGS) -c $< -o $@

clean:
> rm -f build/*

.PHONY: all clean