################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../code/common/buffer.cpp \
../code/common/common.cpp \
../code/common/id.cpp \
../code/common/object.cpp 

OBJS += \
./code/common/buffer.o \
./code/common/common.o \
./code/common/id.o \
./code/common/object.o 

CPP_DEPS += \
./code/common/buffer.d \
./code/common/common.d \
./code/common/id.d \
./code/common/object.d 


# Each subdirectory must supply rules for building sources it contributes
code/common/%.o: ../code/common/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -DOS_LINUX -DOSAPI_TRACING -DOSAPI_BASELINE_LIBRARY_C -I"${OSAPI_PLUS_DIR}/code" -I"${OSAPI_DIR}/code" -I/usr/include -O0 -g3 -p -pg -ftest-coverage -fprofile-arcs -Wall -Wextra -Wconversion -c -fmessage-length=0 -fstack-protector-all -v -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


