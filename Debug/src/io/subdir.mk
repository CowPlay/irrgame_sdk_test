################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/io/CMemoryFileTest.cpp \
../src/io/IFileListTest.cpp \
../src/io/IFileSystemTest.cpp \
../src/io/IReadFileTest.cpp \
../src/io/IWriteFileTest.cpp \
../src/io/IXMLReaderTest.cpp \
../src/io/IXMLWriterTest.cpp 

OBJS += \
./src/io/CMemoryFileTest.o \
./src/io/IFileListTest.o \
./src/io/IFileSystemTest.o \
./src/io/IReadFileTest.o \
./src/io/IWriteFileTest.o \
./src/io/IXMLReaderTest.o \
./src/io/IXMLWriterTest.o 

CPP_DEPS += \
./src/io/CMemoryFileTest.d \
./src/io/IFileListTest.d \
./src/io/IFileSystemTest.d \
./src/io/IReadFileTest.d \
./src/io/IWriteFileTest.d \
./src/io/IXMLReaderTest.d \
./src/io/IXMLWriterTest.d 


# Each subdirectory must supply rules for building sources it contributes
src/io/%.o: ../src/io/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Users/litirvi/workspace/irrgame_sdk/include -I/Users/litirvi/workspace/irrgame_sdk_test/src -I/Users/litirvi/Downloads/boost_1_50_0 -I/Users/litirvi/workspace/irrgame_sdk_test/cute -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


