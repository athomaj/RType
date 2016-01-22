#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/GameEngine/GameEngine.o \
	${OBJECTDIR}/Gameobject/CrossLoader.o \
	${OBJECTDIR}/Gameobject/GameObject.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/AServer.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/ASocket.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/ActionManager.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/GameEngine.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/GameManager.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/Mutex.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/Room.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/ServerTCP.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/ServerUDP.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/TCPSocket.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/Thread.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadCond.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadPool.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/UDPSocket.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/circular_buffer.o \
	${OBJECTDIR}/Network/ServerRType/ServerRType/main.o \
	${OBJECTDIR}/Parser/Entity/Entity.o \
	${OBJECTDIR}/Parser/Entity/Level.o \
	${OBJECTDIR}/Parser/Entity/Vessel.o \
	${OBJECTDIR}/Parser/Parser.o \
	${OBJECTDIR}/Parser/Scenario.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/ParserTest.o \
	${TESTDIR}/tests/ParserTestRunner.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/GameEngine/GameEngine.o: GameEngine/GameEngine.cpp 
	${MKDIR} -p ${OBJECTDIR}/GameEngine
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GameEngine/GameEngine.o GameEngine/GameEngine.cpp

${OBJECTDIR}/Gameobject/CrossLoader.o: Gameobject/CrossLoader.cpp 
	${MKDIR} -p ${OBJECTDIR}/Gameobject
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Gameobject/CrossLoader.o Gameobject/CrossLoader.cpp

${OBJECTDIR}/Gameobject/GameObject.o: Gameobject/GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/Gameobject
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Gameobject/GameObject.o Gameobject/GameObject.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/AServer.o: Network/ServerRType/ServerRType/AServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/AServer.o Network/ServerRType/ServerRType/AServer.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/ASocket.o: Network/ServerRType/ServerRType/ASocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/ASocket.o Network/ServerRType/ServerRType/ASocket.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/ActionManager.o: Network/ServerRType/ServerRType/ActionManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/ActionManager.o Network/ServerRType/ServerRType/ActionManager.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/GameEngine.o: Network/ServerRType/ServerRType/GameEngine.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/GameEngine.o Network/ServerRType/ServerRType/GameEngine.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/GameManager.o: Network/ServerRType/ServerRType/GameManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/GameManager.o Network/ServerRType/ServerRType/GameManager.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/Mutex.o: Network/ServerRType/ServerRType/Mutex.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/Mutex.o Network/ServerRType/ServerRType/Mutex.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/Room.o: Network/ServerRType/ServerRType/Room.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/Room.o Network/ServerRType/ServerRType/Room.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/ServerTCP.o: Network/ServerRType/ServerRType/ServerTCP.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/ServerTCP.o Network/ServerRType/ServerRType/ServerTCP.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/ServerUDP.o: Network/ServerRType/ServerRType/ServerUDP.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/ServerUDP.o Network/ServerRType/ServerRType/ServerUDP.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/TCPSocket.o: Network/ServerRType/ServerRType/TCPSocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/TCPSocket.o Network/ServerRType/ServerRType/TCPSocket.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/Thread.o: Network/ServerRType/ServerRType/Thread.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/Thread.o Network/ServerRType/ServerRType/Thread.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadCond.o: Network/ServerRType/ServerRType/ThreadCond.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadCond.o Network/ServerRType/ServerRType/ThreadCond.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadPool.o: Network/ServerRType/ServerRType/ThreadPool.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadPool.o Network/ServerRType/ServerRType/ThreadPool.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/UDPSocket.o: Network/ServerRType/ServerRType/UDPSocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/UDPSocket.o Network/ServerRType/ServerRType/UDPSocket.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/circular_buffer.o: Network/ServerRType/ServerRType/circular_buffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/circular_buffer.o Network/ServerRType/ServerRType/circular_buffer.cpp

${OBJECTDIR}/Network/ServerRType/ServerRType/main.o: Network/ServerRType/ServerRType/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/main.o Network/ServerRType/ServerRType/main.cpp

${OBJECTDIR}/Parser/Entity/Entity.o: Parser/Entity/Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}/Parser/Entity
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parser/Entity/Entity.o Parser/Entity/Entity.cpp

${OBJECTDIR}/Parser/Entity/Level.o: Parser/Entity/Level.cpp 
	${MKDIR} -p ${OBJECTDIR}/Parser/Entity
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parser/Entity/Level.o Parser/Entity/Level.cpp

${OBJECTDIR}/Parser/Entity/Vessel.o: Parser/Entity/Vessel.cpp 
	${MKDIR} -p ${OBJECTDIR}/Parser/Entity
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parser/Entity/Vessel.o Parser/Entity/Vessel.cpp

${OBJECTDIR}/Parser/Parser.o: Parser/Parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/Parser
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parser/Parser.o Parser/Parser.cpp

${OBJECTDIR}/Parser/Scenario.o: Parser/Scenario.cpp 
	${MKDIR} -p ${OBJECTDIR}/Parser
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parser/Scenario.o Parser/Scenario.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/ParserTest.o ${TESTDIR}/tests/ParserTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/tests/ParserTest.o: tests/ParserTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ParserTest.o tests/ParserTest.cpp


${TESTDIR}/tests/ParserTestRunner.o: tests/ParserTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++98 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ParserTestRunner.o tests/ParserTestRunner.cpp


${OBJECTDIR}/GameEngine/GameEngine_nomain.o: ${OBJECTDIR}/GameEngine/GameEngine.o GameEngine/GameEngine.cpp 
	${MKDIR} -p ${OBJECTDIR}/GameEngine
	@NMOUTPUT=`${NM} ${OBJECTDIR}/GameEngine/GameEngine.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GameEngine/GameEngine_nomain.o GameEngine/GameEngine.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/GameEngine/GameEngine.o ${OBJECTDIR}/GameEngine/GameEngine_nomain.o;\
	fi

${OBJECTDIR}/Gameobject/CrossLoader_nomain.o: ${OBJECTDIR}/Gameobject/CrossLoader.o Gameobject/CrossLoader.cpp 
	${MKDIR} -p ${OBJECTDIR}/Gameobject
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Gameobject/CrossLoader.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Gameobject/CrossLoader_nomain.o Gameobject/CrossLoader.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Gameobject/CrossLoader.o ${OBJECTDIR}/Gameobject/CrossLoader_nomain.o;\
	fi

${OBJECTDIR}/Gameobject/GameObject_nomain.o: ${OBJECTDIR}/Gameobject/GameObject.o Gameobject/GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/Gameobject
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Gameobject/GameObject.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Gameobject/GameObject_nomain.o Gameobject/GameObject.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Gameobject/GameObject.o ${OBJECTDIR}/Gameobject/GameObject_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/AServer_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/AServer.o Network/ServerRType/ServerRType/AServer.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/AServer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/AServer_nomain.o Network/ServerRType/ServerRType/AServer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/AServer.o ${OBJECTDIR}/Network/ServerRType/ServerRType/AServer_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/ASocket_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/ASocket.o Network/ServerRType/ServerRType/ASocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/ASocket.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/ASocket_nomain.o Network/ServerRType/ServerRType/ASocket.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/ASocket.o ${OBJECTDIR}/Network/ServerRType/ServerRType/ASocket_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/ActionManager_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/ActionManager.o Network/ServerRType/ServerRType/ActionManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/ActionManager.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/ActionManager_nomain.o Network/ServerRType/ServerRType/ActionManager.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/ActionManager.o ${OBJECTDIR}/Network/ServerRType/ServerRType/ActionManager_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/GameEngine_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/GameEngine.o Network/ServerRType/ServerRType/GameEngine.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/GameEngine.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/GameEngine_nomain.o Network/ServerRType/ServerRType/GameEngine.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/GameEngine.o ${OBJECTDIR}/Network/ServerRType/ServerRType/GameEngine_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/GameManager_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/GameManager.o Network/ServerRType/ServerRType/GameManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/GameManager.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/GameManager_nomain.o Network/ServerRType/ServerRType/GameManager.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/GameManager.o ${OBJECTDIR}/Network/ServerRType/ServerRType/GameManager_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/Mutex_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/Mutex.o Network/ServerRType/ServerRType/Mutex.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/Mutex.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/Mutex_nomain.o Network/ServerRType/ServerRType/Mutex.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/Mutex.o ${OBJECTDIR}/Network/ServerRType/ServerRType/Mutex_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/Room_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/Room.o Network/ServerRType/ServerRType/Room.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/Room.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/Room_nomain.o Network/ServerRType/ServerRType/Room.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/Room.o ${OBJECTDIR}/Network/ServerRType/ServerRType/Room_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/ServerTCP_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/ServerTCP.o Network/ServerRType/ServerRType/ServerTCP.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/ServerTCP.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/ServerTCP_nomain.o Network/ServerRType/ServerRType/ServerTCP.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/ServerTCP.o ${OBJECTDIR}/Network/ServerRType/ServerRType/ServerTCP_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/ServerUDP_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/ServerUDP.o Network/ServerRType/ServerRType/ServerUDP.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/ServerUDP.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/ServerUDP_nomain.o Network/ServerRType/ServerRType/ServerUDP.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/ServerUDP.o ${OBJECTDIR}/Network/ServerRType/ServerRType/ServerUDP_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/TCPSocket_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/TCPSocket.o Network/ServerRType/ServerRType/TCPSocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/TCPSocket.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/TCPSocket_nomain.o Network/ServerRType/ServerRType/TCPSocket.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/TCPSocket.o ${OBJECTDIR}/Network/ServerRType/ServerRType/TCPSocket_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/Thread_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/Thread.o Network/ServerRType/ServerRType/Thread.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/Thread.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/Thread_nomain.o Network/ServerRType/ServerRType/Thread.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/Thread.o ${OBJECTDIR}/Network/ServerRType/ServerRType/Thread_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadCond_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadCond.o Network/ServerRType/ServerRType/ThreadCond.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadCond.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadCond_nomain.o Network/ServerRType/ServerRType/ThreadCond.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadCond.o ${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadCond_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadPool_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadPool.o Network/ServerRType/ServerRType/ThreadPool.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadPool.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadPool_nomain.o Network/ServerRType/ServerRType/ThreadPool.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadPool.o ${OBJECTDIR}/Network/ServerRType/ServerRType/ThreadPool_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/UDPSocket_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/UDPSocket.o Network/ServerRType/ServerRType/UDPSocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/UDPSocket.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/UDPSocket_nomain.o Network/ServerRType/ServerRType/UDPSocket.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/UDPSocket.o ${OBJECTDIR}/Network/ServerRType/ServerRType/UDPSocket_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/circular_buffer_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/circular_buffer.o Network/ServerRType/ServerRType/circular_buffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/circular_buffer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/circular_buffer_nomain.o Network/ServerRType/ServerRType/circular_buffer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/circular_buffer.o ${OBJECTDIR}/Network/ServerRType/ServerRType/circular_buffer_nomain.o;\
	fi

${OBJECTDIR}/Network/ServerRType/ServerRType/main_nomain.o: ${OBJECTDIR}/Network/ServerRType/ServerRType/main.o Network/ServerRType/ServerRType/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/Network/ServerRType/ServerRType
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Network/ServerRType/ServerRType/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Network/ServerRType/ServerRType/main_nomain.o Network/ServerRType/ServerRType/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Network/ServerRType/ServerRType/main.o ${OBJECTDIR}/Network/ServerRType/ServerRType/main_nomain.o;\
	fi

${OBJECTDIR}/Parser/Entity/Entity_nomain.o: ${OBJECTDIR}/Parser/Entity/Entity.o Parser/Entity/Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}/Parser/Entity
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Parser/Entity/Entity.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parser/Entity/Entity_nomain.o Parser/Entity/Entity.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Parser/Entity/Entity.o ${OBJECTDIR}/Parser/Entity/Entity_nomain.o;\
	fi

${OBJECTDIR}/Parser/Entity/Level_nomain.o: ${OBJECTDIR}/Parser/Entity/Level.o Parser/Entity/Level.cpp 
	${MKDIR} -p ${OBJECTDIR}/Parser/Entity
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Parser/Entity/Level.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parser/Entity/Level_nomain.o Parser/Entity/Level.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Parser/Entity/Level.o ${OBJECTDIR}/Parser/Entity/Level_nomain.o;\
	fi

${OBJECTDIR}/Parser/Entity/Vessel_nomain.o: ${OBJECTDIR}/Parser/Entity/Vessel.o Parser/Entity/Vessel.cpp 
	${MKDIR} -p ${OBJECTDIR}/Parser/Entity
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Parser/Entity/Vessel.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parser/Entity/Vessel_nomain.o Parser/Entity/Vessel.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Parser/Entity/Vessel.o ${OBJECTDIR}/Parser/Entity/Vessel_nomain.o;\
	fi

${OBJECTDIR}/Parser/Parser_nomain.o: ${OBJECTDIR}/Parser/Parser.o Parser/Parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/Parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Parser/Parser.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parser/Parser_nomain.o Parser/Parser.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Parser/Parser.o ${OBJECTDIR}/Parser/Parser_nomain.o;\
	fi

${OBJECTDIR}/Parser/Scenario_nomain.o: ${OBJECTDIR}/Parser/Scenario.o Parser/Scenario.cpp 
	${MKDIR} -p ${OBJECTDIR}/Parser
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Parser/Scenario.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parser/Scenario_nomain.o Parser/Scenario.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Parser/Scenario.o ${OBJECTDIR}/Parser/Scenario_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -std=c++98 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/server.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
