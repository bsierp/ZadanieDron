CPPFLAGS= -c -g -Wall -pedantic -std=c++17 -iquote inc 
OBJ=./obj
TRGDIR=./

${TRGDIR}/test: ${OBJ} ${OBJ}/main.o ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/Prostopadloscian.o ${OBJ}/WekC.o ${OBJ}/MacC.o ${OBJ}/MacOb.o ${OBJ}/Dron.o ${OBJ}/GraniastoslupHex.o
			g++ -o ${TRGDIR}/test ${OBJ}/main.o ${OBJ}/Dr3D_gnuplot_api.o ${OBJ}/Prostopadloscian.o ${OBJ}/WekC.o ${OBJ}/MacC.o ${OBJ}/MacOb.o ${OBJ}/Dron.o ${OBJ}/GraniastoslupHex.o -lpthread
${OBJ}:
		mkdir ${OBJ}
${OBJ}/main.o: src/main.cpp inc/Obiekt3D.hh inc/Wek.hh inc/Mac.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Prostopadloscian.hh inc/Interfejs.hh inc/MacOb.hh inc/GraniastoslupHex.hh
		g++ ${CPPFLAGS} -o ${OBJ}/main.o src/main.cpp
${OBJ}/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp
${OBJ}/MacC.o: inc/Mac.hh src/Mac.cpp src/MacC.cpp inc/Wek.hh                 
		g++ ${CPPFLAGS} -o ${OBJ}/MacC.o src/MacC.cpp
${OBJ}/WekC.o: inc/Wek.hh src/Wek.cpp src/WekC.cpp                            
		g++ ${CPPFLAGS} -o ${OBJ}/WekC.o src/WekC.cpp
${OBJ}/Prostopadloscian.o: inc/Prostopadloscian.hh src/Prostopadloscian.cpp inc/Wek.hh inc/Mac.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Obiekt3D.hh inc/MacOb.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Prostopadloscian.o src/Prostopadloscian.cpp
${OBJ}/Dron.o: inc/Dron.hh src/Dron.cpp inc/Obiekt3D.hh inc/Wek.hh inc/Mac.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Prostopadloscian.hh inc/Interfejs.hh inc/MacOb.hh
		g++ ${CPPFLAGS} -o ${OBJ}/Dron.o src/Dron.cpp
${OBJ}/MacOb.o: inc/MacOb.hh src/MacOb.cpp inc/Mac.hh inc/Wek.hh
		g++ ${CPPFLAGS} -o ${OBJ}/MacOb.o src/MacOb.cpp
${OBJ}/GraniastoslupHex.o: src/GraniastoslupHex.cpp inc/GraniastoslupHex.hh inc/Wek.hh inc/Mac.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Obiekt3D.hh inc/MacOb.hh
		g++ ${CPPFLAGS} -o ${OBJ}/GraniastoslupHex.o src/GraniastoslupHex.cpp
inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
		touch inc/Dr3D_gnuplot_api.hh
inc/Interfejs.hh: inc/Prostopadloscian.hh inc/Obiekt3D.hh inc/MacOb.hh inc/Wek.hh inc/Mac.hh inc/Draw3D_api_interface.hh inc/Dr3D_gnuplot_api.hh
		touch inc/Interfejs.hh
inc/Obiekt3D.hh: inc/MacOb.hh inc/Mac.hh inc/Wek.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh
		touch inc/Obiekt3D.hh
clear:
		rm -f ${TRGDIR}/test ${OBJ}/*