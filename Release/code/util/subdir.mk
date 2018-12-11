################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../code/util/util.cpp 

OBJS += \
./code/util/util.o 

CPP_DEPS += \
./code/util/util.d 


# Each subdirectory must supply rules for building sources it contributes
code/util/%.o: ../code/util/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DOS_LINUX -DOSAPI_TRACING -I../code -I../../osapi/code -I/usr/include -I"/osapi/code" -I"/osapi_plus/code" -O3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


