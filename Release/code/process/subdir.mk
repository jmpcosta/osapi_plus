################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../code/process/process.cpp \
../code/process/signal.cpp 

OBJS += \
./code/process/process.o \
./code/process/signal.o 

CPP_DEPS += \
./code/process/process.d \
./code/process/signal.d 


# Each subdirectory must supply rules for building sources it contributes
code/process/%.o: ../code/process/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DOS_LINUX -I../code -I../../osapi/code -I/usr/include -I"/osapi/code" -I"/osapi_plus/code" -O3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


