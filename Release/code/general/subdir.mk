################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../code/general/general.cpp \
../code/general/object.cpp 

OBJS += \
./code/general/general.o \
./code/general/object.o 

CPP_DEPS += \
./code/general/general.d \
./code/general/object.d 


# Each subdirectory must supply rules for building sources it contributes
code/general/%.o: ../code/general/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DOS_LINUX -DOSAPI_BASELINE_LIBRARY_C -I/usr/include -I"${OSAPI_PLUS_DIR}/code" -I"${OSAPI_DIR}/code" -O3 -Wall -Wextra -Wconversion -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


