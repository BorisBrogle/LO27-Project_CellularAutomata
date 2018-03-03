#My general makefile template
CXX=gcc
CFLAGS = -Wall -Werror -g -pedantic -o -I.

#application-related macros
TARGET = project
SOURCEFILE = project

#Generating the executable
$(TARGET): $(SOURCEFILE).o
	@echo "Generating the executable" $@
	$(CXX) $(CFLAGS) $(SOURCEFILE).o -o $@
	./$@	
	rm -rf $(TARGET) $(SOURCEFILE).o


$(SOURCEFILE).o:
	@echo "Generating" $@
	$(CXX) $(CFLAGS) -c $(SOURCEFILE).c -o $@

clean:
	@echo "Cleaning temporary files"
	rm -rf $(TARGET) $(SOURCEFILE).o
