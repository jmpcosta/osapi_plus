################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../code/os/os.cpp 

OBJS += \
./code/os/os.o 

CPP_DEPS += \
./code/os/os.d 


# Each subdirectory must supply rules for building sources it contributes
code/os/%.o: ../code/os/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DOS_LINUX -DOSAPI_TRACING -I../code -I../../osapi/code -I/usr/include -I"/osapi/code" -I"/osapi_plus/code" -O3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


