CXX=g++ 
CXXFLAGS=-std=c++11 -g -O2 -march=native -ftree-vectorize -Wall

LDFLAGS=-g
LDLIBS=-lnetcdf_c++4
TESTLDLIBS=-lboost_unit_test_framework

all: antsontable-orig antsontable

test: integratedtest run-initializationtest run-timesteptest  run-randompartitiontest

clean: clean-orig clean-new clean-test

distclean: clean clean-more 

.PHONY: all clean distclean clean-orig clean-new clean-more run-orig run integratedtest run-initializationtest run-timesteptest  run-randompartitiontest help

antsontable-orig.o: antsontable-orig.cc
	${CXX} ${CXXFLAGS} -c -o $@ $^

antsontable-orig: antsontable-orig.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS}

run-orig: antsontable-orig
	./antsontable-orig > run-orig

clean-orig:
	\rm -f antsontable-orig.o

output.o: netcdfoutput.cc netcdfoutput.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

timestep.o: timestep.cc timestep.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

screenoutput.o: screenoutput.cc screenoutput.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

initialization.o: initialization.cc initialization.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

parameters.o: parameters.cc parameters.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

randompartition.o: randompartition.cc randompartition.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

initializationtest.o: initializationtest.cc initialization.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

randompartitiontest.o: randompartitiontest.cc randompartition.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

timesteptest.o: timesteptest.cc timestep.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

antsontable.o: antsontable.cc initialization.h screenoutput.h timestep.h netcdfoutput.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

antsontable: antsontable.o initialization.o randompartition.o screenoutput.o timestep.o netcdfoutput.o parameters.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS}

randompartitiontest: randompartitiontest.o randompartition.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS} ${TESTLDLIBS}

timesteptest: timesteptest.o timestep.o randompartition.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS} ${TESTLDLIBS}

initializationtest: initializationtest.o initialization.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS} ${TESTLDLIBS}

run: antsontable
	./antsontable params.ini > run

run-timesteptest: timesteptest
	./timesteptest

run-initializationtest: initializationtest
	./initializationtest

run-randompartitiontest: randompartitiontest
	./randompartitiontest

clean-new:
	\rm -f antsontable.o initialization.o randompartition.o screenoutput.o timestep.o netcdfoutput.o parameters.o

clean-test:
	\rm -f initializationtest.o timesteptest.o randompartitiontest.o

clean-more:
	\rm -f antsontable antsontable-orig run run-orig initializationtest timesteptest randompartitiontest

integratedtest: run run-orig
	diff -q run run-orig

help:
	@echo Type:
	@echo " 'make'                to compile the antsontable and antsontable-orig applications;"
	@echo " 'make run'            to run antsontable;"
	@echo " 'make run-orig'       to run antsontable-orig;"
	@echo " 'make integratedtest' to compare netcdfoutputs of antsontable and antsontable-orig."
	@echo " 'make clean'          to remove all object files (triggers a full recompile on next 'make')"
	@echo " 'make distclean'      to remove all object files, executables and test outputs"
