CC=g++
FLAGS=-std=c++20 -w
TARGET=AnalysisData
OBJECTS=AnalysisData.o CustomFunctions.o

${TARGET}:${OBJECTS}
	@echo "Linking..."
	${CC} ${FLAGS} ${OBJECTS} -o ${TARGET}
	

AnalysisData.o : AnalysisData.cxx 
	${CC} ${FLAGS} -c AnalysisData.cxx

CustomFunctions.o : CustomFunctions.cxx
	${CC} ${FLAGS} -c CustomFunctions.cxx

.PHONY: clean
clean:
	@echo "Cleaning files..."
	rm -f $(OBJECTS) $(TARGET)