################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../code/process/current.cpp \
../code/process/factory.cpp \
../code/process/library.cpp \
../code/process/plan.cpp \
../code/process/plan_signal.cpp \
../code/process/runner.cpp \
../code/process/signal.cpp \
../code/process/status.cpp 

OBJS += \
./code/process/current.o \
./code/process/factory.o \
./code/process/library.o \
./code/process/plan.o \
./code/process/plan_signal.o \
./code/process/runner.o \
./code/process/signal.o \
./code/process/status.o 

CPP_DEPS += \
./code/process/current.d \
./code/process/factory.d \
./code/process/library.d \
./code/process/plan.d \
./code/process/plan_signal.d \
./code/process/runner.d \
./code/process/signal.d \
./code/process/status.d 


# Each subdirectory must supply rules for building sources it contributes
code/process/%.o: ../code/process/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DOS_LINUX -DOSAPI_BASELINE_LIBRARY_C -I/usr/include -I"${OSAPI_PLUS_DIR}/code" -I"${OSAPI_DIR}/code" -O3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


