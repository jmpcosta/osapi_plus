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
	g++ -std=c++0x -DOS_LINUX -DOSAPI_TRACING -I/home/joao/workspace/osapi_plus/code -I/home/joao/workspace/osapi/code -O0 -g3 -p -pg -ftest-coverage -fprofile-arcs -Wall -Wextra -Wconversion -c -fmessage-length=0 -fstack-protector-all -v -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


