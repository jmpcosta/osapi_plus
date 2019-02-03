################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../code/process/common.cpp \
../code/process/current.cpp \
../code/process/factory.cpp \
../code/process/plan.cpp \
../code/process/runner.cpp \
../code/process/signal.cpp 

OBJS += \
./code/process/common.o \
./code/process/current.o \
./code/process/factory.o \
./code/process/plan.o \
./code/process/runner.o \
./code/process/signal.o 

CPP_DEPS += \
./code/process/common.d \
./code/process/current.d \
./code/process/factory.d \
./code/process/plan.d \
./code/process/runner.d \
./code/process/signal.d 


# Each subdirectory must supply rules for building sources it contributes
code/process/%.o: ../code/process/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DOS_LINUX -I/usr/include -I"${OSAPI_PLUS_DIR}/code" -I"${OSAPI_DIR}/code" -O3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


