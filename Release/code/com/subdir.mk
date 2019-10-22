################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../code/com/endpoint.cpp \
../code/com/ip.cpp \
../code/com/sharedMemory.cpp \
../code/com/tcp.cpp 

OBJS += \
./code/com/endpoint.o \
./code/com/ip.o \
./code/com/sharedMemory.o \
./code/com/tcp.o 

CPP_DEPS += \
./code/com/endpoint.d \
./code/com/ip.d \
./code/com/sharedMemory.d \
./code/com/tcp.d 


# Each subdirectory must supply rules for building sources it contributes
code/com/%.o: ../code/com/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DOS_LINUX -DOSAPI_BASELINE_LIBRARY_C -I/usr/include -I"${OSAPI_PLUS_DIR}/code" -I"${OSAPI_DIR}/code" -O3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


