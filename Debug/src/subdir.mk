################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/RunAllTests.cpp \
../src/main.cpp 

OBJS += \
./src/RunAllTests.o \
./src/main.o 

CPP_DEPS += \
./src/RunAllTests.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Users/litirvi/workspace/irrgame_sdk/include -I/Users/litirvi/workspace/irrgame_sdk_test/src -I/Users/litirvi/Downloads/boost_1_50_0 -I/Users/litirvi/workspace/irrgame_sdk_test/cute -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


