################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../code/common/id.cpp 

OBJS += \
./code/common/id.o 

CPP_DEPS += \
./code/common/id.d 


# Each subdirectory must supply rules for building sources it contributes
code/common/%.o: ../code/common/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DOS_LINUX -I/usr/include -I"${OSAPI_PLUS_DIR}/code" -I"${OSAPI_DIR}/code" -O3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


