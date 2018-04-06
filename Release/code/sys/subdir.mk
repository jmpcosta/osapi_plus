################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../code/sys/system.cpp 

OBJS += \
./code/sys/system.o 

CPP_DEPS += \
./code/sys/system.d 


# Each subdirectory must supply rules for building sources it contributes
code/sys/%.o: ../code/sys/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -DOS_LINUX -I/home/joao/workspace/osapi_plus/code -I/home/joao/workspace/osapi/code -O3 -Wall -Wconversion -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


